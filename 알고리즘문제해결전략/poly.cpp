#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int n;
int solve();
int mod = 10000000;

int main()
{

     int numCases;
     cin>>numCases;
     vector<int> results;
     for(int i=0; i<numCases; i++){
          cin>>n;
          results.push_back(solve());
     }
     for(int i=0; i<numCases; i++){
          cout<<results[i]<<endl;
     }
     return 0;
}


