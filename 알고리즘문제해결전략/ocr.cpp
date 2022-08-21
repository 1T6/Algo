#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int m, q;
vector<string> words;
int B[500];
int T[500][500];
int M[500][500];

int cache[500][500];

int n;
string line;

int maxProb(int target, int before);

int main()
{
     //입력
     cin>>m>>q;
     for(int i=0; i<m; i++){
          string tmp;
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

int maxProb(int target, int before)
{
     if(target == n) return 1;
     
     int& ret = cache[target][before];
     if(ret != -1) return ret;

     ret = 1;


}