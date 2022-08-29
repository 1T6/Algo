#include <iostream>


using namespace std;

int fact(int n);
int nCr(int n, int r);

int main()
{   
    cout<<fact(100);
    

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