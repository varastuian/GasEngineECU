#include "gimbaltcp.h"
#include "QGCApplication.h"
#include "LinkManager.h"
// #include "TCPLink.h"

#define AP_MOUNT_VIEWPRO_HEADER1       0x55     // first header byte
#define AP_MOUNT_VIEWPRO_HEADER2       0xAA     // second header byte
#define AP_MOUNT_VIEWPRO_HEADER3       0xDC     // third header byte
#define AP_MOUNT_VIEWPRO_PACKETLEN_MIN 5        // min number of bytes in a packet (3 header bytes, length, crc)
#define AP_MOUNT_VIEWPRO_DATALEN_MAX   (AP_MOUNT_VIEWPRO_PACKETLEN_MAX-AP_MOUNT_VIEWPRO_PACKETLEN_MIN) // max bytes for data portion of packet
#define AP_MOUNT_VIEWPRO_HEALTH_TIMEOUT_MS 1000 // state will become unhealthy if no attitude is received within this timeout
#define AP_MOUNT_VIEWPRO_UPDATE_INTERVAL_MS 100 // resend angle or rate targets to gimbal at this interval
#define AP_MOUNT_VIEWPRO_ZOOM_SPEED     0x07    // hard-coded zoom speed (fast)
#define AP_MOUNT_VIEWPRO_ZOOM_MAX       10      // hard-coded absolute zoom times max
#define AP_MOUNT_VIEWPRO_DEG_TO_OUTPUT  (65536.0 / 360.0)   // scalar to convert degrees to the viewpro angle scaling
#define AP_MOUNT_VIEWPRO_OUTPUT_TO_DEG  (360.0 / 65536.0)   // scalar to convert viewpro angle scaling to degrees
#define AP_MOUNT_VIEWPRO_DEBUG 0
#define AP_MOUNT_VIEWPRO_PACKETLEN_MAX  63  // maximum number of bytes in a packet sent to or received from the gimbal


GimbalTcp::GimbalTcp(QObject *parent)
    : QObject{parent}

{

}
// SharedLinkInterfacePtr getTcpLink(const QList<SharedLinkInterfacePtr>& sharedLinks) {
//     for (const auto& link : sharedLinks) {
//         if (qobject_cast<TCPLink*>(link) != nullptr) {
//             return link;
//         }
//     }
//     return nullptr;
// }

void GimbalTcp::init(){

    for (auto templink : qgcApp()->toolbox()->linkManager()->links()) {
        if (templink->linkConfiguration()->type() == LinkConfiguration::TypeTcp) {
            link = templink.get();
            qDebug() << link;
            auto linkConfiguration = link->linkConfiguration();
            if (link->isConnected() && linkConfiguration && !linkConfiguration->isHighLatency()) {
                sendTargetAngles(1, 1);
                break;
            }

        }
    }

}

bool GimbalTcp::sendTargetAngles(float pitch_rad, float yaw_rad)
{

    // scale pitch and yaw to values gimbal understands
    const uint16_t pitch_angle_output = -qRadiansToDegrees(pitch_rad) * AP_MOUNT_VIEWPRO_DEG_TO_OUTPUT;
    const uint16_t yaw_angle_output = qRadiansToDegrees(yaw_rad) * AP_MOUNT_VIEWPRO_DEG_TO_OUTPUT;

    // fill in packet
    // const A1Packet a1_packet {
    //     .content = {
    //         .frame_id =  FrameId::A1,
    //         .servo_status =  ServoStatus::MANUAL_ABSOLUTE_ANGLE_MODE,
    //         .yaw_be =  yaw_angle_output,
    //         .pitch_be =  pitch_angle_output
    //     }
    // };
    A1Packet a1_packet = {};
    a1_packet.content.frame_id = FrameId::A1;
    a1_packet.content.servo_status = ServoStatus::MANUAL_ABSOLUTE_ANGLE_MODE;
    a1_packet.content.yaw_be = yaw_angle_output;
    a1_packet.content.pitch_be = pitch_angle_output;


    // send targets to gimbal
    return sendPacket(a1_packet.bytes, sizeof(a1_packet.bytes));
}

uint8_t GimbalTcp::calcCrc(const uint8_t *buf, uint8_t len) const
{
    uint8_t res = 0;
    for (uint8_t i=0; i<len; i++) {
        res = (res ^ buf[i]) & 0xFF;
    }
    return res;
}
bool GimbalTcp::sendPacket(const uint8_t* databuff, uint8_t databuff_len)
{
    // calculate and sanity check packet size
    const uint16_t packet_size = AP_MOUNT_VIEWPRO_PACKETLEN_MIN + databuff_len;

    // uint8_t send_buff[packet_size];
    std::vector<uint8_t> send_buff(packet_size);

    uint8_t send_buff_ofs = 0;

    // packet header
    send_buff[send_buff_ofs++] = AP_MOUNT_VIEWPRO_HEADER1;
    send_buff[send_buff_ofs++] = AP_MOUNT_VIEWPRO_HEADER2;
    send_buff[send_buff_ofs++] = AP_MOUNT_VIEWPRO_HEADER3;

    // length and frame counter. length is databuffer length + 2 (1 for length, 1 for crc)
    send_buff[send_buff_ofs++] =  ((((_last_frame_counter + 1) & 0x03) << 6) | (databuff_len + 2 & 0x3F));

    // data
    if (databuff_len != 0) {
        memcpy(&send_buff[send_buff_ofs], databuff, databuff_len);
        send_buff_ofs += databuff_len;
    }

    // crc
    const uint8_t crc = calcCrc(&send_buff[3], send_buff_ofs-3);
    send_buff[send_buff_ofs++] = crc;
    QString hexString;
    for (uint8_t byte : send_buff) {
        hexString += QString::number(byte, 16).toUpper().rightJustified(2, '0');
    }

    qDebug() << hexString;

    auto linkConfiguration = link->linkConfiguration();
    if (link->isConnected() && linkConfiguration && !linkConfiguration->isHighLatency()) {
        link->writeBytesThreadSafe(reinterpret_cast<const char*>(send_buff.data()), send_buff_ofs);
    }


    return true;
}
