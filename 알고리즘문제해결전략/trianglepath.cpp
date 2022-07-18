#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int n;
int map[101][101];
int cache[101][101];

int solve(int y, int x);

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
                cin>>map[j][k];
            }
        }

        results.push_back(solve(0,0));
    }

    for(int i=0; i<n; i++){
        cout<< results[i]<<endl;
    }
    return 0;
}

int solve(int y, int x)
{
    
}
