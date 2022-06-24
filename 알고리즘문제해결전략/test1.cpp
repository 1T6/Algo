#include <iostream>
#include <vector>

using namespace std;


void asdff(vector<int> &a);





int main()
{
    vector<int> v(10);

    asdff(v);
    return 0;

}

void asdff(vector<int> &a)
{
    for(auto it = a.begin(); it!= a.end(); it++){
        a[*it]+= 3;
    }
}