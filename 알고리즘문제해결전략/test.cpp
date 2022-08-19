#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


string a[10];

int main()
{
     memset(a, -1, sizeof(a));
     for(int i=0; i<10; i++){
          
          cout<<a[i]<<endl;
     }
     return 0;
}