#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
double cache[1000][2000];

double prob(int days, int climbed);

int main()
{
     int numCases; 
     cin>>numCases;
     vector<double> results;
     for(int i=0; i<numCases; i++){
          fill(&cache[0][0], &cache[999][2000], -1);
          cin>>n>>m;
          results.push_back(prob(0,0));
     }   
     cout.precision(10);
     for(int i=0; i<numCases; i++){
          cout<<results[i]<<endl;
     }

     return 0;
}

double prob(int days, int climbed)
{
     if(days==m) return (climbed>=n ? 1 : 0);
     double& ret = cache[days][climbed];
     if(ret != -1) return ret;

     return ret = 0.25 * prob(days+1, climbed+1) + 0.75 * prob(days+1, climbed+2);
}