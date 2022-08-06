#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cache[100];
int mod = 1000000007;
int fill(int x);
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

int fill(int x)
{
     if(x==n) return 1;
     if(x>n) return 0;
     int& ret = cache[x];
     if(ret != -1) return ret;
     return ret = (fill(x+1) + fill(x+2));
}
int solve()
{
     memset(cache, -1, sizeof(cache));
     int tmp = fill(0);
     tmp-=fill(n/2+1);
     if(n%2 ==0)
          tmp-=fill(n/2);
     return tmp%mod;
}