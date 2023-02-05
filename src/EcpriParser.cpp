#include <iostream>
#include <string>
#include <vector>

#include "EcpriParser.h"
#include "EthernetPacket.h"

using namespace std;

EthernetPacket* EcpriParser::parse(unsigned int id, const string& packet) {
    EcpriPacket* ecpri_packet = new EcpriPacket(id, packet);
    ecpri_packet->set_destination_address(packet.substr(16, 12));
    ecpri_packet->set_source_address(packet.substr(28, 12));
    ecpri_packet->set_crc(packet.substr(packet.size() - 8));
    ecpri_packet->set_type(packet.substr(40, 4));

    ecpri_packet->set_concat_indicator("0");
    ecpri_packet->set_message_type(packet.substr(46, 2));
    ecpri_packet->set_payload_size(packet.substr(48, 4));
    ecpri_packet->set_protocol_version("1");
    ecpri_packet->set_rtc_id(packet.substr(52, 4));
    ecpri_packet->set_sequence_id(packet.substr(56, 4));
    return ecpri_packet;

}