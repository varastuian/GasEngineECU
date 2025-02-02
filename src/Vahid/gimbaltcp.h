#ifndef GIMBALTCP_H
#define GIMBALTCP_H

#include "LinkInterface.h"
#include <QObject>

class GimbalTcp : public QObject
{
    Q_OBJECT
public:
    explicit GimbalTcp(QObject *parent = nullptr);
    Q_INVOKABLE void     init ();

signals:
protected:
    bool sendPacket(const uint8_t *databuff, uint8_t databuff_len);
    bool sendTargetAngles(float pitch_rad, float yaw_rad);
    uint8_t calcCrc(const uint8_t *buf, uint8_t len) const;

private:
    uint8_t _last_frame_counter;                    // frame counter sent in last message

    // packet frame ids
    enum class FrameId : uint8_t {
        HANDSHAKE = 0x00,       // handshake sent to gimbal
        U = 0x01,               // communication configuration control (this packet is sent to gimbal)
        V = 0x02,               // communication configuration status (this is the reply to U)
        HEARTBEAT = 0x10,       // heartbeat received from gimbal
        A1 = 0x1A,              // target angles (sent)
        C1 = 0x1C,              // camera controls commonly used (sent)
        E1 = 0x1E,              // tracking controls commonly used (sent)
        C2 = 0x2C,              // camera controls infrequently used (sent)
        E2 = 0x2E,              // tracking controls infrequently used (sent)
        T1_F1_B1_D1 = 0x40,     // actual roll, pitch, yaw angles (received)
        M_AHRS = 0xB1,          // vehicle attitude and position (sent)
    };

    // U communication configuration control commands
    enum class CommConfigCmd : uint8_t {
        QUERY_FIRMWARE_VER = 0xD0,
        QUERY_MODEL = 0xE4,
    };

    // A1 servo status enum (used in A1, B1 packets)
    enum class ServoStatus : uint8_t {
        MANUAL_SPEED_MODE = 0x01,
        FOLLOW_YAW = 0x03,
        MANUAL_ABSOLUTE_ANGLE_MODE = 0x0B,
        FOLLOW_YAW_DISABLE = 0x0A,
    };

    // C1 image sensor choice
    enum class ImageSensor : uint8_t {
        NO_ACTION = 0x00,   // no image sensor is affected
        EO1 = 0x01,         // electro-optical, aka rgb
        IR = 0x02,          // infrared, aka thermal
        EO1_IR_PIP = 0x03,  // rgb is main, IR is picture-in-picture
        IR_EO1_PIP = 0x04,  // thermal is main, rgb is picture-in-picture
        FUSION = 0x05,      // rgb and thermal are fused
        IR1_13MM = 0x06,    // only valid for 1352 module
        IR2_52MM = 0x07,    // only valid for 1352 module
    };

    // C1 camera commands
    enum class CameraCommand : uint8_t {
        NO_ACTION = 0x00,
        STOP_FOCUS_AND_ZOOM = 0x01,
        ZOOM_OUT = 0x08,
        ZOOM_IN = 0x09,
        FOCUS_PLUS = 0x0A,
        FOCUS_MINUS = 0x0B,
        TAKE_PICTURE = 0x13,
        START_RECORD = 0x14,
        STOP_RECORD = 0x15,
        AUTO_FOCUS = 0x19,
        MANUAL_FOCUS = 0x1A
    };

    // C1 rangefinder commands
    enum class LRFCommand : uint8_t {
        NO_ACTION = 0x00,
        SINGLE_RANGING = 0x01,
        CONTINUOUS_RANGING_START = 0x02,
        LPCL_CONTINUOUS_RANGING_START = 0x03,
        STOP_RANGING = 0x05
    };

    // C2 camera commands
    enum class CameraCommand2 : uint8_t {
        SET_EO_ZOOM = 0x53
    };

