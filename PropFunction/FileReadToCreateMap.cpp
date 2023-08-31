#include "FileReadToCreateMap.h"
#include "datTocsv.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, vector<string>> FileReadToCreateMap::process_file(const string &DatFileLocation)
{

    // Convert .dat to .csv
    datTocsv datTocsv;
    string CSVFileLocation = "temp.csv";
    CSVFileLocation = datTocsv.ConvertDatToCSV(DatFileLocation, CSVFileLocation);

    ifstream input(CSVFileLocation);
    if (!input.is_open())
    {
        cerr << "Failed to open input file." << endl;
        return {};
    }

    map<string, vector<string>> dataMap; // Store values as strings

    string headerLine;
    if (getline(input, headerLine))
    {
        istringstream headerStream(headerLine);
        string column;
        getline(headerStream, column, ','); // Skip the first column
        dataMap["x"].push_back(column);     // Initialize 'x'
        int columnIndex = 0;
        while (getline(headerStream, column, ','))
        {
            dataMap["y" + to_string(columnIndex)].push_back(column); // Initialize 'y0', 'y1', 'y2', ...
            columnIndex++;
        }
    }

    string line;
    while (getline(input, line))
    {
        istringstream lineStream(line);
        string cell;
        getline(lineStream, cell, ','); // Read the first column ('x')
        dataMap["x"].push_back(cell);
        int columnIndex = 0;
        while (getline(lineStream, cell, ','))
        {
            dataMap["y" + to_string(columnIndex)].push_back(cell);
            columnIndex++;
        }
    }

    int DeleteCSVFile = remove(CSVFileLocation.c_str());

    return dataMap;
}