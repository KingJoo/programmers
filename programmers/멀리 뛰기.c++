#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> dy(n+1);
    dy[1]=1;
    dy[2]=2;
    if(n<=2) return dy[n];
    for(long long i=3; i<=n; i++) {
        dy[i] = (dy[i-1] + dy[i-2])%1234567;
    }
    return dy[n];
}