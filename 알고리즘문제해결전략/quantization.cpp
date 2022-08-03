#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


const int INF = 987654321;
int n;
//pSum은 A[]의 부분합을 저장하고 qSqSum은 A제곱의 부분합을 저장한다.
int A[100], pSum[100], pSqSum[100];
int cache[100][10];

int quantize(int from, int parts);
int minError(int lo, int hi);
void precalc();

int main()
{
    int numCases;
    cin>>numCases;
    vector<int> results;
    for(int i=0; i<numCases; i++){
        memset(cache, -1, sizeof(cache));
        int s=0;
        cin>>n>>s;
        for(int j=0; j<n; j++){
            cin>>A[j];
        }
        precalc();
        results.push_back(quantize(0, s));
    }

    for(int i=0; i<numCases; i++){
        cout<<results[i]<<endl;
    }
    return 0;
}

//정렬하고 부분합을 저장한다.
//이걸 사용해서 나중에 필요할때 계산하지 않도록 한다.
void precalc()
{
    sort(A, A+n);
    pSum[0] = A[0];
    pSqSum[0] = A[0]*A[0];
    for(int i=1; i<n; i++){
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
    }
}

int minError(int lo, int hi)
{
    int sum = pSum[hi] -(lo == 0? 0: pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0: pSqSum[lo-1]);

    //반올림 하는 방법
    int  m = int(0.5 + (double)sum / (hi-lo +1));
    int ret = sqSum -2 * m * sum + m * m * (hi -lo +1);
    return ret;
}

int quantize(int from, int parts)
{
    if(from == n) return 0;
    if(parts == 0) return INF;
    int& ret = cache[from][parts];
    if(ret != -1) return ret;
    ret = INF;
    for(int partSize =1; from +partSize<=n; partSize++){
        ret = min(ret, minError(from, from + partSize -1) + quantize(from + partSize, parts-1));
    }
    return ret;
}
