#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int numCases;
    cin>>numCases;
    for(int i=0; i<numCases; i++){
        
    }
    return 0;
}



int pack(int rest, int item)
{   
    rest -= need[item];
    ret =0;
    best = -1;
    for(int next=rest+1; next<n; next++){
        if(rest > need[next]){
            int tmp = pack(rest, next);
            if(tmp > ret){
                best = next;
                ret = tmp;
            }
        }
    }
    choice[item] = best;
    return ret;
}