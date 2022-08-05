#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int n,m;
double prob(int days, int climbed);

double cache[1000][];

int main()
{
     int numCases;
     cin>>numCases;
     vector<double> results;
     for(int i=0; i<numCases; i++){
          memset(cahce,-1, sizeof(cache));
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
     
     double& ret = cache[days][climbed];
     if(ret!= -1) return ret;


     ret = 0.25*  prob(days+1, climbed+1) + 0.75 * prob(days+1, climbed+2);
     return ret;
}