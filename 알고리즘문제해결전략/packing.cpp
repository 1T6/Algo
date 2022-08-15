#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, w;

int need[100], volume[100], index[100];
int INF = 987654321;

void solve(vector<string> list);
int calc();

int main()
{
     int numCases;
     cin>>numCases;
     for(int i=0; i<numCases; i++){
          cin>> n>>w;
          vector<string> list;
          
          for(int j=0; j<n; j++){
               string tmp;
               cin>>tmp;
               list.push_back(tmp);
          }


          solve(list);

     }

     return 0;
}

