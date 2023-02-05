#ifndef WRITER_H
#define WRITER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "EthernetPacket.h"

using namespace std;

/*
    This class is responsible for writing packets to an output file.
*/

class Writer {
private:
    ofstream output_file_;

public:
    Writer(const string& file_path);
    void write(EthernetPacket* packet);
    ~Writer();
};

#endif