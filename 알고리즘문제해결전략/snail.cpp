#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n,m;
double prob(int days, int climbed);

double cache[1000][2000];

int main()
{
     int numCases;
     cin>>numCases;
     vector<double> results;
     for(int i=0; i<numCases; i++){
          memset(cache,-1, sizeof(cache));
          cin>>n>>m;
          results.push_back(prob(0,0));
     }
     for(int i=0; i<numCases; i++){
          cout<<results[i]<<endl;
     }
     return 0;
}
double prob(int days, int climbed)
{
     if(days==n) return climbed>=n ? (double)1 : 0;
     double& ret = cache[days][climbed];
     if(!isnan(ret)) return ret;

     ret = 0.25 * prob(days+1, climbed+1) + 0.75 * prob(days+1, climbed+2);
     return ret;
}