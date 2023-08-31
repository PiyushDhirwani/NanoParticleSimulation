#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "FileReadToCreateMap.h"
using namespace std;

vector<double> GetLocalMaximaMinima(const string& DatFileLocation){
    cout<<setprecision(13);
    FileReadToCreateMap FileReadToCreateMap;
    map<string, vector<string> > dataMap = FileReadToCreateMap.process_file(DatFileLocation);
    vector<double> NvNminNlNmax;
    vector<pair<double, double> > local_maxima;
    vector<pair<double, double> > local_minima;

    for (int i = 1; i < dataMap["y0"].size() - 1; i++) {
        double prev=stod(dataMap["y0"][i - 1]);
        double curr=stod(dataMap["y0"][i]);
        double next=stod(dataMap["y0"][i + 1]);
        double pos=stod(dataMap["x"][i]);
        if (curr > prev && curr > next) {
            local_maxima.push_back(make_pair(pos, curr));
        }
        if (curr < prev && curr < next) {
            local_minima.push_back(make_pair(pos, curr));
        }
    }
    double Nv=local_maxima[0].first;
    NvNminNlNmax.push_back(Nv);
    double Nmin=local_minima[0].first;
    NvNminNlNmax.push_back(Nmin);
    double Nl=local_maxima[1].first;
    NvNminNlNmax.push_back(Nl);
    double Nmax=dataMap["y0"].size()-1;
    NvNminNlNmax.push_back(Nmax);

    return NvNminNlNmax;
}