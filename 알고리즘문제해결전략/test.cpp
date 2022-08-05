#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


double a[10][10];

int main()
{
    memset(a, -1, sizeof(a));
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<isnan(a[0][0])<<endl;
    return 0;
}