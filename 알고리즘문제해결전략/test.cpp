#include <iostream>
#include <vector>
#include <string>

using namespace std;

string flip(string::iterator& it);

int main()
{
    int numCases;
    cin>>numCases;
    vector<string> results;

    for(int i=0; i<numCases; i++){
        string str;
        cin>>str;
        string::iterator it = str.begin();
        results.push_back(flip(it));
    }
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    return 0;
}

string flip(string::iterator& it)
{
    
}