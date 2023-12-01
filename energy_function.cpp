

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

double calculateEnergy(const vector<double> &r1, const vector<double> &r2, const vector<double> &param1, const vector<double> &param2, int potential_type1, int potential_type2)
{
    double x1 = r1[0], y1 = r1[1], z1 = r1[2], d1 = r1[3];
    double x2 = r2[0], y2 = r2[1], z2 = r2[2], d2 = r2[3];

    double sigmaHS = (d1 + d2) / 2.0;
    double rij = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));

    if (rij < sigmaHS)
    {
        return 1e100;
    }
    else if (sigmaHS <= rij && rij <=  max(d1+ param1[1], d2+param2[1]))
    {
        if ((potential_type1 == 0 && (potential_type2 == 0 || potential_type2 == 1)) || (potential_type2 == 0 && (potential_type1 == 0 || potential_type1 == 1)))
        {
            return 0;
        }
        else if (potential_type1 == 1 && (potential_type2 == 1))
        {
            return -sqrt(param1[0] * param2[0]);
        }
    }
    return 0;
}

// original code
// double calculateTotalEnergy(const vector<vector<vector<double>>> &positions, const vector<vector<vector<double>>> &parameters, const vector<vector<int>> &potential_types)
// {
//     int N = positions.size();
//     double totalEnergy = 0.0;

//     for (int i = 0; i < N-1; ++i)
//     {
//         for (int j = i + 1; j < N; ++j)
//         {
//             double energy = calculateEnergy(
//                 positions[i][0], positions[j][0], parameters[i][0], parameters[j][0],
//                 potential_types[i][0], potential_types[j][0]);
//             totalEnergy += energy;
            
//         }
//     }

//     return totalEnergy;
// }

// double calculateIndividualEnergy(int i, const vector<vector<vector<double>>> &positions, const vector<vector<vector<double>>> &parameters, const vector<vector<int>> &potential_types)
// {
//     double energy = 0.0;
//     int N = positions.size();

//     for (int j = 0; j < N; ++j)
//     {
//         if (i != j)
//         {
//             energy += calculateEnergy(
//                 positions[i][0], positions[j][0], parameters[i][0], parameters[j][0],
//                 potential_types[i][0], potential_types[j][0]);
//         }
//     }

//     return energy;
// }




// int main()
// {

//     //testing the total energy function
//     int N = 4; // Number of particles
//     vector<vector<vector<double>>> positions(N);
//     vector<vector<vector<double>>> parameters(N);
//     vector<vector<int>> potential_types(N);

//     // Populate particle positions, parameters, and potential types
//     // Example data for 4 particles
//     for (int i = 0; i < N; ++i) {
//         positions[i] = {{i * 1.5, i * 1.5, 0.0, 2.0}}; // Example positions for each particle adjusted to meet the condition
//         parameters[i] = {{1.0, 1.0}}; // Example parameters (eps, alpha) for each particle adjusted to meet the condition
//         potential_types[i] = {1}; // Example potential type (0 for Hard Sphere, 1 for Square Well) for each particle
//     }

//     double totalEnergy = calculateTotalEnergy(positions, parameters, potential_types);

//     cout << "Total energy of " << N << " particles: " << totalEnergy << endl;

//     return 0;

//     // testing the individual energy function
//     // int N = 4; // Number of particles
//     // vector<vector<vector<double>>> positions(N);
//     // vector<vector<vector<double>>> parameters(N);
//     // vector<vector<int>> potential_types(N);

//     // // Populate particle positions, parameters, and potential types
//     // // Example data for 4 particles
//     // for (int i = 0; i < N; ++i)
//     // {
//     //     positions[i] = {{i * 5.0, i *1.5, 0.0, 1.0}}; // Example positions for each particle
//     //     parameters[i] = {{1.0, 0.5}};                  // Example parameters (eps, alpha) for each particle
//     //     potential_types[i] = {1};                      // Example potential type (0 for Hard Sphere, 1 for Square Well) for each particle
//     // }

//     // // Calculate individual energy for particle '0'
//     // int particleIndex = 0;
//     // double energy = calculateIndividualEnergy(particleIndex, positions, parameters, potential_types);

//     // cout << "Individual energy for particle " << particleIndex << ": " << energy << endl;

//     // return 0;
// }


double calculateTotalEnergy(const vector<vector<vector<double>>>& positions, const vector<vector<vector<double>>>& parameters, const vector<vector<int>>& potential_types, const map<int, vector<int>>& connectivity) {
    double totalEnergy = 0.0;

    for (const auto& particle : connectivity) {
        int center = particle.first;
        const vector<int>& connectedParticles = particle.second;

        // Calculate energies only for the center particle
        for (int i = center + 1; i < positions.size(); ++i) {
            if (i != center && find(connectedParticles.begin(), connectedParticles.end(), i) == connectedParticles.end()) {
                double energy = calculateEnergy(
                    positions[center][0], positions[i][0],
                    parameters[center][0], parameters[i][0],
                    potential_types[center][0], potential_types[i][0]
                );
                totalEnergy += energy;
            }
        }
    }

    return totalEnergy;
}

double calculateIndividualEnergy(int i, const vector<vector<vector<double>>>& positions, const vector<vector<vector<double>>>& parameters, const vector<vector<int>>& potential_types, const map<int, vector<int>>& connectivity) {
    double energy = 0.0;
    int N = positions.size();

    if (connectivity.find(i) != connectivity.end()) {
        const vector<int>& connectedParticles = connectivity.at(i);

        for (int j = 0; j < N; ++j) {
            if (i != j && find(connectedParticles.begin(), connectedParticles.end(), j) == connectedParticles.end()) {
                energy += calculateEnergy(
                    positions[i][0], positions[j][0],
                    parameters[i][0], parameters[j][0],
                    potential_types[i][0], potential_types[j][0]
                );
            }
        }
    } else {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                energy += calculateEnergy(
                    positions[i][0], positions[j][0],
                    parameters[i][0], parameters[j][0],
                    potential_types[i][0], potential_types[j][0]
                );
            }
        }
    }

    return energy;
}

int main() {
    int N = 6; // Number of particles
    vector<vector<vector<double>>> positions(N);
    vector<vector<vector<double>>> parameters(N);
    vector<vector<int>> potential_types(N);
    map<int, vector<int>> connectivity;

    // Populate particle positions, parameters, and potential types
    // Example data for 6 particles
    for (int i = 0; i < N; ++i) {
        positions[i] = {{i * 1.0, i * 1.0, 0.0, 2.0}}; // Example positions for each particle
        parameters[i] = {{1.0, 0.5}}; // Example parameters (eps, alpha) for each particle
        potential_types[i] = {1}; // Example potential type (0 for Hard Sphere, 1 for Square Well) for each particle
    }

    // Define connectivity, where particle 1 has connected particles 2 and 3, and particle 4 has connected particles 5 and 6
    connectivity[1] = {2, 3};
    connectivity[4] = {5, 6};

    double totalEnergy = calculateTotalEnergy(positions, parameters, potential_types, connectivity);

    cout << "Total energy of " << N << " particles: " << totalEnergy << endl;

    // Test individual energies for each particle
    for (int i = 0; i < N; ++i) {
        double individualEnergy = calculateIndividualEnergy(i, positions, parameters, potential_types, connectivity);
        cout << "Individual energy for particle " << i << ": " << individualEnergy << endl;
    }

    return 0;
}