#include "SurfaceTension.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int SurfaceTension::SURFACETension(int Nmin, int Nmax, int Nl, int Nv, int BoxLength, int Temperature,const string& FileLocation){

    map<string, vector<double>> DataFrame;
    
    ifstream infile(FileLocation);
    if (!infile.is_open()) {
        return 0;
    }

    
}