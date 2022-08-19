#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, w;
int volume[100], need[100];
int cache[1000][100];
string name[100];


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
               cin>>name[j]>>volume[j]>>need[j];
          }
          int result = pack(w,0);
          vector<string> picked;
          getPicked(w, 0, picked);



          cout<<result<<" "<< picked.size();
          for(int j=0; j<n; j++){
               cout<<picked[j]<<endl;
          }
     }
     return 0;
}


int pack(int rest, int item)
{

}
void getPicked(int rest, int item, vector<string>& picked)
{

}