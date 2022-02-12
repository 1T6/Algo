/*
    재귀로 map의 전체를 계속해서 넘기면 좀 무리니까... vector을 이용해도 괜찮을듯?
    --> 그냥 전역변수 자체를 사용하지 않으면 된다.
    base case는 어떻게 해야할까... 어떤 한 칸의 사방이 다 black으로 덮여있으면 일단 out
    그리고 모두 black으로 덮히게 되면 out

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int H;
int W;


int main()
{
    int numCases;

    for(int i=0; i<numCases; i++){
        cin>>H>>W;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                
            }
        }        
    }
    return 0;
}


