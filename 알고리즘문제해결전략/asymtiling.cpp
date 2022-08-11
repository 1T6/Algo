#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cache[100];
int mod = 1000000007;
int solve();
int fill(int x);

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

int fill(int x)
{
     if(x==n) return 1;
     if(x>n) return 0;
     int& ret = cache[x];
     if(ret != -1) return ret;
     return ret = (fill(x+1)+fill(x+2))%mod;
}

int solve()
{
     memset(cache, -1, sizeof(cache));
     int ret = (fill(0) - fill(n/2) + mod)%mod;
     if(n%2 ==0) ret = (ret-fill(n/2+1) +mod)%mod;
     return ret;
}