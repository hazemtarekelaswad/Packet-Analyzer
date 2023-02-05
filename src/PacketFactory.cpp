#include "EthernetPacket.h"
#include "EcpriPacket.h"
#include "PacketFactory.h"


EthernetPacket* PacketFactory::generate_packet(PacketType type) {
    switch (type) {
        case PacketType::ethernet: return new EthernetPacket();
        case PacketType::ecpri: return new EcpriPacket();
        default: return nullptr;
    }
}