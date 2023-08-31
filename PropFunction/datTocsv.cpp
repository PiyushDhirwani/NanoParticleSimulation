#include "datTocsv.h"
#include <bits/stdc++.h>
using namespace std;

string datTocsv::ConvertDatToCSV(const string &DatFileLocation, const string &CSVFileLocation)
{
    // Open the input .dat file
    ifstream input(DatFileLocation);
    if (!input.is_open())
    {
        return "Failed to open output file.";
    }

    // Open the output CSV file
    ofstream output(CSVFileLocation);
    if (!output.is_open())
    {
        return "Failed to open output file.";
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