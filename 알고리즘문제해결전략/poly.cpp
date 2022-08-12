#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int solve();
int mod = 10000000;
int cache[100][100];
int cnt(int rest, int first);
int solve();
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
int cnt(int rest, int first)
{
     if(rest == first) return 1;
     int& ret = cache[rest][first];
     if(ret!= -1) return ret;
     ret =0;
     for(int i=1; i<=rest-first; i++){
          ret +=cnt(rest-first, i)*(first+i-1)/mod;
     }
     return ret;
}
int solve()
{
     memset(cache, -1, sizeof(cache));
     int ret =0;
     for(int i=1; i<=n; i++){
          ret+=cnt(n,i);
     }
     return ret;
}