#include <iostream>
#include <vector>
#define INF 9999
using namespace std;

vector<vector<int>> map = {
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

int solve(vector<int>& clocks, int num);
bool areAligned(vector<int>& clocks);
void push(vector<int>& clocks, int num);

int main()
{
    int numCases;
    cin>> numCases;

    vector<int> results;

    for(int i=0; i<numCases; i++){

        vector<int> clocks;
        for(int j=0; j<16; j++){
            int tmp;
            cin>>tmp;
            clocks.push_back(tmp);
        }

        int ret = solve(clocks, 0);
        if(ret == INF) results.push_back(-1);
        else results.push_back(ret);
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int solve(vector<int>& clocks, int num)
{
    if(num == 10) return areAligned(clocks) ? 0 : INF;

    int ret = INF;
    for(int i=0; i<4; i++){
        ret = min(ret, i+solve(clocks, num+1));
        //push를 뒤에 적는 이유는 처음에 i는 누르지 않기 때문. 다음을 위한 세팅이라고 생각하면 된다.
        push(clocks, num);
    }

    return ret;
}

bool areAligned(vector<int>& clocks)
{
    for(int i=0; i<16;i++){
        if(clocks[i]%12 != 0 ) return false;
    }
    return true;
}

void push(vector<int>& clocks, int num)
{
    for(auto it = map[num].begin(); it!=map[num].end(); it++){
        clocks[*it] +=3;
    }
}