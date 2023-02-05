#ifndef PACKET_FACTORY_H
#define PACKET_FACTORY_H

#include "EthernetPacket.h"
#include "EcpriPacket.h"

class PacketFactory {
public:
    static EthernetPacket* generate_packet(PacketType type);
};

#endif