#ifndef FILEREADTOCREATEMAP_H
#define FILEREADTOCREATEMAP_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class FileReadToCreateMap {
public:
    map<string, vector<string> > process_file(const string& file_location);
};

#endif // DATA_PROCESSOR_H