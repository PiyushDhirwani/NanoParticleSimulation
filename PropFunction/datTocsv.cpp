#include "datTocsv.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string datTocsv::ConvertDatToCSV(const string &DatFileLocation, const string &CSVFileLocation)
{
    // Open the input .dat file
    ifstream input(DatFileLocation);
    if (!input.is_open())
    {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    // Open the output CSV file
    ofstream output(CSVFileLocation);
    if (!output.is_open())
    {
        cerr << "Failed to open output file." << endl;
        return 1;
    }

    string line;
    while (getline(input, line))
    {
        istringstream iss(line);
        vector<string> tokens;

        string token;
        while (iss >> token)
        {
            tokens.push_back(token);
        }

        // Write CSV row
        for (size_t i = 0; i < tokens.size(); ++i)
        {
            output << tokens[i];
            if (i != tokens.size() - 1)
            {
                output << ",";
            }
        }
        output << endl;
    }

    // Close the files
    input.close();
    output.close();

    return CSVFileLocation;
}