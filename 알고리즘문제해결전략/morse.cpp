#include <iostream>
#include <vector>
#include <string>


using namespace std;


int n, m, k;

void solve();


int fact(int n);
int nCr(int n, int r);



int main()
{
    int numCases;
    cin>>numCases;
    for(int i=0; i<numCases; i++){
        cin>>n>>m>>k;
        solve();
    }

    return 0;
}

int fact(int n)
{
    if(n ==0) 
        return 1;
    int res = 1;
    for(int i=2; i<=n; i++){
        res*=i;
    }
    return res;
}
int nCr(int n, int r)
{
    return fact(n) / (fact(r)* fact(n-r));
}

int solve()
{
    int skip = 0;
    int left = 0;
    for(int i=0; i<n; i++){
        int comb =nCr(m+i+1, i)
        if(k>comb){
            skip = i;
            left = k-comb;
            break;
        }
    }
}