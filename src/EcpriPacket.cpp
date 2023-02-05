#include <iostream>
#include <string>

#include "EcpriPacket.h"

using namespace std;

// void EcpriPacket::set_concat_indicator(const string& concat_indicator) { concat_indicator_ = concat_indicator; }
// void EcpriPacket::set_message_type(const string& message_type) { message_type_ = message_type; }
// void EcpriPacket::set_payload_size(const string& payload_size) { payload_size_ = payload_size; }
// void EcpriPacket::set_protocol_version(const string& protocol_version) { protocol_version_ = protocol_version; }
// void EcpriPacket::set_rtc_id(const string& rtc_id) { rtc_id_ = rtc_id; }
// void EcpriPacket::set_sequence_id(const string& sequence_id) { sequence_id_ = sequence_id; }

// string EcpriPacket::get_concat_indicator() const { return concat_indicator_; }
// string EcpriPacket::get_message_type() const { return message_type_; }
// string EcpriPacket::get_payload_size() const { return payload_size_; }
// string EcpriPacket::get_protocol_version() const { return protocol_version_; }
// string EcpriPacket::get_rtc_id() const { return rtc_id_; }
// string EcpriPacket::get_sequence_id() const { return sequence_id_; }

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
