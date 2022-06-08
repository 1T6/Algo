#include <iostream>
#include <vector>

using namespace std;

int countPairs(bool taken[10]);
void init();

bool areFriends[10][10];
int n;

int main()
{
    int numCases;
    vector<int> results;


    cin>>numCases;
    for(int i=0; i<numCases; i++){
        
        int numPairs=0;
        cin>>n>>numPairs;

        for(int i=0; i<numPairs; i++){
            int tmp1;
            int tmp2;
            cin>>tmp1>>tmp2;
            areFriends[tmp1][tmp2] = true;
            areFriends[tmp2][tmp1] = true;
        }

        bool taken[10] = {false};
        
        results.push_back(countPairs(taken));
        init();
        
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    return 0;

}

void init()
{
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            areFriends[i][j]=false;
            areFriends[j][i]=false;
        }
    }
}

int countPairs(bool taken[10])
{
    int first = -1;
    for(int i=0; i<n; i++){
        if(!taken[i]){
            first = i;
            break;
        }
    }

    if(first == -1) return 1;

    int ret = 0;

    for(int i = first+1; i<n; i++){
        if(areFriends[first][i] && !taken[i]){
            taken[first] = true;
            taken[i] = true;
            cout<<first<<i<<endl;
            ret += countPairs(taken);
            taken[first] = false;
            taken[i] =false;        
        }
    }

    return ret;
}

