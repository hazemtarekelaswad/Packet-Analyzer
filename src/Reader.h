#ifndef READER_H
#define READER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Reader {
private:
    ifstream input_file_;

public:
    Reader(const string& file_path);
    vector<string> read();
    ~Reader();
};

#endif