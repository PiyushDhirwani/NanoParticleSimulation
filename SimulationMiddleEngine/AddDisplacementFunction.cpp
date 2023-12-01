#include <bits/stdc++.h>
using namespace std;

vector<float> SimpleDisplacement(int ParticleType, vector<float> Ri, map<int, vector<int>> ConnectivityParticleType, map<int, vector<float>> CordinateParticleType1, map<int, vector<float>> CordinateParticleType2, int BoxSize, float Delta)
{
    float XCordinate = Ri[0], YCordinate = Ri[1], ZCordinate = Ri[2];
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> distribution(0.0, 1.0);

    vector<int> ConnectedParticleTypes = ConnectivityParticleType[ParticleType];
    float random_number1 = distribution(gen);
    float random_number2 = distribution(gen);
    float random_number3 = distribution(gen);

    float XDisplacement = random_number1 * 2 - 1, YDisplacement = random_number2 * 2 - 1, ZDisplacement = random_number3 * 2 - 1;

    float XNewCordinate = XCordinate + XDisplacement * Delta, YNewCordinate = YCordinate + YDisplacement * Delta, ZNewCordinate = ZCordinate + ZDisplacement * Delta;

    assert CordinateParticleType1 == CordinateParticleType2
    for (int i = 0; i < ConnectedParticleTypes.size(); i++)
    {
        vector<float> TempCord = CordinateParticleType1[ConnectedParticleTypes[i]]

            float XTempCord = TempCord[0],
                      YTempCord = TempCord[1], ZTempCord = TempCord[2];

        float XNewTempCord = XTempCord + XDisplacement * Delta, YNewTempCord = YTempCord + YDisplacement * Delta, ZNewTempCord = ZTempCord + ZDisplacement * Delta;

        if (XNewTempCord < 0 or XNewTempCord > BoxSize or YNewTempCord < 0 or YNewTempCord > BoxSize or ZNewTempCord < 0 or ZNewTempCord > BoxSize)
        {
            int Div = float(TempCord[0]) / BoxSize;
            TempCord[0] = TempCord[0] - Div * BoxSize;
            int Div = float(TempCord[1]) / BoxSize;
            TempCord[1] = TempCord[1] - Div * BoxSize;
            int Div = float(TempCord[2]) / BoxSize;
            TempCord[2] = TempCord[2] - Div * BoxSize;
        }
    }

    int flag = 0;
    for (int i = 0; i < ConnectedParticleTypes.size(); i++)
    {
        vector<float> TempCord = CordinateParticleType1[ConnectedParticleTypes[i]]

            float XTempCord = TempCord[0],
                      YTempCord = TempCord[1], ZTempCord = TempCord[2];

        float XNewTempCord = XTempCord + XDisplacement * Delta, YNewTempCord = YTempCord + YDisplacement * Delta, ZNewTempCord = ZTempCord + ZDisplacement * Delta;

        if (XNewTempCord < 0 or XNewTempCord > BoxSize or YNewTempCord < 0 or YNewTempCord > BoxSize or ZNewTempCord < 0 or ZNewTempCord > BoxSize)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        return {XCordinate, YCordinate, ZCordinate};
    }
    else
    {
        int Div = float(XNewCordinate) / BoxSize;
        XNewCordinate = XNewCordinate - BoxSize * Div;
        int Div = float(YNewCordinate) / BoxSize;
        YNewCordinate = YNewCordinate - BoxSize * Div;
        int Div = float(ZNewCordinate) / BoxSize;
        ZNewCordinate = ZNewCordinate - BoxSize * Div;

        for (int i = 0; i < ConnectedParticleTypes.size(); i++)
        {
            vector<float> TempCord = CordinateParticleType1[ConnectedParticleTypes[i]]

                TempCord[0] = TempCord[0] + XDisplacement * Delta;
            TempCord[1] = TempCord[1] + YDisplacement * Delta;
            TempCord[2] = TempCord[2] + ZDisplacement * Delta;

            if (TempCord[0] < 0 or TempCord[0] > BoxSize or TempCord[1] < 0 or TempCord[1] > BoxSize or TempCord[2] < 0 or TempCord[2] > BoxSize)
            {
                int Div = float(TempCord[0]) / BoxSize;
                TempCord[0] = TempCord[0] - Div * BoxSize;
                int Div = float(TempCord[1]) / BoxSize;
                TempCord[1] = TempCord[1] - Div * BoxSize;
                int Div = float(TempCord[2]) / BoxSize;
                TempCord[2] = TempCord[2] - Div * BoxSize;
            }
        }
        return {XNewCordinate, YNewCordinate, ZNewCordinate};
    }
}

