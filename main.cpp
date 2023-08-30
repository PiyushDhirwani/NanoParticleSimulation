#include "PropFunction/FileReadToCreateMap.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    FileReadToCreateMap data_processor;
    map<string, vector<string> > mp=data_processor.process_file("/Users/apple/Desktop/NanoParticleSimulation/PropFunction/output.csv");
    for (const auto &entry : mp) {
        cout << "Column: " << entry.first << ", Values: ";
        for (const string &value : entry.second) {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}