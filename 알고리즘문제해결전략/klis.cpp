#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int n, k;

int seq[500];
int cache[501], cntCache[501];

int lis(int x);
int count(int x);
void skipFind(int start, int skip, int lis, vector<int>& klis);

int main()
{
    int c;
    cin>>c;
    for(int i=0; i<c; i++){
        cin>>n>>k;
        for(int j=0; j<n; j++){
            cin>>seq[j];
        }
        memset(cache, -1, sizeof(cache));
        memset(cntCache, -1, sizeof(cntCache));

        int res1 = lis(-1);
        int res2 = count(-1);

        vector<int> answer;
        skipFind(0, k, res1, answer);
        
        for(auto x: answer){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
int lis(int x)
{
    int& ret = cache[x+1];
    if(ret != -1) return ret;
    ret = 1;
    for(int i=x+1; i<n; i++){
        
        if(x==-1 || seq[x]<seq[i]){
            ret = max(ret, lis(i)+1);

        }
    }
    return ret;
}
int count(int x)
{   
    int& ret = cntCache[x+1];
    if(ret != -1) return ret;
    if(cache[x+1] ==1){
        ret = 1;
        return ret;
    }
    ret =0;
    for(int i = x+1; i<n; i++){
        if(x==-1 || (seq[x]<seq[i] && cache[x+1]==cache[i+1]+1)){
            ret +=count(i);
        }
    }
    return ret;
}

void skipFind(int start, int skip, int lis, vector<int>& kils)
{
    map<int, int> targets;
    
}





void skipFind(int start, int skip, int lis, vector<int>& klis)
{
    //cntCache의 lis값 기준으로 오름차순 정렬이 되어있다. 
    map<int, int> targets;
    for(int i=start; i<n; i++){
        if(cache[i+1] == lis)
            targets.insert(make_pair(cntCache[i+1], i));
    }
    if(targets.empty())
        return;
    map<int, int>::iterator iter = targets.begin();
    int idx=0;
    while(lis>0){
        lis-= iter->first;
        idx++;
    }
    iter--;
    lis += iter->first;
    idx -=1;
    klis.push_back(seq[idx]);
    skipFind(idx, lis, cache[idx+1], klis);
}
