#include "ECUController.h"
#include "LinkManager.h"
#include "QGCApplication.h"
#include <QDebug>
#include <QtQml/QQmlEngine>
#include <qendian.h>

uint16_t ECUController::frameSequence = 0;

ECUController::ECUController(QGCApplication* app, QGCToolbox* toolbox)
    : QGCTool(app, toolbox)
    , _linkMgr(nullptr)
    , _multiVehicleManager(nullptr)
    , link(nullptr)
    , linkConfiguration(nullptr)
    , m_timer(new QTimer(this)) {
    connect(m_timer, &QTimer::timeout, this, &ECUController::onTimeout);
    m_timer->setInterval(400);
    connect(&_simulationTimer, &QTimer::timeout, this, &ECUController::updateSimulationData);
    // _simulationTimer.start(1000);
    // createPacket("qr");

}
void ECUController::updateSimulationData() {

    QByteArray packet = QByteArray::fromHex("F1 1F 00 00 00 7D 00 00 22 06 07 66 0F 66 0F CB 07 CD 00 03 48 93 93 00 00 BF 03 BF 03 0A 03 3B 07 C8 00 77 00 93 00 93 00 00 00 64 00 64 00 62 00 8F 00 00 00 64 00 66 00 8D 00 3A 00 3A 00 28 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 58 02 00 00 12 00 00 00 00 00 01 00 0B 4E FE 4C FC 07 02 06 FE 07 F2 06 64 00 64 00 00 00 00 00 00 00 00 00 56 10 56 10 00 80 97 43 51 EF F2 2F");
    parsePacket(packet);

    // Message.statusData.speed += 5;
    // if (Message.statusData.speed > 120) {
    //     Message.statusData.speed = 0; // Reset speed if it exceeds the limit
    // }

    // // Adjust cylinder temperatures with random changes
    // Message.statusData.cylinder1Temp =Message.statusData.cylinder1Temp + getRandomChange(5.0f);

    // Message.statusData.cylinder2Temp = Message.statusData.cylinder2Temp + getRandomChange(5.0f);

    // emit dataChanged();
}

void ECUController::setToolbox(QGCToolbox *toolbox)
{
    QGCTool::setToolbox(toolbox);
    _linkMgr =               _toolbox->linkManager();
    // _multiVehicleManager =   _toolbox->multiVehicleManager();
    qmlRegisterSingletonInstance<ECUController>("Vahid.Utility", 1, 0, "ECUController", this);

}

void ECUController::init(){

    for (auto templink : qgcApp()->toolbox()->linkManager()->links()) {
        if (templink->linkConfiguration()->type() == LinkConfiguration::TypeSerial) {
            link = templink.get();
            linkConfiguration = link->linkConfiguration().get();
            if (link->isConnected() && linkConfiguration && !linkConfiguration->isHighLatency()) {
                m_timer->start();
                break;
            }

        }
    }
}

void ECUController::receiveBytes(LinkInterface* link, QByteArray b)
{
    SharedLinkInterfacePtr linkPtr = _linkMgr->sharedLinkInterfacePointerForLink(link);
    if (!linkPtr) {
        qDebug() << "receiveBytes: link gone!" << b.size() << " bytes arrived too late";
        return;
    }


    bTotal.append(b);

    const int packetLength = 127;

    while (true) {
        int startIndex = bTotal.indexOf(QByteArray(reinterpret_cast<const char*>(&Message.header), sizeof(Message.header)));

        if (startIndex == -1) {
            break;
        }

        // Ensure we have enough bytes for a complete packet
        if (bTotal.size() < startIndex + packetLength) {
            break;
        }

        int endIndex = startIndex + packetLength - sizeof(Message.tail);
        qDebug() << bTotal.mid(endIndex, sizeof(Message.tail)) << Message.tail << sizeof(Message.tail) ;
        if (bTotal.mid(endIndex, sizeof(Message.tail)) != QByteArray(reinterpret_cast<const char*>(&Message.tail), sizeof(Message.tail))) {
            // Invalid packet; discard up to the start marker and continue
            bTotal.remove(0, startIndex + packetLength);
            continue;
        }


        QByteArray packet = bTotal.mid(startIndex, packetLength);

        parsePacket(packet);

        bTotal.remove(0, startIndex + packetLength);
    }
}


