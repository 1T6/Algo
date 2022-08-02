#include <iostream>
#include <vector>

using namespace std;

int N;
int S;
int seq[100];

int solve();
int sse();

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        cin>>N>>S;
        for(int j=0; j<N; j++){
            cin>>seq[j];
        }
        results.push_back(solve());
    }
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    return 0;
}

int solve()dfsdaf
{

}
int sse()
{

}

