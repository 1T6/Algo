#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> m;

    m.insert(make_pair(4,1));
    m.insert(make_pair(3,1));
    m.insert(make_pair(2,1));
    m.insert(make_pair(1,1));




    
    
    
    for(auto iter = m.begin(); iter != m.end(); iter++){
        cout<<iter->first<<" ";
    }


    return 0;
}