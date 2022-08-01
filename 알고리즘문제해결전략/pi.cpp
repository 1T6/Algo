#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;


string N;
const int INF =999999;
int cache[10002];

int classify(int x, int y);
int memorize(int x);

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        memset(cache, -1, sizeof(cache));
        cin>>N;
        results.push_back(memorize(0));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int classify(int x, int y)
{
    string M = N.substr(x, y-x+1);
    if(M == string(M.size(), M[0])) return 1;

    bool progressive = true;
    for(int i=0; i<M.size()-1; i++){
        if(M[i+1]-M[i] != M[1]-M[0]) 
            progressive = false;
    }
    if(progressive && abs(M[1]-M[0])==1) return 2;
    bool alternating = true;
    for(int i=0; i<M.size(); i++){
        if(M[i] != M[i%2])
            alternating = true;
    }
    if(alternating) return 4;
    if(progressive) return 5; 
    return 10;
}

int memorize(int x)
{
    if(x==N.size()) return 0;
    
    int& ret = cache[x];
    if(ret!= -1) return ret;
    ret = INF;
    for(int i = 3; i<=5; i++){
        if(x+i <= N.size())
            ret = min(ret, memorize(x+i)+classify(x, x+i-1));
    }
    return ret;
}