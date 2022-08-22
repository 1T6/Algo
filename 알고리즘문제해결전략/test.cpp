#include <iostream>
#include <string>

using namespace std;

int main()
{
     string a  = " ";

     a += "asdf ";
     a = a.substr(0, a.size()-1);
     cout<<a<< a.size();
     

     return 0;

}