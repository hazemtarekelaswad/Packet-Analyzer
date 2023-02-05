#ifndef ECPRI_PACKET_H
#define ECPRI_PACKET_H

#include <iostream>
#include <string>

#include "EthernetPacket.h"

using namespace std;

/*
    This class is responsible for parsing and storing the data of an ecpri packet.
*/

class EcpriPacket : public EthernetPacket {
private:
    string concat_indicator_;
    string message_type_;
    string payload_size_;
    string protocol_version_;
    string rtc_id_;
    string sequence_id_;
    
public:

    virtual void parse(unsigned int id, const string& packet) override;

    virtual string to_string() const override;
};

#endif