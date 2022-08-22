#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, int> strToIdx;
map<int, string> idxToStr;

int m, q;
int B[500], M[500][500], T[500][500];

int n;
string words[500];

double cache[500][500];

double maxProb(int target, int before;

int main()
{
    cin>>m>>q;
    for(int i=0; i<m; i++){
        string tmp;
        cin>>tmp;
        strToIdx.insert(pair<string, int>(tmp,i));
        idxToStr.insert(pair<int, string>(i, tmp));
    }
    for(int i=0; i<m; i++){
        cin>>B[i];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin>>T[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin>>M[i][j];
        }
    }

    for(int i=0; i<q; i++)){
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>words[j];
        }
    }
    return 0;
}

