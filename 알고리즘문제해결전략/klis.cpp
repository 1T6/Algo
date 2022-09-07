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
void skipFind(int start, int rest, int lis, int current, vector<int>& klis);

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

        int res1 = lis(-1)-1;
        int res2 = count(-1);

        vector<int> answer;
        skipFind(0, k, res1, -1, answer);
        
        cout<<res1<<endl;
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

void skipFind(int start, int rest, int lis, int current, vector<int>& klis)
{
    if(lis==0) return;
    // key : seq, value : idx
    map<int, int> m;
    for(int i=start; i<n; i++){
        if(cache[i+1] == lis){
            m.insert(make_pair(seq[i], i));
        }   
    }
    for(auto i = m.begin(); i!= m.end(); i++){
        int idx = i->second;
        
        //범위 내에 없을때
        if(cntCache[idx+1] < rest && current < seq[idx]){
            rest -= cntCache[idx+1];
        }
        //범위내에 있을때
        else if(cntCache[idx+1] >= rest && current < seq[idx]){
            klis.push_back(seq[idx]);
            skipFind(idx+1, rest, lis-1, seq[idx], klis);
            break;
        }
    }
}


