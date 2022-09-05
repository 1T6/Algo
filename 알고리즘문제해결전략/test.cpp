#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, k;

int seq[500];

//x+1 시점부터의 lis를 저장, x+1시점 부터의 lis 개수를 저장
int cache[501], cntCache[501];

int lis(int x);
int count(int x);

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>seq[i];
    }

    memset(cache, -1, sizeof(cache));
    memset(cntCache, -1, sizeof(cntCache));
    
    int res = lis(-1);
    int ret = count(-1);
    cout<<res<<endl;
    cout<<ret<<endl;
    for(int i=0; i<=n; i++){
        cout<<cache[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<=n; i++){
        cout<<cntCache[i]<<" ";
    }
    cout<<endl;
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
    

    for(int i= x+1; i<n; i++){
        if(x==-1 || (seq[x]<seq[i] && cache[x+1]-1 == cache[i+1])){
            ret += count(i);
        }
    }

    return ret;
}