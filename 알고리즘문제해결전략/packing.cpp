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
void solve(vector<string> items);
void makeList(vector<string>& seq, const vector<string>& items);
int main()
{
    int numCases;
    cin>>numCases;
    for(int i=0; i<numCases; i++){
        cin>>n>>w;
        vector<string> items;
        for(int j=0; j<n; j++){
            string tmp;
            cin>>tmp>>volume[j]>>need[j];
            items.push_back(tmp);
        }

        solve(items);                       
    }
    return 0;
}
 
void solve(vector<string> items)
{
    memset(cache, -1, sizeof(cache));
    memset(choices, -1, sizeof(choices));
    int result = pack(n, -1);
    vector<string> seq;
    makeList(seq, items);
    
    cout<< result<<" " <<seq.size()<<endl;
    for(int i=0; i<seq.size();i++){
        cout<<seq[i]<<endl;
    }
}

//현재 남은 공간에서 item을 선택함. 반환은 최대 need를 반환한다.
int pack(int rest, int item)
{
    int& ret = cache[rest][item+1];
    if(ret != -1) return ret;
    ret =0;
    int bestNext =-1;
    int nextRest = rest - volume[item+1];
    for(int next = item+1; next<n; next++){
        if(nextRest>volume[next]){
            int tmp = pack(nextRest, next)+volume[item+1];
            if(tmp>ret){
                ret = tmp;
                bestNext = next;
            }
        }
    }
    choices[item+1] = bestNext;

    return ret;
}

void makeList(vector<string>& seq, const vector<string>& items)
{
    for(int i=0; i<n; i++){
        if(choices[i] == -1)
            break;
        else
            seq.push_back(items[choices[i]]);
    }
    
}