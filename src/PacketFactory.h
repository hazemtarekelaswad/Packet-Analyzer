#ifndef PACKET_FACTORY_H
#define PACKET_FACTORY_H

#include "EthernetPacket.h"
#include "EcpriPacket.h"

/*
    This class acts as a factory for generating packets, based on the type of packet.
*/
class PacketFactory {
public:
    // This function is used to generate a packet based on the type of packet.
    static EthernetPacket* generate_packet(PacketType type);
};

#endif