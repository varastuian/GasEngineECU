#ifndef ECUCONTROLLER_H
#define ECUCONTROLLER_H

#include "LinkInterface.h"
#include "QGCToolbox.h"

#include <QtCore/QString>
#include <QtCore/QByteArray>
#include <QtCore/QLoggingCategory>
#include <QTimer>

class LinkManager;
class MultiVehicleManager;
class QGCApplication;

struct __message {
    uint16_t header = (0x1F << 8) | 0xF1;

    uint32_t length;
    uint16_t frameNumber;
    uint8_t commandWord;
    struct StatusData {
        uint32_t runTime=0;
        float speed = 0;
        uint32_t fuelConsumed=0;
        uint16_t realTimeFuel=0;
        float cylinder1Temp =0;
        float cylinder2Temp = 0;
        uint16_t atmosphericTemp=0;
        uint16_t atmosphericPressure=0;
        uint16_t batteryVoltage=0;
        bool engineStarted=false;
        bool engineStandby=false;
        bool driveStartup=false;
        bool startCompensation=false;
        bool warmUp=false;
        bool accelerating=false;
        bool decelerating=false;
        bool oilPumpWorking=false;
        bool flameoutReady=false;
    } statusData;
    uint16_t checksum=0;
    uint16_t tail = (0x2F << 8) | 0xF2;
};


class ECUController : public QGCTool {
    Q_OBJECT
public:
    ECUController(QGCApplication* app, QGCToolbox* toolbox);


    Q_PROPERTY(QVariantList vehicleComponents   READ vehicleComponents  NOTIFY dataChanged)
    Q_PROPERTY(QVariantList vehicleCkeck        READ vehicleCkeck       NOTIFY dataChanged)

    struct VehicleComponent {
        QString     name;
        QVariant    value;
        QString     unit;
    };


    virtual void setToolbox(QGCToolbox *toolbox);

    Q_INVOKABLE void init ();
    Q_INVOKABLE void startEngine();
    Q_INVOKABLE void stopEngine();
    Q_INVOKABLE void flameout();


signals:
    void messageReceived(LinkInterface* link, __message message);
    void dataChanged(void);

public slots:
    void receiveBytes(LinkInterface* link, QByteArray b);
    void onTimeout();

private:
    void sendCommand(const QByteArray &command);
    QByteArray createPacket(const QByteArray &data);
    uint16_t calculateCRC(const QByteArray &data);
    bool parsePacket(const QByteArray &packet);


    QTimer *m_timer;

    LinkManager*            _linkMgr;
    MultiVehicleManager*    _multiVehicleManager;
    LinkInterface*          link;
    LinkConfiguration*      linkConfiguration;

    static uint16_t frameSequence;
    __message Message;
    QByteArray bTotal;
    QVariantList vehicleComponents();
    QVariantList vehicleCkeck();
    float fahrenheitToCelsius(float fahrenheit);
    QTimer _simulationTimer;
    void updateSimulationData();

};

#endif // ECUCONTROLLER_H
