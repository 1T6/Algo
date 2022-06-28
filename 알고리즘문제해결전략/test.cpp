#include <iostream>
#include <vector>


using namespace std;


int get_size(vector<int>& fence);

int N;

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;

    for(int i=0; i<numCases; i++){
        cin>>N;
        vector<int> fence;
        for(int j=0; j<N; j++){
            int tmp;
            cin>>tmp;
            fence.push_back(tmp);
        }
        results.push_back(get_size(fence));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int get_size(vector<int>& fence)
{
    
}