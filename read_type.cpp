
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream inputFile("species_type.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string line;
    map<string, vector<string>> data; // Map to store data

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
        data[species_type] = values;
    }

    inputFile.close();

    // Print the data to verify
    for (const auto& pair : data) {
        cout << "Species Type: " << pair.first << endl;
        const vector<string>& values = pair.second;
        for (const string& value : values) {
            cout << value << "\t";
        }
        cout << endl;
    }

    return 0;
}
