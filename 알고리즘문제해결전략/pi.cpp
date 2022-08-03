#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
<<<<<<< HEAD
string N;
int cache[10000 ];
int INF =999999999;
int classify(int start, int num);
int solve(int x);
=======

int classify(int a, int b);
int solve(int start);
string N;
int cache[10000];
int INF = 987654321;

>>>>>>> 6dd2957367a0b9cb06a6586b5b8c480483feff6e
int main()
{
    
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        memset(cache, -1, sizeof(cache));
        cin>>N;
        results.push_back(solve(0));
    }
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    return 0;
}
int classify(int a, int b)
{
    string M = N.substr(a, b-a+1);
    if(M==string(M.size(), M[0])) return 1;
    bool progressive = true;
    for(int i=0; i<M.size()-1; i++){
        if(M[i+1]-M[i] != M[1] - M[0])
            progressive = false;
    }
    if(progressive && abs(M[1] - M[0])==1)
        return 2;
    bool alternating = true;
    for(int i=0; i<M.size(); i++)
        if(M[i]!=M[i%2])
            alternating = false;
    if(alternating) return 4;
    if(progressive) return 5;
    return 10;
}
int solve(int start)
{
    if(start == N.size()) return 0;
    int& ret = cache[start];
    if(ret != -1) return ret;

    ret = INF;
    for(int i=3; i<=5; i++){
        if(start+i<=N.size())
            ret = min(ret, solve(start+i)+classify(start,start+i-1));
    }
    return ret;
}