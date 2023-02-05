#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Reader.h"

using namespace std;

Reader::Reader(const string& file_path) {
    input_file_.open(file_path);
    if (!input_file_.is_open()) {
        // error
        throw string("Invalid file path: " + file_path);
    }
}

vector<string> Reader::read_all() {
    vector<string> packets;
    while (!input_file_.eof()) {
        string packet;
        input_file_ >> packet;
        packets.push_back(packet); 
    }
    return packets;
}

Reader::~Reader() {
    input_file_.close();
}