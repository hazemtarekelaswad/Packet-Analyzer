#ifndef ECPRI_PARSER_H
#define ECPRI_PARSER_H

#include <iostream>
#include <string>
#include <vector>

#include "EthernetPacket.h"
#include "EcpriPacket.h"
#include "Parser.h"

using namespace std;

class EcpriParser : public Parser {
private:
public:
    virtual EthernetPacket* parse(unsigned int id, const string& packet) override;


};

#endif