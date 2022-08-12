#include <iostream>
#include <limits>


using namespace std;

int main()
{
    cout<<numeric_limits<char>::max()<<endl;
    cout<<numeric_limits<short>::max()<<endl;
    cout<<numeric_limits<int>::max()<<endl;
    cout<<numeric_limits<long>::max()<<endl;
    cout<<numeric_limits<long long>::max()<<endl;
    cout<<fixed<<endl;
    cout<<numeric_limits<long double>::max()<<endl;
    

    return 0;
}