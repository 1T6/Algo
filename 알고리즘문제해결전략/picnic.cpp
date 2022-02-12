#include <iostream>
#include <vector>

using namespace std;

int countPairs(bool[], int);
void init();
bool areFriends[10][10];
int numStds;
int numPairs;
bool taken[10];

int main()
{
    int numCases;
    vector<int> results;

    cin>>numCases;

    for(int i=0; i<numCases; i++){
        cin>>numStds>>numPairs;
        for(int j=0; j<numPairs; j++){
            int tmp1=0, tmp2=0;
            cin>>tmp1 >>tmp2;
            areFriends[tmp1][tmp2]=true;
            areFriends[tmp2][tmp1]=true;
        }

        results.push_back(countPairs(taken, 0));
        init();
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}
void init()
{
    for(int i=0; i<numStds;i++){
        for(int j=0; j<numStds; j++){
            areFriends[i][j]=false;
            areFriends[j][i]=false;
        }
    }
}

//중복으로 세지는 경우를 대비해서 특정 형태의 답만이 나오게 해야 한다.
//least와 반복문의 j=i+1로 해결할 수 있다.
//아니면 BASE CASE를 찾을때 어차피 한번 서치를 하게 되니 그때 Least를 구해도 괜찮다.
int countPairs(bool taken[10], int least)
{
    //BASE CASE
    int finished = true;
    for(int i=0; i<numStds; i++) if(!taken[i]) finished = false;
    if(finished) return 1;

    //끝난경우, 끝나지 않은경우로 나눠서... 끝나지 않은경우엔?

    int count=0;
    
    for(int i=least; i<numStds; i++){
        for(int j= i+1; j<numStds; j++){
            if(areFriends[i][j] && !taken[i] && !taken[j]){
                taken[i] = taken[j] = true;
                count+= countPairs(taken, i);
                
                //다른 세계관
                taken[i] = taken[j] = false;
            }
        }
    }
    return count;
}
    