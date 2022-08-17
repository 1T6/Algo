<<<<<<< HEAD
=======
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, w;
int need[100], volume[100];
int cache[1000][101];
int choices[101];

int pack(int rest, int item);
int solve();

int main()
{
     cin>>n>>w;
     vector<string> items;
     for(int i=0; i<n; i++){
          string tmp;
          cin>>tmp>>volume[i]>>need[i];
          items.push_back(tmp);
     }

     memset(cache, -1, sizeof(cache));
     memset(choices, -1, sizeof(choices));

     cout<<solve()<<endl;


     return 0;
}
//rest남았을때 item을 고르면 얻을 수 있는 최대 need
//base case는 애초에 불가능하면 호출을 하지 않을것이기 때문에 따로 명시하지 않아도 될듯.
int pack(int rest, int item)
{
     cout<<rest<<" "<<item<<endl;
     int& ret = cache[rest][item];
     if(ret != -1) return ret;
     ret =0;
     for(int next = item+1; next<n; next++){
          if(rest>=volume[next]){
               int cand = pack(rest-volume[item], next) + need[item];
               if(cand > ret){
                    ret = cand;
               }
          }
     }
     return ret;
}
int solve()
{    

     cout<<pack(w,0)<<endl;
     /*
     int ret= 0;
     for(int i=0; i<n; i++){
          int tmp = pack(w, i);
          cout<<tmp<<endl;
          ret = max(ret, tmp);
     }
     return ret;
     */
}
>>>>>>> master
