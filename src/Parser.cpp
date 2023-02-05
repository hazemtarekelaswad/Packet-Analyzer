#include <iostream>
#include <string>
#include <vector>

#include "Parser.h"
#include "EthernetPacket.h"

using namespace std;

EthernetPacket* Parser::parse(unsigned int id, const string& packet) {
    EthernetPacket* ethernet_packet = new EthernetPacket(id, packet);
    ethernet_packet->set_destination_address(packet.substr(16, 12));
    ethernet_packet->set_source_address(packet.substr(28, 12));
    ethernet_packet->set_crc(packet.substr(packet.size() - 8));
    ethernet_packet->set_type(packet.substr(40, 4));
    return ethernet_packet;

}