#ifndef ETHERNET_PACKET_H
#define ETHERNET_PACKET_H

#include <iostream>
#include <string>
using namespace std;

enum class PacketType { ethernet, ecpri };

/*
    This class is responsible for parsing and storing the data of an ethernet packet.
*/

class EthernetPacket {
protected:
    unsigned int id_;
    string packet_;
    string crc_;
    string destination_address_;
    string source_address_;
    string type_;

public:

    virtual void parse(unsigned int id, const string& packet);
    virtual string to_string() const;

    static PacketType get_packet_type(const string& packet);
};

#endif