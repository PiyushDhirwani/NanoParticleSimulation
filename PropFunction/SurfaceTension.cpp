#include "SurfaceTension.h"
#include "FileReadToCreateMap.h"
#include "GetMaximaMinima.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

double SurfaceTension::SURFACETension(const string& DatFileLocation, int Temperature,int BoxLength){


    cout<<setprecision(13);
    FileReadToCreateMap FileReadToCreateMap;
    map<string, vector<string> > dataMap = FileReadToCreateMap.process_file(DatFileLocation);
    vector<double> NvNminNlNmax=GetLocalMaximaMinima(DatFileLocation);
    double Nv=NvNminNlNmax[0], Nmin=NvNminNlNmax[1], Nl=NvNminNlNmax[2], Nmax=NvNminNlNmax[3];

    double Y_Nv=stod(dataMap["y0"][Nv]),Y_Nmin=stod(dataMap["y0"][Nmin]), Y_Nl=stod(dataMap["y0"][Nl]);

    double STension = Temperature*(0.5*(Y_Nv+Y_Nmin)-Y_Nl)/(2*BoxLength*BoxLength);

    return STension;

}