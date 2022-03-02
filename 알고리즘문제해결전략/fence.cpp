#include <iostream>
#include <vector>


using namespace std;

int bruteForce(const vector<int>& boards);
int getSize(const vector<int>& boards, int left, int right);

int main()
{
    int numCases=0;
    vector<int> results;

    cin>>numCases;

    for(int i=0; i<numCases; i++){
        int numBoards = 0;
        vector<int> boards;
        cin>>numBoards;
        for(int j=0; j<numBoards; j++){
            int tmp=0;            
            cin>>tmp;
            boards.push_back(tmp);
        }

        results.push_back(getSize(boards, 0,boards.size()-1));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int bruteForce(const vector<int>& boards)
{
    int ret =0;
    int N = boards.size();

    for(int i=0; i<N; i++){
        int minHeight = boards[i];
        for(int j=i; j<N;j++){
            minHeight= min(minHeight, boards[j]);
            ret = max(ret, (j-i+1)*minHeight);
        }
    }
    return ret;
}

int getSize(const vector<int>& boards, int left, int right)
{   
    
    //BASE CASE
    if(left==right) return boards[left];
    //분할
    int mid = (right+left)/2;
    int ret = max(getSize(boards, left, mid),getSize(boards, mid+1, right));

    //두 부분에 걸친 사각형 중 가장 큰 것을 찾는다.
    int lo = mid, hi = mid+1;
    int height = min(boards[lo], boards[hi]);

    ret = max(ret, height*2);

    while(left<lo ||hi <right){
        if(hi<right && (lo==left || boards[lo-1]<boards[hi+1])){
            ++hi;
            height = min(height, boards[hi]);
        }
        else{
            --lo;
            height = min(height, boards[lo]);
        }
        ret = max(ret, height*(hi-lo+1));
    }

    return ret;
}