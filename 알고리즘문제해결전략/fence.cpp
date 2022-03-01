#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bruteForce(const vector<int>& boards);

int main()
{
    int numCases=0;
    vector<int> results;

    cin>>numCases;

    for(int i=0; i<numCases; i++){
        int numBoards = 0;
        vector<int> boards;
        cin>>numBoards;
        for(int j=0; j<numBoards; j++){
            int tmp=0;            
            cin>>tmp;
            boards.push_back(tmp);
        }

        results.push_back(bruteForce(boards));        
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int bruteForce(const vector<int>& boards)
{
    int ret =0;
    int N = boards.size();

    for(int i=0; i<N; i++){
        int minHeight = boards[i];
        for(int j=i; j<N;j++){
            minHeight= min(minHeight, boards[j]);
            ret = max(ret, (j-i+1)*minHeight);
        }
    }
    return ret;
}