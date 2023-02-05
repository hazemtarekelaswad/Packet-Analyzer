#ifndef ECPRI_PACKET_H
#define ECPRI_PACKET_H

#include <iostream>
#include <string>

#include "EthernetPacket.h"

using namespace std;

class EcpriPacket : public EthernetPacket {
private:
    string concat_indicator_;
    string message_type_;
    string payload_size_;
    string protocol_version_;
    string rtc_id_;
    string sequence_id_;
    
public:

    // void set_concat_indicator(const string& concat_indicator);
    // void set_message_type(const string& message_type);
    // void set_payload_size(const string& payload_size);
    // void set_protocol_version(const string& protocol_version);
    // void set_rtc_id(const string& rtc_id);
    // void set_sequence_id(const string& sequence_id);

    // string get_concat_indicator() const;
    // string get_message_type() const;
    // string get_payload_size() const;
    // string get_protocol_version() const;
    // string get_rtc_id() const;
    // string get_sequence_id() const;

    virtual void parse(unsigned int id, const string& packet) override;

    virtual string to_string() const override;
};

#endif