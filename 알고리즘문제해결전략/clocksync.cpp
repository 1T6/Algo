#include <iostream>
#include <vector>

#define INF 9999


using namespace std;

void mapping();
int solve(int clocks[], int num);
bool areAligned(int clocks[]);
void push(int clocks[], int num);
int switches[10][5]={
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};
bool map[10][16];


int main()
{   
    mapping();
    int numCases;
    cin>>numCases;
    vector<int> results;

    for(int i=0; i<numCases; i++){
        int clocks[16]={0};
        for(int j=0; j<16; j++){
            cin>>clocks[j];
        }
        int ret = solve(clocks,0);
        if (ret>=1000) ret =#include <iostream>
#include <vector>

#define INF 9999


using namespace std;

void mapping();
int solve(int clocks[], int num);
bool areAligned(int clocks[]);
void push(int clocks[], int num);
int switches[10][5]={
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};
bool map[10][16];


int main()
{   
    mapping();
    int numCases;
    cin>>numCases;
    vector<int> results;

    for(int i=0; i<numCases; i++){
        int clocks[16]={0};
        for(int j=0; j<16; j++){
            cin>>clocks[j];
        }
        int ret = solve(clocks,0);
        if (ret>=1000) ret = -1;
        results.push_back(ret);
    }
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    return 0;
}

void mapping()
{
    for(int i=0; i<10; i++){
        int least = switches[i][0];
        for(int j=0; j<5; j++){
            if(switches[i][j]>=least){
                least = switches[i][j];
                map[i][switches[i][j]]=true;
            }
            else break;
        }
    }
}
bool areAligned(int clocks[])
{   
    bool finished =true;
    for(int i=0; i<16; i++){
        if(clocks[i]%12 !=0) finished = false;
    }
    return finished;
}
void push(int clocks[], int num)
{
    for(int i=0; i<16; i++){
        if(map[num][i]){
            clocks[i]+=3;
        }
    }
}
int solve(int clocks[], int num)
{
    if(num ==10) return areAligned(clocks) ? 0 : INF;
    int ret = INF;
    for(int i=0; i<4; i++){
        ret = min(ret, i+solve(clocks, num+1));
        push(clocks, num);
    }
    return ret;
} -1;
        results.push_back(ret);
    }
    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    return 0;
}

void mapping()
{
    for(int i=0; i<10; i++){
        int least = switches[i][0];
        for(int j=0; j<5; j++){
            if(switches[i][j]>=least){
                least = switches[i][j];
                map[i][switches[i][j]]=true;
            }
            else break;
        }
    }
}
bool areAligned(int clocks[])
{   
    bool finished =true;
    for(int i=0; i<16; i++){
        if(clocks[i]%12 !=0) finished = false;
    }
    return finished;
}
void push(int clocks[], int num)
{
    for(int i=0; i<16; i++){
        if(map[num][i]){
            clocks[i]+=3;
        }
    }
}
int solve(int clocks[], int num)
{
    if(num ==10) return areAligned(clocks) ? 0 : INF;
    int ret = INF;
    for(int i=0; i<4; i++){
        ret = min(ret, i+solve(clocks, num+1));
        push(clocks, num);
    }
    return ret;
}