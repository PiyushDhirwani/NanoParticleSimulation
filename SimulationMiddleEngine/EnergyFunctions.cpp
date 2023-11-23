#include<bits/stdc++.h>
using namespace std;

float getEnergy(float x1, float y1, float z1, float x2, float y2, float z2, int Site_Type, string Potential_Type, int dataMap)
{
    vector<float> param = dataMap[Site_Type][Potential_Type];
    float r12 = pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2);
    if (Potential_Type=="HS"){
        if (r12 < pow(param[0],2)){/// change to diameter // no need to use parameter just use of diameter comaprision
            return 1e100;
        }
        else{
            return 0;
        }
    }
    else if (Potential_Type=="SW"){
        if (r12 < pow(param[0],2)){ //r12 sigma 12 // param2 
            return 1e100;
        }
        else if (r12>=pow(param[0],2) and r12<param[1]+pow(param[0],2)){ //lamda*sigma12 ^2 // param2
            return -param[1]; //param 0
        }
        else{
            return 0;
        }
    }
}


//sperate function for each potential
// rijsq
// pass rij^2

//position
//param list
//size of particle separately
// sigma 12
// power of sigma 12

int main(int argc, char const *argv[])
{
    /* code */
    float Energy = getEnergy(0,0,0,0,0,1,1,"HS",dataMap);
    return 0;
}
