#include <iostream>
#include <vector>

using namespace std;

int get_size(vector<int>& fence, int start, int end);

int main()
{
    int numCases=0;
    cin>>numCases;
    vector<int> results;

    for(int i=0; i<numCases; i++){
        int numFences =0;
        cin>>numFences;
        vector<int> fence;
        for(int j=0; j<numFences; j++){
            int tmp=0;
            cin>>tmp;
            fence.push_back(tmp);
        }

        results.push_back(get_size(fence, 0, fence.size()));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int get_size(vector<int>& fence, int start, int end)
{
    //BASE CASE
    if(end-start == 1) return fence[start];

    int half = (end+start)/2;
    int ret = max(get_size(fence, 0, half), get_size(fence, half, end));

    int left = half-1;
    int right = half;
    int height = min(fence[left], fence[right]);

    while(start<=left || right<end-1){
        if((right<end-1 && (left==start || fence[left-1]<fence[right+1]))){
            right++;
            height = min(height, fence[right]);
        }
        else{
            left--;
            height = min(height, fence[left]);
        }
    }

    ret = max(ret, height*(right-left+1));

    return ret;
}