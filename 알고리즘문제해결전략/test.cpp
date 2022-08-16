#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, w;

int main()
{
     cin>>n>>w;
     vector<string> items;
     for(int i=0; i<n; i++){
          string tmp;
          int a, b;
          cin>>tmp>>a>>b;
          items.push_back(tmp);
     }
     cout<<"finished"<<endl;
     return 0;
}