#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int bino[201][201];

void calcBino();
string kth(int n,int m,int k);


int M = 1000000000+10;

int main()
{
    int numCases;
    cin>>numCases;
    calcBino();
    for(int i=0; i<numCases; i++){
        int n, m, k;
        cin>>n>>m>>k;
        string result = kth(n, m, k);
        cout<<result<<endl;
    }

    return 0;
}

void calcBino()
{
    memset(bino, 0, sizeof(bino));
    for(int i=0; i<=200; i++){
        bino[i][0] = bino[i][i] = 1;
        for(int j=1; j<i; j++){
            bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
        }
    }
}

string kth(int n, int m, int remain)
{
    if(n==0) return string(m, 'o');

    if(remain <= bino[n+m-1][n-1])
        return "-" + kth(n-1, m, remain);
    return "o" + kth(n, m-1, remain - bino[n+m-1][n-1]);
}