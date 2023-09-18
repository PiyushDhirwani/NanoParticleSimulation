#include <bits/stdc++.h>
using namespace std;

vector<float> FindCordinate3D(float EdgeLength, float AnglePhi, float AngleTheta)
{

    float AnglePhiRadian = M_PI * AnglePhi / 180, AngleThetaRadian = M_PI * AngleTheta / 180;
    float XCordinate = EdgeLength * sin(AnglePhiRadian) * cos(AngleThetaRadian), YCordinate = EdgeLength * sin(AnglePhiRadian) * sin(AngleThetaRadian), ZCordinate = EdgeLength * cos(AnglePhiRadian);
    vector<float> Cordinate;
    Cordinate.push_back(XCordinate);
    Cordinate.push_back(YCordinate);
    Cordinate.push_back(ZCordinate);
    return Cordinate;
}

vector<float> FindCordinate2D(float EdgeLength, float Angle)
{

    float AngleRadian = M_PI * Angle / 180;
    float XCordinate = EdgeLength * cos(AngleRadian), YCordinate = EdgeLength * sin(AngleRadian);
    vector<float> Cordinate;
    Cordinate.push_back(XCordinate);
    Cordinate.push_back(YCordinate);
    return Cordinate;
}

void Input2D(int NumberOfParitcles, ofstream &outputFile)
{
    float ParticleType1, ParticleSize1;
    cout << "Enter ParticleType and ParticleSize For Particle 1: ";
    cin >> ParticleType1 >> ParticleSize1;
    vector<float> Cordinate(2, 0);
    outputFile << "ParticleID x y z ParticleType ParticleSize" << endl;
    outputFile << 1 << "          " << Cordinate[0] << " " << Cordinate[1] << " " << 0 << " " << ParticleType1 << "            " << ParticleSize1 << endl;
    for (int i = 1; i < NumberOfParitcles; i++)
    {
        float EdgeLength, Angle, ParticleType, ParticleSize;
        cout << "Enter Distance with Respect to Particle 1 as Reference Point, Angle, ParticleType, ParticleSize For Particle " << i + 1 << ": ";
        cin >> EdgeLength >> Angle >> ParticleType >> ParticleSize;
        Cordinate = FindCordinate2D(EdgeLength, Angle);
        for (int iterator = 0; iterator < 2; iterator++)
        {
            if ((Cordinate[iterator] > -1e-5 and Cordinate[iterator] < 0) or (Cordinate[iterator] < 1e-5 and Cordinate[iterator] > 0))
            {
                Cordinate[iterator] = 0;
            }
        }
        outputFile << i + 1 << "          " << Cordinate[0] << " " << Cordinate[1] << " " << ParticleType << "            " << ParticleSize << endl;
    }
    return;
}

void Input3D(int NumberOfParitcles, ofstream &outputFile)
{
    float ParticleType1, ParticleSize1;
    cout << "Enter ParticleType and ParticleSize For Particle 1: ";
    cin >> ParticleType1 >> ParticleSize1;
    vector<float> Cordinate(3, 0);
    outputFile << "ParticleID x y z ParticleType ParticleSize" << endl;
    outputFile << 1 << "          " << Cordinate[0] << " " << Cordinate[1] << " " << Cordinate[2] << " " << ParticleType1 << "            " << ParticleSize1 << endl;
    for (int i = 1; i < NumberOfParitcles; i++)
    {
        float EdgeLength, AnglePhi, AngleTheta, ParticleType, ParticleSize;
        cout << "Enter Distance with Respect to Particle 1 as Reference Point, AnglePhi, AngleTheta, ParticleType, ParticleSize For Particle " << i + 1 << ": ";
        cin >> EdgeLength >> AnglePhi >> AngleTheta >> ParticleType >> ParticleSize;
        Cordinate = FindCordinate3D(EdgeLength, AnglePhi, AngleTheta);
        for (int iterator = 0; iterator < 3; iterator++)
        {
            if ((Cordinate[iterator] > -1e-5 and Cordinate[iterator] < 0) or (Cordinate[iterator] < 1e-5 and Cordinate[iterator] > 0))
            {
                Cordinate[iterator] = 0;
            }
        }
        outputFile << i + 1 << "          " << Cordinate[0] << " " << Cordinate[1] << " " << Cordinate[2] << " " << ParticleType << "            " << ParticleSize << endl;
    }
    return;
}

int main(int argc, char const *argv[])
{
    // vector<double> Cordinate = FindCordinate3D(3, 60, 45);
    // cout << Cordinate[0] << " " << Cordinate[1] << " " << Cordinate[2] << endl;

    ofstream outputFile("StructuralCordinate.txt");
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }
    int NumberOfParitcles, StructureType;
    cout << "Enter the number of particles: ";
    cin >> NumberOfParitcles;
    cout << "Please Enter 0 if you have 2D Structure, Else Enter Any Integer: ";
    cin >> StructureType;
    if (StructureType == 0 or NumberOfParitcles <= 3)
    {
        Input2D(NumberOfParitcles, outputFile);
    }
    else
    {
        Input3D(NumberOfParitcles, outputFile);
    }
    outputFile.close();
    return 0;
}