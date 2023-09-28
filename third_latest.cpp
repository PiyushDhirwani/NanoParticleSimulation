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
    float XCordinate = EdgeLength * cos(AngleRadian), YCordinate = EdgeLength * sin(AngleRadian), ZCordinate = 0;
    vector<float> Cordinate;
    Cordinate.push_back(XCordinate);
    Cordinate.push_back(YCordinate);
    Cordinate.push_back(ZCordinate);
    return Cordinate;
}

void Input2D(int NumberOfParitcles, ofstream &outputFile)
{
    float ParticleType1, ParticleSize1;
    cout << "Enter ParticleType and ParticleSize For Particle 1: ";
    cin >> ParticleType1 >> ParticleSize1;
    vector<vector<float>> AllCordinates;
    vector<float> Cordinate(3, 0);
    AllCordinates.push_back(Cordinate);
    vector<pair<float, float>> Site_TypeDiameter;
    Site_TypeDiameter.push_back(make_pair(ParticleType1, ParticleSize1));
    // outputFile << "ParticleID x y z ParticleType ParticleSize" << endl;
    // outputFile << 1 << "          " << Cordinate[0] << " " << Cordinate[1] << " " << Cordinate[2] << " " << ParticleType1 << "            " << ParticleSize1 << endl;
    for (int i = 1; i < NumberOfParitcles; i++)
    {
        float EdgeLength, Angle, ParticleType, ParticleSize;
        cout << "Enter Distance with Respect to Particle 1 as Reference Point, Angle, ParticleType, ParticleSize For Particle " << i + 1 << ": ";
        cin >> EdgeLength >> Angle >> ParticleType >> ParticleSize;
        Site_TypeDiameter.push_back(make_pair(ParticleType, ParticleSize));
        Cordinate = FindCordinate2D(EdgeLength, Angle);
        for (int iterator = 0; iterator < 3; iterator++)
        {
            if ((Cordinate[iterator] > -1e-5 and Cordinate[iterator] < 0) or (Cordinate[iterator] < 1e-5 and Cordinate[iterator] > 0))
            {
                Cordinate[iterator] = 0;
            }
        }
        AllCordinates.push_back(Cordinate);
        // outputFile << i + 1 << "          " << Cordinate[0] << " " << Cordinate[1] << " " << Cordinate[2] << " "<<ParticleType << "            " << ParticleSize << endl;
    }
    outputFile << "Site_diameters:" << endl
               << "Site_No		Diameter" << endl;
    for (int i = 0; i < NumberOfParitcles; i++)
    {
        outputFile << i + 1 << "		" << Site_TypeDiameter[i].second << endl;
    }
    outputFile << "Types_of_sites:" << endl
               << "Site_No		Site_Type" << endl;
    for (int i = 0; i < NumberOfParitcles; i++)
    {
        outputFile << i + 1 << "		" << Site_TypeDiameter[i].first << endl;
    }
    outputFile << "x	y	z" << endl;
    for (int i = 0; i < NumberOfParitcles; i++)
    {
        outputFile << AllCordinates[i][0] << " " << AllCordinates[i][1] << " " << AllCordinates[i][2] << endl;
    }
    return;
}

void Input3D(int NumberOfParitcles, ofstream &outputFile)
{
    float ParticleType1, ParticleSize1;
    cout << "Enter ParticleType and ParticleSize For Particle 1: ";
    cin >> ParticleType1 >> ParticleSize1;
    vector<vector<float>> AllCordinates;
    vector<float> Cordinate(3, 0);
    AllCordinates.push_back(Cordinate);
    vector<pair<float, float>> Site_TypeDiameter;
    Site_TypeDiameter.push_back(make_pair(ParticleType1, ParticleSize1));
    // outputFile << "ParticleID x y z ParticleType ParticleSize" << endl;
    // outputFile << 1 << "          " << Cordinate[0] << " " << Cordinate[1] << " " << Cordinate[2] << " " << ParticleType1 << "            " << ParticleSize1 << endl;
    for (int i = 1; i < NumberOfParitcles; i++)
    {
        float EdgeLength, AnglePhi, AngleTheta, ParticleType, ParticleSize;
        cout << "Enter Distance with Respect to Particle 1 as Reference Point, AnglePhi, AngleTheta, ParticleType, ParticleSize For Particle " << i + 1 << ": ";
        cin >> EdgeLength >> AnglePhi >> AngleTheta >> ParticleType >> ParticleSize;
        Site_TypeDiameter.push_back(make_pair(ParticleType, ParticleSize));
        Cordinate = FindCordinate3D(EdgeLength, AnglePhi, AngleTheta);
        for (int iterator = 0; iterator < 3; iterator++)
        {
            if ((Cordinate[iterator] > -1e-5 and Cordinate[iterator] < 0) or (Cordinate[iterator] < 1e-5 and Cordinate[iterator] > 0))
            {
                Cordinate[iterator] = 0;
            }
        }
        AllCordinates.push_back(Cordinate);
        // outputFile << i + 1 << "          " << Cordinate[0] << " " << Cordinate[1] << " " << Cordinate[2] << " " << ParticleType << "            " << ParticleSize << endl;
    }
    outputFile << "Site_diameters:"
               << "Site_No		Diameter" << endl;
    for (int i = 0; i < NumberOfParitcles; i++)
    {
        outputFile << i + 1 << "		" << Site_TypeDiameter[i].second << endl;
    }
    outputFile << "Types_of_sites:" << endl
               << "Site_No		Site_Type" << endl;
    for (int i = 0; i < NumberOfParitcles; i++)
    {
        outputFile << i + 1 << "		" << Site_TypeDiameter[i].first << endl;
    }
    outputFile << "x	y	z" << endl;
    for (int i = 0; i < NumberOfParitcles; i++)
    {
        outputFile << AllCordinates[i][0] << " " << AllCordinates[i][1] << " " << AllCordinates[i][2] << endl;
    }
    return;
}

int main(int argc, char const *argv[])
{
    // vector<double> Cordinate = FindCordinate3D(3, 60, 45);
    // cout << Cordinate[0] << " " << Cordinate[1] << " " << Cordinate[2] << endl;

    ofstream outputFile("StructuralCordinate.dat");
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }
    outputFile << "*****species shape info***************" << endl;
    int NumberOfParitcles, StructureType;
    cout << "Enter the number of particles: ";
    cin >> NumberOfParitcles;
    outputFile << "No_of_sites = " << NumberOfParitcles << endl;
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