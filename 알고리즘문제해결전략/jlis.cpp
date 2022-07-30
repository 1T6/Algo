#include <iostream>
#include <vector>
#include <cstring>
#include <limits>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m;
int seq1[100], seq2[100];
int cache[101][101];

int solve(int x, int y);

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;

    for(int i=0; i<numCases; i++){
        memset(cache, -1, sizeof(cache));
        cin>>n>>m;
        for(int j=0; j<n; j++){
            cin>>seq1[j];
        }
        for(int j=0; j<m; j++){
            cin>>seq2[j];
        }
        results.push_back(solve(-1, -1));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    
    return 0;
}

int solve(int x, int y)
{
    int& ret = cache[x+1][y+1];
    if(ret != -1) return ret;

    ret = 0;
    long long a = (x == -1 ? NEGINF: seq1[x]);
    long long b = (y == -1 ? NEGINF: seq2[y]);
    long long tmp = max(a,b);

    for(int i = x+1; i<n; i++){
        if(tmp<seq1[i])
            ret = max(ret, solve(i,y)+1);
    }

    for(int i = y+1; i<m; i++){
        if(tmp<seq2[i])
            ret = max(ret, solve(x,i)+1);
    }

    return ret;
}