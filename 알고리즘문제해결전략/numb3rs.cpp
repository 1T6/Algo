#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, p;
int A[50][50];
int degree[50];
double cache[100][50];

double prob(int days, int target);
vector<double> solve(vector<int> targets);
void cntTargets();

int main()
{
    int numCases;
    cin>>numCases;
    vector<vector<double>> results;
    for(int i=0; i<numCases; i++){
        vector<double> result;
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
        result = solve(targets);
        results.push_back(result);
    }

    cout.precision(8);
    cout<<fixed;
    for(int i=0; i<numCases; i++){
        for(int j=0; j<results[i].size(); j++){
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
double prob(int days, int target)
{
    if(days == 0 && target == p) return 1;
    if(days == 0 && target != p) return 0;
    double& ret = cache[days][target];
    if(ret > -0.5) return ret;

    ret =0;

    for(int i=0; i<n; i++){
        if(A[target][i]){
            ret += prob(days-1, i) * 1/degree[i];
        }
    }
    return ret;
}
vector<double> solve(vector<int> targets)
{
    fill(&cache[0][0], &cache[99][50], -1);
    cntTargets();
    vector<double> ret;
    for(int i=0; i<targets.size(); i++){
        ret.push_back(prob(d,targets[i]));
    }
    return ret;
}
void cntTargets()
{
    for(int i=0; i<n; i++){
        int tmp=0;
        for(int j=0; j<n; j++){
            if(A[i][j]) 
                tmp++;
        }
        degree[i] = tmp;
    }
}