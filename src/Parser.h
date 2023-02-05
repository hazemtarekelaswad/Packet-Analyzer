#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>

#include "EthernetPacket.h"

using namespace std;

class Parser {
protected:

public:
    virtual EthernetPacket* parse(unsigned int id, const string& packet);

};

#endif