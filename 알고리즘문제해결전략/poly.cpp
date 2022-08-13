#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cache[100][100];
int mod = 10000000;

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

    ret = 0;
    for(int i=1; i<=rest-first; i++){
        int add = i+first-1;
        add*=cnt(rest-first, i);
        add%=mod;
        ret+=add;
        ret%=mod;
    }
    return ret;
}

int solve()
{
    memset(cache, -1, sizeof(cache));
    int ret = 0;
    for(int i=1; i<=n; i++){
        ret+=cnt(n, i);
        ret %= mod;
    }
    return ret;
}