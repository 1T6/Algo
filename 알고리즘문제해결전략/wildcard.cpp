#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool match(string::iterator& itW, string::iterator& itT);

string wildCard;
string target;
int N;

int main()
{
    return 0;
}

bool match(string::iterator& itW, string::iterator& itT);
{
    //BASE CASE
    if(itW == wildCard.end() && itT == target.end()) return true;
    
    if(*itW =='*'){
        
    }
    else if(*itW =='?'){
        itW++;
        itT++;
        match(itW, itT);
    }
    //일반 문자인 경우   
    else{
        if(*itW == *itT){
            itW++;
            itT++;
            match(itW, itT);
        }
    }


}