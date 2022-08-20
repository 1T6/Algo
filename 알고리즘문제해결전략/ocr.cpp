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

int n;

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
          vector<string> target;
          for(int j=0; j<n; j++){
               string tmp;
               cin>>tmp;
          }
          solve();
     }

     return 0;
}

