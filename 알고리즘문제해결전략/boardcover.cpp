#include <iostream>
#include <vector>

using namespace std;

void init();
int count();
bool cover(int y, int x, int type, int delta);
bool inRange(int y, int x);
int H, W;
int board[20][20];
int dir[4][3][2] = {
    {{0,0}, {1,0}, {0,1}},
    {{0,0}, {0,1}, {1,1}},
    {{0,0}, {1,0}, {1,1}},
    {{0,0}, {1,0}, {1,-1}},
    
};

int main()
{

    init();

    int numCases;
    cin>>numCases;
    vector<int> results;

    for(int i=0; i<numCases; i++){
        cin>>H>>W;
        
        for(int j=0; j<H; j++){
            for(int k=0; k<W; k++){
                char tmp;
                cin>>tmp;
                if(tmp=='#') board[j][k] = 1;
                else board[j][k] =0;
            }
        }
        
        results.push_back(count());
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int count()
{
    bool finished = true;

    int x=0, y =0;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(!board[i][j]){
                y=i;
                x=j;
                finished = false;
                break;
            }
        }
        if(!finished) break;
    }

    //BASE CASE
    if(finished) return 1;

    int ret= 0;
    for(int i=0; i<4; i++){
        if(cover(y, x, i, 1)) 
            ret += count();
        cover(y, x, i, -1);
    }

    return ret;
}
bool cover(int y, int x, int type, int delta)
{   
    bool ok = true;

    for(int i=0; i<3; i++){
        int n_y = y+dir[type][i][0];
        int n_x = x+dir[type][i][1];
        if(!inRange(n_y, n_x)) ok = false;
        else{
            if((board[n_y][n_x]+=delta)>1) ok = false;
        }
    }
    return ok;

}
bool inRange(int y, int x)
{
    return (y>=0 && x>=0 && y<H && x<W);
}