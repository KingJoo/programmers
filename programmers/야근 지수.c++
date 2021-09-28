#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    vector<int> w(50001);
    int mx=*max_element(works.begin(),works.end());
    for(int t:works)    w[t]++;
    while(n&&mx){
        if(w[mx]<n){
            w[mx-1]+=w[mx];
            n-=w[mx--];
        }
        else{
            if(w[mx]==n)    w[--mx]+=n;
            else{w[mx]-=n;w[mx-1]+=n;}
            break;
        }
    }
    for(int i=mx;i>0;i--)
        if(w[i])    answer+=(long long)w[i]*i*i;
    return answer;
}