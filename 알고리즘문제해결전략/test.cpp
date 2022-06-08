#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count(int (*board)[20]);
bool inRange(int y, int x);
bool cover(int y, int x, int (*board)[20], int type, int delta);


int N, H, W;
int board[20][20];

int dir[4][3][2] = {
    {{0,0},{0,1},{1,0}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};


int main()
{
    vector<int> results;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>H>>W;

        for(int j=0; j<H; j++){
            string tmp;
            cin>>tmp;
            for(int k=0; k<W; k++){
                if(tmp[k] =='#') board[j][k] = 1;
                else board[j][k] =0;
            }
        
        }
        results.push_back(count(board));
    }

    for(int i=0; i<N; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int count(int (*board)[20])
{   
    int y = -1, x = -1;
    bool finished = true;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(!board[i][j]){
                y = i;
                x = j;
                finished = false;
            }
        }
    }
    if(finished) return 1;
    

    int ret = 0;

    for(int i=0; i<4; i++){
        if(cover(y, x, board, i, 1)){
            ret += count(board);

            
        }
        cover(y, x, board, i, -1);

    }
    return ret;
}
bool cover(int y, int x, int (*board)[20], int type, int delta)
{
    bool ok = true;

    for(int i=0; i<3; i++){
        int t_y = y+ dir[type][i][0];
        int t_x = x+ dir[type][i][1];
        
        if(inRange(t_y, t_x) && (board[t_y][t_x]+=delta)>1){
            ok = false;
        }
    }

    return ok;

}

bool inRange(int y, int x)
{
    return (y>=0 && x>=0 && y<H && x<W);
}



