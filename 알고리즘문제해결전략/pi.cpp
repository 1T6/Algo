#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;



int seq[10000];
int cache[10000];

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;

    for(int i=0; i<numCases;i++){
        string tmp;
        cin>> tmp;
        memset(cache, -1, cache);
        for(int j=0; j<tmp.length(); j++){
            seq[j] = tmp[j];
        }
        results.push_back(solve());
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int solve(int x)
{
    
}