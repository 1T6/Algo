#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int fact(int n);
int nCr(int n, int r);


int main()
{

    cout<<nCr(5,3);
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