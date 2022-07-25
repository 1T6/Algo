#include <iostream>
#include <cstring>

using namespace std;

int a[10];


int main()
{
    memset(a, -1, sizeof(int)*5);
    for(int i=0; i<10; i++){
        cout<<a[i]<<endl;
    }
    return 0;
}