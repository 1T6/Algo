#include <iostream>
#include <vector>
#include <string>

using namespace std;

void match(string::iterator& itW, string::iterator& itT);

string wildCard;
string target;
int n;
bool finished = false;

int main()
{
    int numCases;
    cin>>numCases;
    vector<string> results;
    for(int i=0; i<numCases; i++){
        cin>>wildCard>>n;
        for(int j=0; j<n; j++){
            cin>>target;
            string::iterator itW = wildCard.begin();
            string::iterator itT = target.begin();
            
            
        }
    }
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}
void match(string::iterator& itW, string::iterator& itT)
{
    //BASE CASE
    if(itW==wildCard.end() && itT == target.end()){
        finished = true;
        return;
    }

    char current = *itW;
    
    if(current == '*'){

    }
    else if(current  == '?'){
        itW++;
        itT++;
        match(itW, itT);
    }
    else{

    }

    
}