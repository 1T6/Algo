#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int solve(int x);

int cache[500], seq[500];
int n;

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){ 
        cin>>n;
        memset(cache, -1, sizeof(int)* n);
        for(int j=0; j<n; j++){
            cin>>seq[j];
        }
        results.push_back(solve(0));
    }
    
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}


int solve(int x)
{
    
}