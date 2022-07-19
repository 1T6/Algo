#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int map[101][101];
int cache[101][101];

int solve(int y, int x);
bool inRange(int y, int x);

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

    for(int i=0; i<numCases; i++){
        cout<< results[i]<<endl;
    }
    return 0;
}
int solve(int y, int x)
{   
    if(!inRange(y,x)) return 0;

    int& ret = cache[y][x];
    if(ret != -1) return ret;

    int currentWeight = map[y][x];
    int belowPath = solve(y+1,x);
    int belowRightPath = solve(y+1, x+1);
    
    return ret = currentWeight + max(belowPath, belowRightPath);
}

bool inRange(int y, int x)
{
    return (y<n && x<n && x<=y);
}