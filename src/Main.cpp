/*
    First, make sure you are in the Analyzer directory
    then, run "./run.sh <input_file> <output_file>"
*/

#include <iostream>
#include <vector>
#include "Reader.h"
#include "Writer.h"
#include "EthernetPacket.h"
#include "EcpriPacket.h"
#include "PacketFactory.h"
using namespace std;


int main(int argc, char** argv) {
    try {
        if (argc != 3) throw string("Invalid number of arguments");

        // Read all packets from the input file
        Reader reader(argv[1]);
        vector<string> packets = reader.read_all();
        
        // Parse and write each packet to the output file
        Writer writer(argv[2]);
        for (int id = 0; id < packets.size(); ++id) {
            PacketType type = EthernetPacket::get_packet_type(packets[id]);
            EthernetPacket* packet = PacketFactory::generate_packet(type);
            packet->parse(id, packets[id]);
            writer.write(packet);
        }
        cout << "Success\n";
    } catch (const string& err) {
        cerr << err;
    }
    return 0;
}