#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string N;
int cache[10000 ];
int INF =999999999;

int classify(int start, int num);
int solve(int x);

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        memset(cache, -1, sizeof(cache));
        cin>> N;
        results.push_back(solve(0));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}
// x부터 y개의 숫자
int classify(int start, int num)
{
    string M = N.substr(start, num);
    if(M == string(num, M[0])) return 1;
    bool progressive = true;
    for(int i=1; i<M.size()-1; i++){
        if(M[i+1]-M[i] != M[1] - M[0])
            progressive = false;
    }
    if(progressive && abs(M[1]-M[0] == 1)) return 2;
    bool alternating = true;
    for(int i=0; i<M.size(); i++){
        if(M[i]!= M[i%2])
            alternating=false;
    }
    if(alternating) return 4;
    if(progressive) return 5;
    return 10;
}
int solve(int start)
{
    if(start == N.size()-3) return 0;
    int& ret = cache[start];
    if(ret != -1) return ret;

    ret = INF;

    for(int chunk=3; chunk<=5; chunk++){
        if(start+chunk < N.size())
            ret = min(ret, solve(start+chunk) + classify(start, chunk));
    }

    return ret;
}

