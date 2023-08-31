#ifndef COMPRESSIBILITY_H
#define COMPRESSIBILITY_H
class Compressibility
{
public:
    pair<double, double> VaporLiquidCompressibility(const string &DatFileLocation, int Temperature, int BoxLength, int BoltzmannConstant);
};

#endif // DATA_PROCESSOR_H