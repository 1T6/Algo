#include <iostream>
#include <vector>
#include <string>

using namespace std;

string flip(string::iterator& it);

int main()
{
    int numCases=0;
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
    char head = *it;
    it++;
    //BASE CASE
    if(head == 'w' || head =='b')
        return string(1, head);
    
    string upperLeft = flip(it);
    string upperRight = flip(it);
    string lowerLeft = flip(it);
    string lowerRight = flip(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}