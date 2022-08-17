#include <vector>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int n,w;
int need[100], volume[100];
int cache[1000][100];

int pack(int rest, int item);

int main()
{
     cin>>n>>w;
     vector<string> items;
     for(int i=0; i<n; i++){
          string tmp;
          cin>> tmp >> volume[i]>> need[i];
          items.push_back(tmp);
     }
     


     return 0;
}

int pack(int rest, int item)
{
     int& ret = cache[rest][item];
     if(ret != -1) return ret;
}