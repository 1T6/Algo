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
        for(int i=0; i<=n; i++){
            cout<<cache[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<=n; i++){
            cout<<cntCache[i]<<" ";
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
