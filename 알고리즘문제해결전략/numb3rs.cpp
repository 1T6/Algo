#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, p;
int A[50][50];
double cache[100][50];

double prob(int day, int target);
vector<double> solve(vector<int> targets);

int main()
{
    int numCases;
    cin>>numCases;
    for(int i=0; i<numCases; i++){

        vector<double> results;

        cin>>n>>d>>p;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cin>>A[j][k];
            }
        }

        int t;
        cin>>t;
        vector<int> targets;
        for(int j=0; j<t; j++){
            int tmp;
            cin>>tmp;
            targets.push_back(tmp);
        }

        results = solve(targets);

        cout.precision(7);  
        for(int j=0; j<t; j++){
            cout<<results[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
double prob(int day, int target)
{
    if(day==-1 && target==p) return 1;
    else if(day==-1 && target != p) return 0;
    double& ret = cache[day][target];
    if(ret != -1) return ret;

    ret =0;
    for(int i=0; i<n; i++){
        
        if(A[target][i]){
            ret+= prob(day-1, i)*1/5;
        }
    }

    return ret;
}




vector<double> solve(vector<int> targets)
{
    fill(&cache[0][0], &cache[99][50], -1);
    
    vector<double> ret;
    for(int i=0; i<targets.size(); i++){
        cout<<prob(d,targets[i])<<endl;
        ret.push_back(prob(d, targets[i]));
    }

    return ret;
}