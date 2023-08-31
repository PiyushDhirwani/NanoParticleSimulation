#include "FileReadToCreateMap.h"
#include "GetMaximaMinima.h"
#include "Density.h"
#include <bits/stdc++.h>

using namespace std;

pair<double, double> Density::VaporLiquidDensity(const string &DatFileLocation)
{
    cout << setprecision(13);
    FileReadToCreateMap FileReadToCreateMap;
    map<string, vector<string> > dataMap = FileReadToCreateMap.process_file(DatFileLocation);
    GetMaximaMinima GetMaximaMinima;
    vector<double> NvNminNlNmax = GetMaximaMinima.GetLocalMaximaMinima(DatFileLocation);
    double Nv = NvNminNlNmax[0], Nmin = NvNminNlNmax[1], Nl = NvNminNlNmax[2], Nmax = NvNminNlNmax[3];
    double VaporDensity = 0, LiquidDensity = 0, lnpiavg = 0;
    for (int i = 0; i <= Nmax; i++)
    {
        double lnpi = exp(stod(dataMap["y0"][i]));
        if (i <= Nmin)
        {
            VaporDensity += (i * lnpi);
        }
        else
        {
            LiquidDensity += (i * lnpi);
        }
        lnpiavg += lnpi;
    }
    VaporDensity /= lnpiavg;
    LiquidDensity /= lnpiavg;

    return make_pair(VaporDensity, LiquidDensity);
}