bool ECUController::parsePacket(const QByteArray &packet)
{
    if (packet.size() < 12) {
        qDebug() <<  "Message is too short!";
        return false;
    }
    // Check headers
    if ((static_cast<uint8_t>(packet[1]) << 8 | static_cast<uint8_t>(packet[0])) != Message.header) {
        qDebug() << "Invalid message header!";
        return false;
    }

    Message.length = (static_cast<uint32_t>(packet[2]) << 24) |
                     (static_cast<uint32_t>(packet[3]) << 16) |
                     (static_cast<uint32_t>(packet[4]) << 8) |
                     (static_cast<uint32_t>(packet[5]) << 0);



    Message.frameNumber = (static_cast<uint16_t>(packet[6])<< 8) |
                          (static_cast<uint16_t>(packet[7])<< 0 );

    Message.commandWord = static_cast<uint8_t>(packet[8]);

    // Extract status data
    //LE
    if (Message.length > 12) {

        Message.statusData.speed = static_cast<uint8_t>(packet[16]) << 8 | static_cast<uint8_t>(packet[15]) ;
        Message.statusData.cylinder1Temp = fahrenheitToCelsius(static_cast<uint8_t>(packet[96]) << 8 | static_cast<uint8_t>(packet[95]) );
        Message.statusData.cylinder2Temp = fahrenheitToCelsius(static_cast<uint8_t>(packet[102]) << 8| static_cast<uint8_t>(packet[101]) );
        Message.statusData.runTime = (static_cast<uint8_t>(packet[119]) | (static_cast<uint8_t>(packet[120]) << 8) |(static_cast<uint8_t>(packet[121]) << 16) | (static_cast<uint8_t>(packet[122]) << 24));
        Message.statusData.batteryVoltage = (static_cast<uint8_t>(packet[35]) | (static_cast<uint8_t>(packet[36]) << 8)) / 10.0f;


        // Message.statusData.fuelConsumed = (static_cast<uint8_t>(packet[92]) | (static_cast<uint8_t>(packet[93]) << 8) |(static_cast<uint8_t>(packet[94]) << 16) | (static_cast<uint8_t>(packet[95]) << 24)) / 1e9;
        // Message.statusData.realTimeFuel = (uint8_t(packet[108]) | (uint8_t(packet[109]) << 8)) / 10.0;
        // Message.statusData.atmosphericTemp = (uint8_t(packet[30]) | (uint8_t(packet[31]) << 8)) / 10.0;
        // Message.statusData.atmosphericPressure = (uint8_t(packet[26]) | (uint8_t(packet[27]) << 8)) / 10.0;


        Message.statusData.engineStarted = uint8_t(packet[89]) == 0x01;
        Message.statusData.engineStandby = (uint8_t(packet[20]))& 0x01;
        Message.statusData.driveStartup = (uint8_t(packet[20]))& 0x02;
        Message.statusData.startCompensation = (uint8_t(packet[20]))& 0x04;
        Message.statusData.warmUp = (uint8_t(packet[20]))& 0x08;
        Message.statusData.accelerating = (uint8_t(packet[20]))& 0x10;
        Message.statusData.decelerating = (uint8_t(packet[20]))& 0x20;
        Message.statusData.oilPumpWorking = (uint8_t(packet[20]))& 0x40;
        Message.statusData.flameoutReady = (uint8_t(packet[20]))& 0x80;

    } else {
        qDebug() << "Invalid status data length!";
        return false;
    }

    // Extract checksum
    Message.checksum =  static_cast<uint16_t>(static_cast<uint8_t>(packet[Message.length - 2]) << 8) |
                        static_cast<uint16_t>(static_cast<uint8_t>(packet[Message.length - 1]));

    // Check tail
    if ((static_cast<uint8_t>(packet[Message.length +1]) << 8 | static_cast<uint8_t>(packet[Message.length ])) != Message.tail) {
        qDebug() << "Invalid message tail!";
        return false;
    }

    // Validate CRC
    QByteArray crcData = packet.mid(2, Message.length - (sizeof(Message.header)+ sizeof(Message.tail)));
    uint16_t calculatedCRC = calculateCRC(crcData);
    if (calculatedCRC != Message.checksum) {
        qDebug() <<  QString("CRC mismatch! Calculated: 0x%1, Received: 0x%2")
        .arg(calculatedCRC, 4, 16, QChar('0'))
            .arg(Message.checksum, 4, 16, QChar('0'));
        return false;
    }
    emit dataChanged();
    return true;
}


uint16_t ECUController::calculateCRC(const QByteArray &data) {
    static const uint16_t crcTable[256] = {
        0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
        0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
        0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
        0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
        0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
        0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
        0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
        0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
        0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
        0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
        0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
        0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
        0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
        0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
        0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
        0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
        0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
        0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
        0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
        0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
        0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
        0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
        0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
        0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
        0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
        0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
        0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
        0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
        0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
        0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
        0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
        0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
    };

    uint16_t crc = 0xFFFF;
    for (char byte : data) {
        uint8_t high = (crc >> 8) & 0xFF; // Get high byte
        crc = (crc << 8) ^ crcTable[high ^ static_cast<uint8_t>(byte)];
    }
    return crc;
}


