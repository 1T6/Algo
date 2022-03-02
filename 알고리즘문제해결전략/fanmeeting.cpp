#include <iostream>
#include <string>
#include <vector>


using namespace std;

int countHug(string mem, string fan);

string mem;
string fan;

int main()
{

    int numCases=0;
    cin>>numCases;
    vector<int> results;
    
    for(int i=0; i<numCases; i++){
        cin>> mem>>fan;

        results.push_back(countHug(mem, fan));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

        return 0;
}
int countHug(string mem, string fan)
{
     
}