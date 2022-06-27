#include <iostream>
#include <string>
#include <vector>

using namespace std;

string flip(string::iterator& it);

int main()
{
    int numCases;
    cin>> numCases;
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
    char target = *it;
    it++;
    if(target == 'w' || target == 'b') 
    return string(1, target);

    string upperLeft = flip(it);
    string upperRight = flip(it);
    string lowerLeft = flip(it);
    string lowerLeft = flip(it);

    
}