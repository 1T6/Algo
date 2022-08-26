#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int m, q;
map<string,int> strToIdx;
string corpus[500];

double T[501][500], M[500][500];

int n;
int words[100];

double cache[100][501];
int choice[100][501];


double maxProb(int target, int before);
string getString(int target, int before);
void solve();

int main()
{	
	
	
	cin>>m>>q;
	for(int i=0; i<m; i++){
		string tmp;
		cin>>tmp;
		strToIdx.insert(pair<string, int>(tmp, i));
		corpus[i] = tmp;
	}
	for(int i=0; i<m; i++){
		double tmp;
		cin>>tmp;
		T[0][i] = log(tmp);
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			double tmp;
			cin>>tmp;
			T[i+1][j] = log(tmp);
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			double tmp;
			cin>>tmp;
			M[i][j] = log(tmp);
		}
	}
	for(int i=0; i<q; i++){
		cin>>n;
		for(int j=0; j<n; j++){
			string tmp;
			cin>>tmp;
			words[j] = strToIdx[tmp];
		}
		solve();
	}
	
	return 0;
}
double maxProb(int target, int before)
{
	if(target == n) return 0;
	double& ret = cache[target][before];
	if(ret > -0.5) return ret;

	ret = -1e200;

	int& choose = choice[target][before];

	for(int i=0; i<m; i++){
		
		double cand = T[before+1][i] + M[i][words[target]] + maxProb(target+1, i);
		if(cand>ret){
			ret = cand;
			choose = i;
		}
	}
	return ret;
}

string getString(int target, int before)
{
	int choose = choice[target][before];
	string ret = corpus[choose];
	if(target < n-1)
		ret +=" " + getString(target+1, choose);
	return ret;
}

void solve()
{
	fill(&cache[0][0], &cache[99][501],  -1);
	memset(choice, -1, sizeof(choice));
	double res = maxProb(0,0);
	string ret = getString(0,0);

	cout<<ret<<endl;
}