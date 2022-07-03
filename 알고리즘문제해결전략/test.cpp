#include <iostream>
#include <vector>

using namespace std;

int get_size(vector<int>& fence, int sIdx, int eIdx);

int main()
{   
    int numCases = 0;
    cin>>numCases;
    vector<int> results;

    for(int i=0; i<numCases; i++){
        int numFences =0;
        cin>>numFences;
        vector<int> fence;
        for(int j=0; j< numFences; j++){
            int tmp =0;
            cin>>tmp;
            fence.push_back(tmp);
        }
        results.push_back(get_size(fence, 0, numFences));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    
    return 0;
}

int get_size(vector<int>& fence, int sIdx, int eIdx)
{
    //BASE CASE
    if(eIdx-sIdx == 1) return fence[sIdx];

    int halfIdx = (eIdx-sIdx)/2;

    int leftSize = get_size(fence, sIdx, halfIdx);
    int rightSize = get_size(fence, halfIdx, eIdx);

    int leftHeight = leftSize/(halfIdx-sIdx);
    int rightHeight = rightSize/(eIdx-halfIdx);

    int newHeight = (leftHeight>rightHeight) ? leftHeight : rightHeight;
    int newSize = newHeight*(eIdx-sIdx);

    
    int ret = (leftSize>rightHeight) ? leftSize : rightHeight;
    if(newSize>ret) return newSize;
    else return ret;
}