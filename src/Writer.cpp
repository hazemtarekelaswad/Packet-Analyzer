#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Writer.h"
#include "EthernetPacket.h"

using namespace std;

Writer::Writer(const string& file_path) {
    output_file_.open(file_path);
    if (!output_file_.is_open()) {
        // error
        throw string("Invalid file path: " + file_path);
    }
}

void Writer::write(EthernetPacket* packet) {
    output_file_ << packet->to_string() << endl;
    output_file_ << "**************************************************************************************************************************************************************************************************************************************";
    output_file_ << endl << endl;
}

Writer::~Writer() {
    output_file_.close();
}