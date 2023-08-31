#include "PropFunction/FileReadToCreateMap.h"
#include "PropFunction/Compressibility.h"
#include "PropFunction/datTocsv.h"
#include "PropFunction/delta_u.h"
#include "PropFunction/Density.h"
#include "PropFunction/GetMaximaMinima.h"
#include "PropFunction/SurfaceTension.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main() {
    Compressibility Compressibility;
    pair<double, double> p1 = Compressibility.VaporLiquidCompressibility("/Users/apple/Desktop/TimePass/ccode/gnn.dat", 300, 10, 1);
    cout<< p1.first << " " << p1.second << endl;
    cout<<"-------------------"<<endl;
    datTocsv datTocsv;
    string p2 = datTocsv.ConvertDatToCSV("/Users/apple/Desktop/TimePass/ccode/gnn.dat", "test.csv");
    cout<<p2<<endl;
    cout<<"-------------------"<<endl;
    delta_u delta_u;
    pair<double, double> p3 = delta_u.Delta_U("/Users/apple/Desktop/TimePass/ccode/gnn.dat", 300, 10);
    cout<< p3.first << " " << p3.second << endl;
    cout<<"-------------------"<<endl;
    Density Density;
    pair<double, double> p4 = Density.VaporLiquidDensity("/Users/apple/Desktop/TimePass/ccode/gnn.dat");
    cout<< p4.first << " " << p4.second << endl;
    cout<<"-------------------"<<endl;
    FileReadToCreateMap FileReadToCreateMap;
    map<string, vector<string> > p5 = FileReadToCreateMap.process_file("/Users/apple/Desktop/TimePass/ccode/gnn.dat");
    for (const auto &entry : p5) {
        cout << "Column: " << entry.first << ", Values: ";
        for (const string &value : entry.second) {
            cout << value << " ";
        }
        cout << endl;
    }
    cout<<"-------------------"<<endl;
    GetMaximaMinima GetMaximaMinima;
    vector<double> p6 = GetMaximaMinima.GetLocalMaximaMinima("/Users/apple/Desktop/TimePass/ccode/gnn.dat");
    for (const double &value : p6) {
        cout << value << " ";
    }
    cout<<endl<<"-------------------"<<endl;
    SurfaceTension SurfaceTension;
    double p7 = SurfaceTension.SURFACETension("/Users/apple/Desktop/TimePass/ccode/gnn.dat", 300, 10);
    cout<<p7<<endl;
    return 0;
}