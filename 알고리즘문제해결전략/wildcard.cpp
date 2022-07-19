#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[101][101];
string W, S;

bool match(int w, int s);

int main()
{
    int numCases;
    cin>>numCases;
    vector<string> results;
    
    for(int i=0; i<numCases; i++){
        vector<string> tmp;
        int n;
        cin>>W>>n;
        for(int j=0; j<n; j++){
            memset(cache, -1, sizeof(cache));
            cin>>S;
            bool ret = match(0,0);  
            if(ret == true) tmp.push_back(S);
        }
        sort(tmp.begin(), tmp.end());
        results.insert(results.end(), tmp.begin(), tmp.end());
    }

    for(int i=0; i<results.size(); i++){
        cout<<results[i]<<endl;
    }
    return 0;
}
bool match(int w, int s)
{
    int& ret = cache[w][s];
    if(ret != -1) return ret;

    while(s<S.size() && w<W.size() && (W[w]=='?' || W[w]==S[s])){
        return ret = match(w+1, s+1);
    }
    if(w==W.size()) return ret = (s==S.size());

    if(W[w] =='*'){
        //아무 글자도 대응되지 않는 경우, 다음 글자가 대응되는 경우.
        if(match(w+1, s) || (s<S.size() && match(w, s+1))) return ret = 1;
    }
    
    return ret =0;
}