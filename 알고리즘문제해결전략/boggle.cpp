
#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool hasWord(int, int, const string&);
bool inRange(int, int);
string findWord(const string&);
void init();
    
char map[5][5];
string target[10];


const int dx[8] = {1,1,1,-1,-1,-1,0,0};
const int dy[8] = {1,-1,0,1,-1,0,1,-1};

int main()
{
    int numCases;
    
    cin>> numCases;

    for(int i=0; i<numCases; i++){
        
        for(int j=0; j<5; j++){
            for(int k=0; k<5;k++){
                cin>>map[j][k];
            }
        }

        int numWords=0;
        cin>>numWords;

        for(int l=0; l< numWords; l++){
            cin>>target[l];
            
        }
        for(int l=0; l<numWords; l++){

            cout<<target[l]<<" "<<findWord(target[l])<<endl;;
            
        }

    }

    return 0;
}

bool hasWord(int y, int x, const string& word)
{   
    //OUT OF RANGE, WRONG CHAR
    if(!inRange(y, x)){
        return false;

    }
    if(map[y][x] != word[0]){
        return false;
    }
    //BASE CASE
    if(word.length() ==1){  
        return true;
    }
    
    for(int dir=0; dir<8; dir++){
        int next_y = y+dy[dir];
        int next_x = x+dx[dir];

        if(hasWord(next_y, next_x, word.substr(1))){
            return true;
        }
    }

    return false;

}

bool inRange(int y, int x)
{
    if(y>=0 && y<5 && x>=0 && x<5){
        return true;
    }

    else{
        return false;
    }
}

string findWord(const string& word)
{
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            bool res = hasWord(i,j, word);

            if(res == true){
                return "YES";
            }
        }
    }
    
    return "NO";
}