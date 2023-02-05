#include <iostream>
#include <string>

#include "EthernetPacket.h"

using std::string;


void EthernetPacket::parse(unsigned int id, const string& packet) {
    id_ = id;
    packet_ = packet;
    destination_address_ = packet.substr(16, 12);
    source_address_ = packet.substr(28, 12);
    crc_ = packet.substr(packet.size() - 8);
    type_ = packet.substr(40, 4);
}

string EthernetPacket::to_string() const {
    return string(
        "Packet # " + std::to_string(id_) + ":\n"
        + packet_ + "\n"
        + "CRC: " + crc_ + "\n"
        + "Destination Address: " + destination_address_ + "\n"
        + "Source Address: " + source_address_ + "\n"
        + "Type: " + type_ + "\n"
    );
}

PacketType EthernetPacket::get_packet_type(const string& packet) {
    if (packet.substr(40, 4) == "AEFE")
        return PacketType::ecpri;
    return PacketType::ethernet;
           
}
