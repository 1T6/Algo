#include <iostream>
#include <vector>
#include <string>

using namespace std;


int countHug(const string& mem, const string& fan);
vector<int> karatsuba(const vector<int>& a, const vector<int>& b);

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;

    for(int i=0; i<numCases; i++){
        string mem;
        string fan;
        cin>>mem>>fan;
        
        results.push_back(countHug(mem, fan));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }

    return 0;
}
int countHug(const string& mem, const string& fan)
{
    int memN=mem.size(), fanN=fan.size();
    vector<int> M, F;
    for(int i=0; i<memN; i++) M.push_back(mem[i]=='M');
    for(int i=0; i<memN; i++) F.push_back(fan[i]=='M');
    vector<int> mul = karatsuba(M,F);
    int ret=0;
    for(int i=memN-1; i<fanN; i++) if(mul[i]==0)ret++;
    return ret;
}
vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
    int an = a.size(), bn = b.size();
    if(an<bn) return karatsuba(b,a);
    if(an == 0 || bn == 0) return vector<int>();
    if(an <=50) return multiplu(a,b);
    int half = an/2;

    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+min<int>(b.size(), half));
    vector<int> b1(b.begin()+min<int>(b.size(), half, b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    
    addTo(a0, a1, 0); addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    
    subfrom(z1,z0);
    subfrom(z1,z2);

    vector<int> ret;

    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half+half);

    return ret;
}