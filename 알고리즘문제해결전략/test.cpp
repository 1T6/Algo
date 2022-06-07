#include <iostream>
#include <string>
#include <vector>

using namespace std;


string findWord(string word);
bool inRange(int y, int x);
bool hasWord(int y, int x, const string& word);


char map[5][5];

const int dy[8] = {0,  0, 1, 1, 1, -1,-1, -1};
const int dx[8] = {1, -1, 0, 1, -1,  0, 1, -1};


int main()
{
    int numCases;

    cin>>numCases;

    for(int i=0; i<numCases; i++){

        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                cin>>map[j][k];
            }
        }
    

        int numWords =0;
        cin>>numWords;
        vector<string> words;
        
        for(int j=0; j<numWords; j++){
            string tmp;
            cin>>tmp;
            words.push_back(tmp);
        }

        for(int j=0; j<numWords; j++){
            cout<<words[j]<<" "<<findWord(words[j])<<endl;
        }

    }

    return 0;
}

string findWord(string word)
{
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(hasWord(i, j, word)){
                return "YES";
            }
        }
    }
    return "NO";
}

bool hasWord(int y, int x, const string& word)
{   
    if(!inRange(y,x)){
        return false;
    }
    if(map[y][x] != word[0]){
        return false;
    }
    if(word.length() ==1){
        return true;
    }

    for(int i=0; i<8; i++){
        int n_y = y+dy[i];
        int n_x = x+dx[i];

        if(hasWord(n_y, n_x, word.substr(1))){
            return true;
        }
    }

    return false;
    
}

bool inRange(int y, int x)
{
    if(x>=0 && y>=0 && x<5 && y<5){
        return true;
    }
    else return false;
}