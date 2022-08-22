#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int m, q;
vector<string> words;
double B[500];
double T[500][500];
double M[500][500];
double cache[500][500];

int choices[500];
int n;
string line;
double maxProb(int target, int before);

string solve();
int main()
{
     //입력
     cin>>m>>q;
     for(int i=0; i<m; i++){
          string tmp;
          cin>>tmp;
          words.push_back(tmp);
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

     //테스트
     for(int i=0; i<q; i++){
          cin>>n;
          cin>>line;
          cout<<solve();
     }

     return 0;
}

double maxProb(int target, int before)
{
     if(target == n) return 1;
     
     double& ret = cache[target][before];
     if(ret > -0.5) return ret;

     ret = 0;
     int best =-1;

     for(int i=0; i<m; i++){
          double cand;
          if(target ==0){
               cand = maxProb(target+1, i) * M[i][target] * B[i];
          }
          else{
               cand = maxProb(target+1, i) * M[i][target] * T[before][i];
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
     double tmp = maxProb(0,0);

     string ret = "";
     for(int i=0; i<n; i++){
          ret += words[i]+ " ";
     }

     return ret = ret.substr(0, ret.size()-1);
}