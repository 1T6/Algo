#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int map[100][100];
int cache[100][100];
int n;

string solve();
int jump(int y, int x);

int main()
{   
    int numCases;
    cin>>numCases;
    vector<string> results;
    for(int i=0; i<numCases; i++){
        memset(cache, -1, sizeof(cache));
        cin>>n;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cin>>map[j][k];
            }
        }

        results.push_back(solve());
    }    

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

string solve()
{
    int ret = jump(0,0);
    if (ret == 1) return "YES";
    else return "NO";
}
int jump(int y, int x)
{
    //BASE CASE
    if(y>=n || x>=n) return 0;
    if(y==n-1 && x== n-1) return 1;

    int& ret = cache[y][x];
    if(ret != -1) return ret;

    int mov = map[y][x];

    return ret = jump(y+mov, x)||jump(y,x+mov);
}