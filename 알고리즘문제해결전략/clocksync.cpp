#include <iostream>
#include <vector>

using namespace std;


int countNum(int clocks[], int clicked[]);
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
int clicked[9];

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

        results.push_back(countNum(clocks, clicked));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
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

int countNum(int clocks[], int clicked[])
{   
    //BASE CASE
    //왜 답이 없게 되는지도 알려줘야지 아니면 segmentation fault가 나오게 된다.
    //이것은 같은 스위치를 4번 누르게 되면 정답이 없게 하는 insight로 접근하면 된다.
    int target=0;
    bool finished =true;
    for(int i=0; i<16; i++){
        if(clocks[i]%12 != 0){
            target = i;
            finished= false;
            break;
        }
    }
    if(finished) return 1;

    for(int i=0; i<9; i++){
        if(clicked[i]>=4){
            return 0;
        }
    }

    int ret=0;

    for(int i=0; i<9; i++){
        
        if(map[i][target]){
            for(int j=0; j<16; j++){
                if(map[i][j]){
                    clocks[j]+=3;
                    clicked[i]++;
                }
            }

            ret +=countNum(clocks, clicked);

            for(int j=0; j<16; j++){
                if(map[i][j]){
                    clocks[j]-=3;
                    clicked[i]--;
                }
            }
        }
    }

    return ret;
}