    // D1 recording status (received from gimbal)
    enum class RecordingStatus : uint8_t {
        RECORDING_STOPPED = 0x00,
        RECORDING = 0x01,
        PICTURE_MODE = 0x02
    };

    // E1 tracking commands
    enum class TrackingCommand : uint8_t {
        STOP = 0x01,
        START = 0x03,
        SET_POINT = 0x0A,
        SET_RECT_TOPLEFT = 0x0B,
        SET_RECT_BOTTOMRIGHT = 0x0C,
    };

    // E1 tracking source (e.g. which camera)
    enum class TrackingSource : uint8_t {
        EO1 = 0x01,         // electro-optical, aka rgb
        IR = 0x02,          // infrared, aka thermal
        EO2 = 0x03,         // electro-optical, aka rgb
    };

    // E2 tracking commands2
    enum class TrackingCommand2 : uint8_t {
        SET_POINT = 0x0A,
        SET_RECT_TOPLEFT = 0x0B,
        SET_RECT_BOTTOMRIGHT = 0x0C,
    };

    // F1 tracking status (received from gimbal)
    enum class TrackingStatus : uint8_t {
        STOPPED = 0x00,     // not tracking
        SEARCHING = 0x01,   // searching
        TRACKING = 0x02,    // locked onto a target
        LOST = 0x03,        // lost target
    };

    // parsing state
    enum class ParseState : uint8_t {
        WAITING_FOR_HEADER1,
        WAITING_FOR_HEADER2,
        WAITING_FOR_HEADER3,
        WAITING_FOR_LENGTH,
        WAITING_FOR_FRAMEID,
        WAITING_FOR_DATA,
        WAITING_FOR_CRC
    };

    // packet formats
    union HandshakePacket {
        struct {
            FrameId frame_id;           // always 0x00
            uint8_t unused;             // always 0x00
        } content;
        uint8_t bytes[sizeof(content)];
    };

    // U packed used to send communication configuration control commands
    // gimbal replies with V packet
    union UPacket {
        struct {
            FrameId frame_id;           // always 0x01
            CommConfigCmd control_cmd;  // see CommConfigCmd enum above
            uint8_t params[9];          // parameters (unused)
        } content;
        uint8_t bytes[sizeof(content)];
    };

    // A1 used to send target angles and rates
    union A1Packet {
        struct {
            FrameId frame_id;           // always 0x1A
            ServoStatus servo_status;   // see ServoStatus enum above
            uint16_t yaw_be;              // target yaw angle or rate msb
            uint16_t pitch_be;            // target pitch angle or rate msb
            uint8_t unused[4];          // unused
        } content;
        uint8_t bytes[sizeof(content)];
    };

    // C1 used to send camera commands (commonly used)
    union C1Packet {
        struct PACKED {
            FrameId frame_id;           // always 0x1C
            uint16_t sensor_zoom_cmd_be;
        } content;
        uint8_t bytes[sizeof(content)];
    };

    // C2 used to send camera commands (less commonly used)
    union C2Packet {
        struct {
            FrameId frame_id;           // always 0x2C
            CameraCommand2 cmd;         // see CameraCommand2 enum above
            uint16_t value_be;            // value
        } content;
        uint8_t bytes[sizeof(content)];
    };

    // E1 used to send tracking commands
    union E1Packet {
        struct {
            FrameId frame_id;           // always 0x1E
            TrackingSource source : 3;  // see TrackingSource enum above
            uint8_t unused : 5;         // param1 (unused)
            TrackingCommand cmd;        // see TrackingCommand enum above
            uint8_t param2;             // param2
        } content;
        uint8_t bytes[sizeof(content)];
    };

    // E2 used to send tracking commands2
    union E2Packet {
        struct {
            FrameId frame_id;           // always 0x2E
            TrackingCommand2 cmd;       // see TrackingCommand2 enum above
            uint16_t param1_be;
            uint16_t param2_be;
        } content;
        uint8_t bytes[sizeof(content)];
    };


    LinkInterface* link;
};

#endif // GIMBALTCP_H
