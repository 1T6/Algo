#include <iostream>

using namespace std;


void print(const int& a);
void print1(const int a);
int main()
{  
    int a=10;
    print(a);
    print1(a);
    return 0;
}
void print(const int& a)
{   
    
    cout<<a<<endl;
    cout<<&a<<endl;
}
void print1(const int a)
{   
    
    cout<<a<<endl;
    cout<<&a<<endl;
}
