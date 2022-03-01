#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string::iterator& it);

int main()
{
    int numCases;
    
    vector<string> results;


    cin>>numCases;

    for(int i=0; i<numCases; i++){
        string s;
        cin >> s;
        string::iterator it = s.begin();
        results.push_back(reverse(it));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
        
    return 0;
}


string reverse(string::iterator& it)
{   
    char target = *it;
    it++;
    //BASE CASE
    if(target == 'w' || target=='b') return string(1, target);

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x")+lowerLeft+lowerRight+upperLeft+upperRight;
}
