#include <iostream>
#include <string>

using namespace std;



int fact(int n);
int nCr(int n, int r);

int main()
{
    
    int numCases;
    cin>>numCases;
    for(int i=0; i<numCases; i++){
        int n=0, m=0, k=0;
        cin>>n>>m>>k;
        string result = kth(n, m, k);
        cout<<result<<endl;
    }
    

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

string kth(int n, int m, int remain)
{
    

    if(remain < nCr(n+m-1, n-1))
        return "-" + kth(n-1, m, remain);
    return "o" + kth(n, m-1, remain - nCr(n+m-1, n-1));

    

}