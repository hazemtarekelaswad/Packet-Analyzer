#include <iostream>
#include <vector>
#include "Reader.h"
#include "Writer.h"
#include "Parser.h"
#include "EcpriParser.h"
#include "EthernetPacket.h"
using namespace std;

enum class PacketType { ethernet, ecpri };

PacketType get_packet_type(const string& packet) {
    if (packet.substr(40, 4) == "AEFE")
        return PacketType::ecpri;
    return PacketType::ethernet;
           
}

Parser* generate_parser(PacketType type) {
    switch (type) {
        case PacketType::ethernet: return new Parser();
        case PacketType::ecpri: return new EcpriParser();
        default: return nullptr;
    }
}

int main() {
    try {
        Reader reader("../input_packets");
        vector<string> packets = reader.read();
        
        Writer writer("output");
        for (int id = 0; id < packets.size(); ++id) {
            PacketType type = get_packet_type(packets[id]);
            Parser* parser = generate_parser(type);
            EthernetPacket* parsed_packet = parser->parse(id, packets[id]);
            writer.write(parsed_packet);
        }
        
    } catch (const string& err) {
        cout << err;
    }
    return 0;
}