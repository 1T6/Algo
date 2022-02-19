#include <iostream>
#include <vector>

using namespace std;

void mapping();
int countNum(int clocks[]);

int switches[10][5]={
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};
bool map[10][16];
int clicked[10];

int main()
{      
    mapping();

    int numCases=0;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        int clocks[16];

        for(int j=0; j<16; j++){
            cin>>clocks[j];
        }

        results.push_back(countNum(clocks));
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

            if(least>switches[i][j]){
                break;
            }
            else{
                map[i][switches[i][j]] = true;
            }
        }
    }
}

int countNum(int clocks[])
{

    for(int i=0; i<10; i++){
        cout<<clicked[i]<<" ";
    }
    cout<<endl;
    //BASE CASE
    bool finished =true;
    for(int i=0; i<16; i++){
        if(clocks[i]%12 !=0){
            finished = false;
        }
    }
    if(finished) return 1;
    for(int i=0; i<10; i++){
        if(clicked[i]>=4){
            return 0;
        }
    }

    int ret=0;

    for(int i=0; i<10; i++){


        clicked[i]++;
        for(int j=0; j<16; j++){
            if(map[i][j]){
                clocks[j]+=3;
            }
        }

        ret += countNum(clocks);

        for(int j=0; j<16; j++){
            if(map[i][j]){
                clocks[j]-=3;
            }
        }

        clicked[i]--;
    }
    return ret;

}
