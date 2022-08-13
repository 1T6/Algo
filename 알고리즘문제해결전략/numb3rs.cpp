#include <iostream>
#include <vector>

using namespace std;

int n, d, p;
int A[50][50];
int t;
vector<int> target;



int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        cin>>n>>d>>p;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cin>>A[j][k];
            }
        }

        cin>>t;
        vector<int> target;
        for(int j=0; j<t; j++){
            int tmp;
            cin>>tmp;
            target.push_back(tmp);
        }
    }
    

    return 0;
}

double prob(int days, int target)
{
    
}

