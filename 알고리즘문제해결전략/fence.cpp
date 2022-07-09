#include <iostream>
#include <vector>

using namespace std;


int get_size(const vector<int>& fence, int start, int end);

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

        results.push_back(get_size(fence, 0, fence.size()-1));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}

int get_size(const vector<int>& fence, int start, int end)
{
    //BASE CASE
    if(start == end) return fence[start];

    int half = (start+end)/2;
    int left = half;
    int right = half+1;
    
    int ret = max(get_size(fence, start, half), get_size(fence, half+1, end));
    int height = min(fence[left], fence[right]);

    ret = max(ret, height*2);

    while(left>start||right<end){
        if(right<end &&(left==start || fence[right+1]>fence[left-1])){
            right++;
            height = min(height, fence[right]);
        }
        else{
            left--;
            height = min(height, fence[left]);
        }
        ret = max(ret, height*(right-left+1));
    }

    return ret;
    
}