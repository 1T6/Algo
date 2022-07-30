#include <iostream>
#include <cstring>

using namespace std;

int cache[10][10];

int main()
{
    memset(cache, -1, sizeof(cache[0])*5);
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout<<cache[i][j];
        }
        cout<<endl;
    }

    return 0;
}