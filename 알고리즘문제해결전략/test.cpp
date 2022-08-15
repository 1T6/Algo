#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main()
{
     int a[] = {1,2,3,4,5,6,7};

     for(auto number : a){
          cout<<number<<endl; 
     }
}