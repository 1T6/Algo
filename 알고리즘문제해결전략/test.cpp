#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool inRange(int y, int x);
bool jump(int y, int x);
string solve();

int map[100][100];
int n;

int main()
{   
    int numCases;
    cin>>numCases;
    vector<string> results;
    for(int i=0; i<numCases; i++){
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

bool inRange(int y, int x)
{
    return (y>=0 && x>=0 && y<n && x<n);
}

bool jump(int y, int x)
{
    //BASE CASE
    if(!inRange(y,x)) return false;
    if(y==n-1 && x== n-1) return true;

    int mov = map[y][x];
    
    return jump(y+mov, x) || jump(y,x+mov);
}

string solve()
{
    bool ret = jump(0,0);
    if(ret == false) return "NO";
    else return "Yes";
}
