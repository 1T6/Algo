#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, w;
int volume[100], need[100];
int cache[1000][100];
string items[100];

int pack(int rest, int item);
void getPicked(int rest, int item, vector<string>& picked);

int main()
{
     int numCases;
     cin>>numCases;
     for(int i=0; i<numCases; i++){
          memset(cache, -1, sizeof(cache));
          cin>>n>>w;
          for(int j=0; j<n; j++){
               cin>>items[j]>>volume[j]>>need[j];
          }
          int result = pack(w,0);
          vector<string> picked;
          getPicked(w, 0, picked);

          cout<<result<<" "<< picked.size()<<endl;
          for(int j=0; j<picked.size(); j++){
               cout<<picked[j]<<endl;
          }
     }
     return 0;
}

int pack(int rest, int item)
{
     if(item == n) return 0;
     int& ret = cache[rest][item];
     if(ret != -1) return ret;

     ret = pack(rest, item+1);
     if(rest>=volume[item])
          ret = max(ret, pack(rest-volume[item], item+1)+need[item]);
     
     return ret;
}

void getPicked(int rest, int item, vector<string>& picked)
{
     if(item == n) return;
     if(pack(rest, item) == pack(rest, item+1)){
          getPicked(rest, item+1, picked);
     }
     else{
          picked.push_back(items[item]);
          getPicked(rest-volume[item], item+1, picked);
     }
}