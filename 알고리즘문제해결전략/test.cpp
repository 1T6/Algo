#include <iostream>



using namespace std;

int cache [30][30];
int bino(int n, int r);

int main()
{   
    fill(&cache[0][0], &cache[29][29], -1);

    for(int i=0; i<30; i++){
        for(int j=0; j<30; j++){
            cout<<cache[i][j];
        }
        cout<<endl;
    }
    int tmp1, tmp2;
    cin>>tmp1>>tmp2;

    cout<<bino(tmp1, tmp2);

    return 0;
}

int bino(int n, int r)
{
    //BASE CASE
    if(n==r || r ==0) return 1;

    if
}
