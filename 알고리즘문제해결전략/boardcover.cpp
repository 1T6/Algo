#include <iostream>
#include <string>
#include <vector>

using namespace std;

int H;
int W;
int coverType[4][3][2] ={
    {{0,0},{1,0},{0,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,-1}}
    };

bool cover(vector<vector<int>>& map, int y, int x,int type, int delta);
int countCovers(vector<vector<int>>& map);

int main()
{
    int numCases;
    vector<int> results;
    
    cin>> numCases;

    for(int i=0; i<numCases; i++){
        vector<vector<int>> map;

        cin>>H>>W;
        int whiteCount=0;

        for(int j=0; j<H; j++){
            string tmp;
            cin>>tmp;
            vector<int> line;

            for(int k=0;k<W;k++){
                //BLACK
                if(tmp[k]=='#'){
                    line.push_back(1);
                }
                //WHITE
                else if(tmp[k] == '.'){
                    line.push_back(0);
                    whiteCount++;
                }
            }
            map.push_back(line);
        }
        if(whiteCount%3!=0){
            results.push_back(0);
        }
        else{
            results.push_back(countCovers(map));
        }
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    return 0;
}

int countCovers(vector<vector<int>>& map)
{   
    int y = 0;
    int x = 0;
    bool finished=true;
    //가장 왼쪽 위에 빈칸 찾기.
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(map[i][j]==0){
                y=i;
                x=j;
                finished = false;
                break;
            }
        }
        if(finished==false) break;
    }

    //BASE CASE
    if(finished) return 1;

    int ret = 0;
    for(int i=0; i<4; i++){
        //COVER
        if(cover(map, y, x, i, 1)) ret+=countCovers(map);
        //REMOVE COVER
        cover(map,y,x, i,-1);
    }

    return ret;
}

bool cover(vector<vector<int>>& map, int y, int x,int type, int delta)
{
    bool ret = true;
    for(int i=0; i<3; i++){
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];
        //OUT OF BOUND
        if(ny<0 || ny>=H ||nx<0 || nx>=W){
            ret = false;
        }
        //ALREADY COVERED
        else if((map[ny][nx] += delta) >1){
            ret = false;
        }
    }
    return ret;
}