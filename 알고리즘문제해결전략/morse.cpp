#include <iostream>
#include <vector>

using namespace std;

int n,m,k;

int fact(int n);
int nCr(int n, int r);

int main()
{
    /*
    int numCases;
    cin>>numCases;
    for(int i=0; i<numCases; i++){
        cin>>n>>m>>k;
        solve();
    }
    */

    return 0;
}

int fact(int n)
{
    int ret =1;
    while(n>1){
        ret*=n;
        n--;
    }
    return ret;
}

int nCr(int n, int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}

string kth(int n, int m, int skip)
{

}