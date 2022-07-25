#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int cache[100][100], seq1[100], seq2[100];

int solve();
int check(int x, int y);
int main()
{   
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        cin>>n>>m;
        memset(cache, -1, sizeof(cache));
        for(int j=0; j<n; j++){
            cin>>seq1[j];
        }
        for(int j=0; j<m; j++){
            cin>>seq2[j];
        }
        results.push_back(solve());
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int solve()
{
    int ret =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ret = max(ret, check(i,j));
        }
    }
    return ret;
}

int check(int x, int y)
{
    int& ret = cache[x][y];
    if(ret != -1) return ret;

    ret = 2;
    
    int current = max(seq1[x], seq2[y]);
    
    for(int i=x+1; i<n; i++){
        if(current< seq1[i])
            ret = max(ret, check(i, y)+1);
    }
    
    for(int i=y+1; i<m; i++){
        if(current<seq2[i])
            ret = max(ret, check(x, i)+1);
    }

    return ret;
}