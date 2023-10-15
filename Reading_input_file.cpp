#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string line;
    map<string, string> data_inputs; // Map to store data_inputs;

    // Skip the header line
    getline(inputFile, line);

    // Read and parse lines
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string species_type;
        iss >> species_type; // First value is the species type

        vector<string> values;
        string value;
        while (iss >> value) {
            values.push_back(value);
        }

        // Store values in the map
        data_inputs [species_type] = value;
    }

    inputFile.close();

    // Print the data_inputs; to verify
    for (const auto& pair : data_inputs) {
        cout << pair.first << ": "<< pair.second << endl;

        
    }

    cout<<data_inputs["Chemical_potential"]<<endl;

    return 0;
}