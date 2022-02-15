#include <iostream>
#include <vector>
#include <cstring>


using namespace std;



int main()
{
    int a[2][2]={{-1}};
    fill(a[0], a[0]+2*2, -1);
    

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

