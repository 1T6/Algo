#include <iostream>
#include <limits>

using namespace std;


int main()
{
    const int a = numeric_limits<int>::max();
    cout<<a<<endl;
    return 0;
}
//2,147,483,647