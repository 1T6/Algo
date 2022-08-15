#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, w;

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
     }

     return 0;
}