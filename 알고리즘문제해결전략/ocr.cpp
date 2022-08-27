#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

void init();

int m, q;
string corpus[500];
double T[501][500], M[500][500];

map<string, int> strToIdx;

int n;
int words[100];


double maxProb(int target, int before);
string getString(int target, int before);
void solve();


double cache[100][501];
int choice[100][501];

int main()
{
	init();
	cin>>m>>q;
	double tmp;
	for(int i=0; i<m; i++){
		cin>>corpus[i];
        strToIdx.insert(pair<string, int>(corpus[i], i));
	}
	for(int i=0; i<m; i++){
		cin>> tmp;
		T[0][i] = log(tmp);
	}
	for(int i=1; i<=m; i++){
		for(int j=0; j<m; j++){
			cin>> tmp;
			T[i][j] = log(tmp);
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			cin>>tmp;
			M[i][j] = log(tmp);
		}
	}
	for(int i=0; i<q; i++){
		cin>>n;
		string tmps;
        for(int j=0; j<n; j++){
            cin>>tmps;
            words[j] = strToIdx[tmps];
        }
        solve();
	}

	return 0;
}
void init()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

double maxProb(int target, int before)
{
    if(target == n) return 0;
    double& ret  = cache[target][before+1];
    if(ret != -1) return ret;

    ret = -1e200;

    for(int i=0; i<m; i++){
        double cand = T[before+1][i] + M[i][words[target]] + maxProb(target+1, i);
        if(cand>ret){
            ret = cand;
            choice[target][before+1] = i;
        }
    }
    return ret;
}
void solve()
{
    fill(&cache[0][0], &cache[99][501], -1);
    memset(choice, -1, sizeof(choice));
    double res = maxProb(0, -1);
    string ret = getString(0,-1);
    cout<<ret<<endl;
}
string getString(int target, int before)
{
    int choose = choice[target][before+1];
    string ret = corpus[choose];
    if(target < n-1)
        ret += " " + getString(target+1, choose);
    
    return ret;
}