#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int path[100][100];
int n;

//하나는 최대경로를 저장하고 하나는 
int cache[100][100][2];


int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        memset(cache, -1, sizeof(cache));
        cin>>n;
        for(int j=0; j<n; j++){
            for(int k=0; k<=j; k++){
                cin>>path[j][k];
            }
        }
        results.push_back(solve());
    }
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int solve(int y, int x)
{
    
}