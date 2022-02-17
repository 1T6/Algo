#include <iostream>
#include <vector>

using namespace std;


int coutNum(int clocks[]);
void mapping();
int switches[9][5] ={
    {0, 1, 2},
    {3,7,9, 11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}};

bool map[9][16];

int main()
{  
    mapping();

    int numCases;
    vector<int> results;
    cin>>numCases;

    for(int i=0; i<numCases; i++){
        int clocks[16]={0};
        for(int j=0; j<16; j++){
            cin>>clocks[j];
        }

        results.push_back(countNum);
    }

    for(int i=0; i<16; i++){
        cout<<results[i];
    }


    return 0;
}

void mapping()
{

    for(int i=0; i<9; i++){
        int least = switches[i][0];
        for(int j=0; j<5; j++){
            if(switches[i][j]<least){
                break;
            }
            else{
                map[i][switches[i][j]]=true;
            }
        }
    }


}

int countNum(int[] clocks)
{
    int target=0;
    for(int i=0; i<16; i++){
        if(clocks[i]%12 != 0){
            target = i;
        }
    }

    int ret;


}
