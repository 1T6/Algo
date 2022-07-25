#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int seq[500], cache[500];

int check(int start);
int solve();
int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        cin>>n;
        memset(cache, -1, sizeof(cache));
        for(int j=0; j<n; j++){
            cin>>seq[j];
        }
        results.push_back(solve());
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int solve()
{
    int ret =0;
    for(int i=0; i<n; i++){
        ret = max(check(i), ret);
    }
    return ret;
}
int check(int start)
{
    int& ret = cache[start];
    if(ret != -1) return ret;

    ret = 1;
    for(int i=start+1; i<n; i++){
        if(seq[start]<=seq[i])
            ret = max(ret, check(i)+1);
    }
    return ret;
}