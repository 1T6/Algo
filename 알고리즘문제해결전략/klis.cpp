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
        int res = lis(-1);
        
        solve();
    }
    return 0;
}







int lis(int x)
{
    int& ret = cache[x+1];
    if(ret != -1) return ret;

    int& ret1 = cntCache[x+1];

    ret = 0;

    for(int i=x+1; i<n; i++){
        if(x==-1||seq[x]<seq[i]){
            if(ret<lis(i)+1){
                ret = lis(i)+1;
                ret1 = 0;
            }
            else if(ret == lis(i)+1)
                ret1++;

        }
    }

    return ret;
}


void skipFind(int start, int skip, int lis, vector<int>& klis)
{
    
    
    //cache의 lis값 기준으로 오름차순 정렬이 되어있다. 
    map<int, int> targets;
    for(int i=start; i<n; i++){
        if(cache[i+1] == lis)
            
            targets.insert(cache[i+1], i);
    }
    
    map<int, int>::iterator iter = targets.begin();
    while(lis>0){
        lis-= iter->first;
    }

}