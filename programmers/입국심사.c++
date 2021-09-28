#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;

ll cnt(ll time,vector<int>& times){
    ll c=0;
    for(auto a:times){
        if(time/a)  c+=time/a;
        else break;
        if(c>=N) break;
    }
    return c;
}

ll bs(ll s,ll e,vector<int>&times){
    ll mid=(s+e)>>1;
    ll count=cnt(mid,times);
    if(count<N){
        if(cnt(mid+1,times)>=N) return mid+1;
        else return bs(mid+1,e,times);
    }
    else{
        if(cnt(mid-1,times)<N)  return mid;
        return bs(s,mid-1,times);
    }
}

long long solution(int n, vector<int> times) {
    N=n;    sort(times.begin(),times.end());
    return bs(0,(ll)n*times.front(),times);
}