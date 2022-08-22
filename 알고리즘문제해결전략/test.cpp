#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, int> strToIdx;
map<int, string> idxToStr;

int m, q;
double B[500], M[500][500], T[500][500];

int n;
string words[500];

double cache[500][500];
int choices[100];

double maxProb(int target, int before);
string solve();

int main()
{
    cin>>m>>q;
    for(int i=0; i<m; i++){
        string tmp;
        cin>>tmp;
        strToIdx.insert(pair<string, int>(tmp,i));
        idxToStr.insert(pair<int, string>(i, tmp));
    }
    for(int i=0; i<m; i++){
        cin>>B[i];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin>>T[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin>>M[i][j];
        }
    }
    for(int i=0; i<q; i++){
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>words[j];
        }

        cout<<solve()<<endl;
    }
    return 0;
}

double maxProb(int target, int before)
{
    if(target == n) return 1;
    double& ret = cache[target][before];
    if(ret> -0.5) return ret;
    
    ret = -1;
    int best = -1;

    for(int i=0; i<m; i++){
        double cand=0;
        if(target == 0){
            cand = maxProb(target+1, i) + M[i][strToIdx[words[target]]] + B[i];
        }         
        else{
            cand = maxProb(target+1, i) + M[i][strToIdx[words[target]]] + T[before][i];
        }

        if(cand>ret){
           ret = cand;
           best = i;
        }
    }

    choices[target] = best;
    return ret;
}

string solve()
{
    fill(&cache[0][0], &cache[499][500], -1);
    double res = maxProb(0, 0);

    string ret;
    for(int i=0; i<n; i++){
        ret+= idxToStr[choices[i]] + " ";
    }
    
    return ret.substr(0, ret.size()-1);
}