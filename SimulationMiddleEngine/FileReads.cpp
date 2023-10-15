#include <bits/stdc++.h>
using namespace std;

map<string, string> parseInputFile(const string &filename)
{
    ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cerr << "Error opening the file." << endl;
        return {};
    }

    string line;
    map<string, string> data_inputs;

    // Skip the header line
    getline(inputFile, line);

    while (getline(inputFile, line))
    {
        istringstream iss(line);
        string species_type;
        iss >> species_type; // First value is the species type

        vector<string> values;
        string value;
        while (iss >> value)
        {
            values.push_back(value);
        }

        // Store values in the map
        if (!values.empty())
        {
            data_inputs[species_type] = values.back();
        }
    }

    inputFile.close();
    return data_inputs;
}

map<float, map<string, vector<float> > > readSpeciesData(const string &filePath)
{
    ifstream inputFile(filePath);
    map<float, map<string, vector<float> > > data;

    if (!inputFile.is_open())
    {
        cerr << "Error opening the file." << endl;
        return data;
    }

    string line;

    // Skip the header line
    getline(inputFile, line);

    while (getline(inputFile, line))
    {
        istringstream iss(line);
        float site_type;
        iss >> site_type;

        string potential;
        iss >> potential;

        float value;

        while (iss >> value)
        {
            data[site_type][potential].push_back(value);
        }
    }

    inputFile.close();
    return data;
}

map<float, map<string, vector<float> > > filterDataForSiteTypes(const vector<float> &siteTypes, const map<float, map<string, vector<float> > > &data)
{
    map<float, map<string, vector<float> > >
        filteredData;

    for (float siteType : siteTypes)
    {
        if (data.find(siteType) != data.end())
        {
            filteredData[siteType] = data.at(siteType);
        }
    }

    return filteredData;
}

map<string, vector<float> > getCordinateParticleTypeAndDiameter(const string &StructureCordinateFile){
    map<string, vector<float> > dataMap;
    ifstream file(StructureCordinateFile);
    string line;
    getline(file, line);
    getline(file, line);
    // file.eof() is true

    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

  // Access the last string.
  vector<float> Diameter, SiteType, XCordinate, YCordinate, ZCordinate;
    string last_string = words.back();
    int NumberOfSites = stoi(last_string), startwith=3;
    int StartOfDiameter = 5,EndOfDiameter =  StartOfDiameter + NumberOfSites - 1,StartOfSiteType = EndOfDiameter + 3, EndOfSiteType= StartOfSiteType + NumberOfSites - 1, StartOfCordinate = EndOfSiteType + 3, EndtOfCordinate = StartOfCordinate + NumberOfSites - 1;
    while (getline(file, line)) {
        startwith++;
        if (startwith > StartOfDiameter && startwith <= EndOfDiameter+1)
        {
            /* code */
            istringstream iss(line);
            float Site_No, Diameter_;
            iss >> Site_No >> Diameter_;
            Diameter.push_back(Diameter_);
        }
        else if (startwith > StartOfSiteType && startwith <= EndOfSiteType+1)
        {
            /* code */
            istringstream iss(line);
            float Site_No, Site_Type;
            iss >> Site_No >> Site_Type;
            SiteType.push_back(Site_Type);
        }
        else if (startwith > StartOfCordinate && startwith <= EndtOfCordinate+1)
        {
            /* code */
            // cout << line<<endl;
            istringstream iss(line);
            float x,y,z;
            iss >> x >> y >> z;
            XCordinate.push_back(x);
            YCordinate.push_back(y);
            ZCordinate.push_back(z);
        }
    }

    dataMap["Diameter"] = Diameter;
    dataMap["SiteType"] = SiteType;
    dataMap["XCordinate"] = XCordinate;
    dataMap["YCordinate"] = YCordinate;
    dataMap["ZCordinate"] = ZCordinate;

    file.close();
    return dataMap;
}

int main(int argc, char const *argv[])
{
    map<string, string> data_inputs = parseInputFile("Input.txt");

    for (const auto& pair : data_inputs) {
        cout << "Key: " << pair.first << " Value: " << pair.second << endl;
    }
    cout<<"1----------------------"<<endl;
    string filepath = data_inputs["Path_str_file"];
    cout<<filepath;
    cout<<"2----------------------"<<endl;
    map<string, vector<float> > dataMap;

    dataMap = getCordinateParticleTypeAndDiameter(filepath);

    for (const auto& pair : dataMap) {
        cout << "Key: " << pair.first << " Values: ";
        for (const float& value : pair.second) {
            cout << value << " ";
        }
        cout << endl;
    }

    cout<<"3----------------------"<<endl;

    vector<float> particletype = dataMap["SiteType"];

    for (float value : dataMap["SiteType"]) {
        cout << value << " ";
    }
    cout<<"4----------------------"<<endl;
    map<float, map<string, vector<float> > > paramter = readSpeciesData("species_type_exp.txt");

    for (const auto& outerPair : paramter) {
        cout << "Float Key: " << outerPair.first << endl;

        // Iterate through the inner map (string keys)
        for (const auto& innerPair : outerPair.second) {
            cout << "  String Key: " << innerPair.first << " Values: ";

            // Iterate through the vector of floats
            for (float value : innerPair.second) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
    cout<<"5----------------------"<<endl;
    map<float, map<string, vector<float> > > finalparam = filterDataForSiteTypes(particletype, paramter);

    for (const auto& outerPair : finalparam) {
        cout << "Float Key: " << outerPair.first << endl;

        // Iterate through the inner map (string keys)
        for (const auto& innerPair : outerPair.second) {
            cout << "  String Key: " << innerPair.first << " Values: ";

            // Iterate through the vector of floats
            for (float value : innerPair.second) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
    cout<<"6----------------------"<<endl;
    return 0;
}
