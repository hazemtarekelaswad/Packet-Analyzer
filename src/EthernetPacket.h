#ifndef ETHERNET_PACKET_H
#define ETHERNET_PACKET_H

#include <iostream>
#include <string>
using namespace std;

class EthernetPacket {
protected:
    unsigned int id_;
    string packet_;
    string crc_;
    string destination_address_;
    string source_address_;
    string type_;

public:
    EthernetPacket();
    EthernetPacket(unsigned int id, const string& packet);

    void set_crc(const string& crc);
    void set_destination_address(const string& destination_address);
    void set_source_address(const string& source_address);
    void set_type(const string& type);

    unsigned int get_id() const;
    string get_packet() const;
    string get_crc() const;
    string get_destination_address() const;
    string get_source_address() const;
    string get_type() const;

    virtual string to_string() const;
};

#endif