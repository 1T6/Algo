#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
//0은 그냥 최대 거리를 반환하고, 1은 mod로 나눈 몫을 구한다.
int cache[100][2];
int mod = 1000000007;

int solve();
int fill(int start);
int cal(pair<int, int> a, pair<int,int> b);


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
     int& ret1 = cache[x][0];
     int& ret2 = cache[x][1];
     if(ret1 != -1) return ret;

     ret1 = fill(x+1) + fill(x+2);
     

}