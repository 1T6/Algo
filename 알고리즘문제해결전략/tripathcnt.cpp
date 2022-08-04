#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int seq[5050];

int solve();

int main()
{   
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        cin>> n;
        for(int j=0; j < n*(n+1)/2; j++){
            cin>>seq[j];
        }
        results.push_back(solve());
    }
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

