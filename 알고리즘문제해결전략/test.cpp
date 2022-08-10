#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

int a[2];

int main()
{
    int& x = a[0];
    int& y = a[1];
    pair<int, int> p = make_pair(x,y);
    
    p.first = 1;
    cout<<p.first<<endl;
    cout<<a[0]<<endl;
}