#include "FileReadToCreateMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

pair<double, double> Delta_U(const string& DatFileLocation, int Temperature,int BoxLength) {
    cout<<setprecision(13);
    FileReadToCreateMap FileReadToCreateMap;
    map<string, vector<string> > dataMap = FileReadToCreateMap.process_file(DatFileLocation);
    vector<double> delta_u_vector;
    double Volume = pow(BoxLength,3);
    for (int i=0;i<dataMap["y0"].size()-1;i++){
        double delta_u=(-Temperature/Volume)*(stod(dataMap["y0"][i+1])-stod(dataMap["y0"][i]));
        delta_u_vector.push_back(delta_u);
    }
    vector<pair<double, double> > local_maxima, local_minima;

    for (int i = 1; i < dataMap["y0"].size() - 1; i++) {
        double prev=stod(dataMap["y0"][i - 1]), curr=stod(dataMap["y0"][i]), next=stod(dataMap["y0"][i + 1]), pos=stod(dataMap["x"][i]);
        if (curr > prev && curr > next) {
            local_maxima.push_back(make_pair(pos, curr));
        }
        if (curr < prev && curr < next) {
            local_minima.push_back(make_pair(pos, curr));
        }
    }

    double delta_u_v=local_maxima[0].second, delta_u_l=local_minima[0].second;

    return make_pair(delta_u_v, delta_u_l);
}