vector<float> BigDisplacement(int ParticleType, vector<float> Ri, map<int, vector<int>> ConnectivityParticleType, map<int, vector<float>> CordinateParticleType, int BoxSize)
{
    float XCordinate = 0, YCordinate = 0, ZCordinate = 0;
    float Xcenter = Ri[0], Ycenter = Ri[1], Zcenter = Ri[2];
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> distribution(0.0, 1.0);

    vector<int> ConnectedParticleTypes = ConnectivityParticleType[ParticleType];
    float random_number1 = distribution(gen);
    float random_number2 = distribution(gen);
    float random_number3 = distribution(gen);

    float XDisplacement = random_number1 * BoxSize, YDisplacement = random_number2 * BoxSize, ZDisplacement = random_number3 * BoxSize;

    int Delta = 1;
    float XNewCordinate = XCordinate + XDisplacement * Delta, YNewCordinate = YCordinate + YDisplacement * Delta, ZNewCordinate = ZCordinate + ZDisplacement * Delta;

    int flag = 0;
    for (int i = 0; i < ConnectedParticleTypes.size(); i++)
    {
        float Xref= ConnectedParticleTypes[ConnectedParticleTypes[i]]-Xcenter, Yref= ConnectedParticleTypes[ConnectedParticleTypes[i]]-Ycenter, Zref= ConnectedParticleTypes[ConnectedParticleTypes[i]]-Zcenter;

        vector<float> TempCord = CordinateParticleType[ConnectedParticleTypes[i]]

            float XTempCord = TempCord[0],
                      YTempCord = TempCord[1], ZTempCord = TempCord[2];

        float XNewTempCord = Xref + XNewCordinate * Delta, YNewTempCord = Yref + YNewCordinate * Delta, ZNewTempCord = Zref + ZNewCordinate * Delta;

        if (XNewTempCord < 0 or XNewTempCord > BoxSize or YNewTempCord < 0 or YNewTempCord > BoxSize or ZNewTempCord < 0 or ZNewTempCord > BoxSize)
        {
            int Div = float(TempCord[0]) / BoxSize;
            TempCord[0] = TempCord[0] - Div * BoxSize;
            int Div = float(TempCord[1]) / BoxSize;
            TempCord[1] = TempCord[1] - Div * BoxSize;
            int Div = float(TempCord[2]) / BoxSize;
            TempCord[2] = TempCord[2] - Div * BoxSize;
        }
    }

    if (flag == 1)
    {
        return {XCordinate, YCordinate, ZCordinate};
    }
    else
    {
        int Div = float(XNewCordinate) / BoxSize;
        XNewCordinate = XNewCordinate - BoxSize * Div;
        int Div = float(YNewCordinate) / BoxSize;
        YNewCordinate = YNewCordinate - BoxSize * Div;
        int Div = float(ZNewCordinate) / BoxSize;
        ZNewCordinate = ZNewCordinate - BoxSize * Div;

        for (int i = 0; i < ConnectedParticleTypes.size(); i++)
        {
            vector<float> TempCord = CordinateParticleType[ConnectedParticleTypes[i]]

                TempCord[0] = TempCord[0] + XDisplacement * Delta;
            TempCord[1] = TempCord[1] + YDisplacement * Delta;
            TempCord[2] = TempCord[2] + ZDisplacement * Delta;

            if (TempCord[0] < 0 or TempCord[0] > BoxSize or TempCord[1] < 0 or TempCord[1] > BoxSize or TempCord[2] < 0 or TempCord[2] > BoxSize)
            {
                int Div = float(TempCord[0]) / BoxSize;
                TempCord[0] = TempCord[0] - Div * BoxSize;
                int Div = float(TempCord[1]) / BoxSize;
                TempCord[1] = TempCord[1] - Div * BoxSize;
                int Div = float(TempCord[2]) / BoxSize;
                TempCord[2] = TempCord[2] - Div * BoxSize;
            }
        }
        return {XNewCordinate, YNewCordinate, ZNewCordinate};
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
