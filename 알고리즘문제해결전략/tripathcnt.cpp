#include <iostream>
#include <cstring>

using namespace std;

int cache[100][100];
int map[100][100];
int n;
int cacheCnt[100][100];

int path(int y, int x);

int main()
{
    cin>>n;
    memset(cache, -1, sizeof(cache));
    memset(cacheCnt, -1, sizeof(cacheCnt));
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin>>map[i][j];
        }
    }
    cout<<path(0,0)<<endl;
    return 0;
}

int path(int y, int x)
{
    if(y>=n || x>=y+1) return 0;
    int& ret = cache[y][x];
    if(ret != -1) return ret;

    ret = map[y][x]+max(path(y+1, x),path(y+1, x+1));
    
    return ret;
}
int count(int y, int x)
{
    if(y>=n || x>=y+1) return 0;
    int& ret = cacheCnt[y][x];
    if(ret!= -1) return ret;

    ret = count(y+1, x) + count(y+1, x+1);
    return ret;
}