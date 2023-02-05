#include <iostream>
#include <string>

#include "EcpriPacket.h"

using namespace std;


void EcpriPacket::parse(unsigned int id, const string& packet) {
    EthernetPacket::parse(id, packet);
    concat_indicator_ = "0";
    message_type_ = packet.substr(46, 2);
    payload_size_ = packet.substr(48, 4);
    protocol_version_ = "1";
    rtc_id_ = packet.substr(52, 4);
    sequence_id_ = packet.substr(56, 4);
}

string EcpriPacket::to_string() const {
    return string(
        "Packet # " + std::to_string(id_) + ":\n"
        + packet_ + "\n"
        + "CRC: " + crc_ + "\n"
        + "Concatenation Indicator: " + concat_indicator_ + "\n"
        + "Destination Address: " + destination_address_ + "\n"
        + "Message Type: " + message_type_ + "\n"
        + "Payload Size: " + payload_size_ + "\n"
        + "Protocol Version: " + protocol_version_ + "\n"
        + "RTC ID: " + rtc_id_ + "\n"
        + "Sequence ID: " + sequence_id_ + "\n"
        + "Source Address: " + source_address_ + "\n"
        + "Type: " + type_ + "\n"
    );
}
