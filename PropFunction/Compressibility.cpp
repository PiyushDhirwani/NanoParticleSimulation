#include "FileReadToCreateMap.h"
#include "GetMaximaMinima.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map> 
#include <string>

using namespace std;

pair<double, double> VaporLiquidCompressibility(const string& DatFileLocation, int Temperature, int BoxLength,int BoltzmannConstant) {
    cout<<setprecision(13);
    FileReadToCreateMap FileReadToCreateMap;
    map<string, vector<string> > dataMap = FileReadToCreateMap.process_file(DatFileLocation);
    vector<double> NvNminNlNmax = GetLocalMaximaMinima(DatFileLocation);
    double Nv = NvNminNlNmax[0], Nmin = NvNminNlNmax[1], Nl = NvNminNlNmax[2], Nmax = NvNminNlNmax[3];
    double VaporCompressibility = 0, LiquidCompressibility = 0, lnpiavg=0, VaporDensity = 0, LiquidDensity = 0;
    for (int i = 0; i <= Nmax; i++){
        double lnpi=exp(stod(dataMap["y0"][i]));
        if (i<=Nmin){
            VaporDensity+=(i*lnpi);
            VaporCompressibility+=(i*i*lnpi);
        }
        else{
            LiquidDensity+=(i*lnpi);
            LiquidCompressibility+=(i*i*lnpi);
        }
        lnpiavg+=lnpi;
    }
    VaporDensity/=lnpiavg;
    LiquidDensity/=lnpiavg;
    VaporCompressibility/=lnpiavg;
    LiquidCompressibility/=lnpiavg;

    double Kappa = pow(BoxLength,3)/(BoltzmannConstant*Temperature);
    VaporCompressibility = Kappa*(VaporCompressibility - VaporDensity*VaporDensity)/(VaporDensity*VaporDensity);
    LiquidCompressibility = Kappa*(LiquidCompressibility - LiquidDensity*LiquidDensity)/(LiquidDensity*LiquidDensity);

    return make_pair(VaporCompressibility, LiquidCompressibility);

}