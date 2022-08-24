#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits>

using namespace std;

int m, q;

map<string, int> strToIdx;
map<int, string> idxToStr;


double B[500];
double T[500][500];
double M[500][500];


int n;

string words[100];

double cache[100][500];

int choice[100][500];



void solve();
double maxProb(int target, int before);



int main()
{
    cin>>m>>q;

    for(int i=0; i<m; i++){
        string tmp;
        cin>>tmp;
        strToIdx.insert(pair<string, int>(tmp, i));
        idxToStr.insert(pair<int, string>(i, tmp));
    }
    for(int i=0; i<m; i++){
        double tmp;
        cin>>tmp;
        tmp = log(tmp);
        B[i] = tmp;
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
                double tmp;
                cin>>tmp;
                tmp = log(tmp);
                T[i][j] = tmp;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
                double tmp;
                cin>>tmp;
                tmp = log(tmp);
                M[i][j] = tmp;
        }
    }

    for(int i=0; i<q; i++){
          cin>>n;
          for(int j=0; j<n; j++){
               cin>>words[j];
          }
          solve();
    }

    return 0;
}

double maxProb(int target, int before)
{
     if(target == n) return 0;
     double& ret = cache[target][before];
     if(ret > -0.5) return ret;

     ret = numeric_limits<double>::lowest();
     
     int& choose = choice[target][before];

     for(int i=0; i<m ; i++){
          double cand;
          if(target ==0){
               cand = B[i] + M[i][strToIdx[words[target]]] + maxProb(target+1, i);
          }
          else{
               cand = T[before][i] + M[i][strToIdx[words[target]]] + maxProb(target+1, i);
          }
          if(cand > ret){
               ret = cand;
               choose = i;    
          }
     }
     return ret;
}

void solve()
{
     fill(&cache[0][0], & cache[99][500], -1);
     double tmp = maxProb(a);

     
}


