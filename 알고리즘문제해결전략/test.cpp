#include <iostream>
#include <map>

using namespace std;

int main()
{
     map<string, int> map;
     string tmp ="sdf";
     map.insert(pair<string, int>(tmp,1));
     cout<<map[tmp];
     return 0;
}