QByteArray ECUController::createPacket(const QByteArray &command) {

    __message packet;
    packet.length = sizeof(packet.header) + sizeof(packet.length)+sizeof(packet.frameNumber) + sizeof(packet.commandWord) + command.size() + sizeof(packet.tail);

    uint32_t lengthBE = (packet.length << 24) | ((packet.length << 8) & 0xFF0000) | ((packet.length >> 8) & 0xFF00) | (packet.length >> 24);

    // packet.frameNumber = ++frameSequence;
    packet.frameNumber = 0;
    packet.commandWord = 0x22;

    QByteArray packetBytes;
    packetBytes.append(reinterpret_cast<const char*>(&packet.header)        , sizeof(packet.header));

    packetBytes.append(reinterpret_cast<const char*>(&lengthBE)             , sizeof(lengthBE));
    packetBytes.append(reinterpret_cast<const char*>(&packet.frameNumber)   , sizeof(packet.frameNumber));
    packetBytes.append(packet.commandWord);
    packetBytes.append(command);

    packet.checksum = calculateCRC(packetBytes.mid(2));
    uint16_t checksumBE = qToBigEndian(packet.checksum);
    packetBytes.append(reinterpret_cast<const char*>(&checksumBE)           , sizeof(checksumBE));

    packetBytes.append(reinterpret_cast<const char*>(&packet.tail)          , sizeof(packet.header));

    return packetBytes;
}


void ECUController::sendCommand(const QByteArray &command) {
    SharedLinkInterfacePtr linkPtr = _linkMgr->sharedLinkInterfacePointerForLink(link);
    auto linkConfiguration = linkPtr.get()->linkConfiguration();

    if (!linkPtr) {
        return;
    }

    if (linkPtr.get()->isConnected() && linkConfiguration && !linkConfiguration->isHighLatency()) {
        linkPtr.get()->writeBytesThreadSafe(command.constData(), command.size());
        qDebug() << "Sending Packet:" << command.toHex(' ');

    }

}


float ECUController::fahrenheitToCelsius(float fahrenheit) {
    float fahrenheitd = static_cast<float>(fahrenheit) / 10.0f;
    return (fahrenheitd - 32.0f) * 5.0f / 9.0f;;
}


QVariantList ECUController::vehicleComponents() {
    QList<ECUController::VehicleComponent> components;
    QVariantList list;

    components.append({"Speed",QVariant::fromValue(Message.statusData.speed),"rpm"});
    components.append({ "Run Time", QVariant::fromValue(Message.statusData.runTime), "sec" });

    components.append({ "Cylinder1 Temp", QVariant::fromValue(Message.statusData.cylinder1Temp), "°C" });
    components.append({ "Cylinder2 Temp", QVariant::fromValue(Message.statusData.cylinder2Temp), "°C" });

    // components.append({ "Fuel Consumed", QVariant::fromValue(Message.statusData.fuelConsumed), "L" });
    // components.append({ "Real-Time Fuel", QVariant::fromValue(Message.statusData.realTimeFuel), "L/h" });

    // components.append({ "Atmospheric Temp", QVariant::fromValue(Message.statusData.atmosphericTemp), "°C" });
    // components.append({ "Atmospheric Pressure", QVariant::fromValue(Message.statusData.atmosphericPressure), "hPa" });

    components.append({ "Battery Voltage", QVariant::fromValue(Message.statusData.batteryVoltage), "V" });
    for (const VehicleComponent& component : components) {
        QVariantMap map;
        map["name"] = component.name;
        map["value"] = component.value;
        map["unit"] = component.unit;
        list.append(map);


    }

    // emit dataChanged();
    return list;



}


QVariantList ECUController::vehicleCkeck() {
    QList<ECUController::VehicleComponent> components;
    QVariantList list;

    components.append({ "Engine Started", QVariant::fromValue(Message.statusData.engineStarted), "" });
    components.append({ "Engine Standby", QVariant::fromValue(Message.statusData.engineStandby), "" });
    components.append({ "Drive Startup", QVariant::fromValue(Message.statusData.driveStartup), "" });
    components.append({ "Start Compensation", QVariant::fromValue(Message.statusData.startCompensation), "" });
    components.append({ "Warm Up", QVariant::fromValue(Message.statusData.warmUp), "" });
    components.append({ "Accelerating", QVariant::fromValue(Message.statusData.accelerating), "" });
    components.append({ "Decelerating", QVariant::fromValue(Message.statusData.decelerating), "" });
    components.append({ "Oil Pump Working", QVariant::fromValue(Message.statusData.oilPumpWorking), "" });
    components.append({ "Flameout Ready", QVariant::fromValue(Message.statusData.flameoutReady), "" });


    for (const VehicleComponent& component : components) {
        QVariantMap map;
        map["name"] = component.name;
        map["value"] = component.value;
        map["unit"] = component.unit;
        list.append(map);


    }


    // emit dataChanged();
    return list;


}


void ECUController::onTimeout() {
    sendCommand(createPacket("f"));     // readEngineStatus;
}


void ECUController::startEngine() {
    sendCommand(createPacket("qqd"));
}


void ECUController::stopEngine() {
    sendCommand(createPacket("flm"));
}


void ECUController::flameout() {
    sendCommand(createPacket("qqx"));
}

