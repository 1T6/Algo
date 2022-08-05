#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cache[100][100];
int cntCache[100][100];
int map[100][100];

int path(int y, int x);
int cnt(int y, int x);

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        memset(cache, -1, sizeof(cache));
        memset(cntCache, -1, sizeof(cntCache));
        cin>>n;
        for(int j=0; j<n; j++){
            for(int k=0; k<=j; k++){
                cin>>map[j][k];
            }
        }
        results.push_back(cnt(0,0));
    }
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    return 0;
}

int path(int y, int x)
{
    if(y==n) return 0;
    int& ret = cache[y][x];
    if(ret != -1) return ret;

    ret = map[y][x] + max(path(y+1, x), path(y+1, x+1));

    return ret;
}

int cnt(int y, int x)
{
    if(y==n-1) return 1;
    int& ret = cntCache[y][x];
    if(ret != -1) return ret;
    ret=0;
    if(path(y+1, x) >= path(y+1, x+1)) ret += cnt(y+1,x);
    if(path(y+1, x) <= path(y+1, x+1)) ret += cnt(y+1, x+1);

    return ret;
}