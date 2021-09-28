#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int remain[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string tr(int num,int n){
    string r="";
    while(num){
        r+=remain[num%n];
        num/=n;
    }
    reverse(r.begin(),r.end());
    return r;
}

string solution(int n, int t, int m, int p) {
    string answer = "", tmp="0";
    int l=m*(t-1)+p,num=1;
    while(tmp.size()<l)
        tmp+=tr(num++,n);
    p--;
    for(int i=0;i<t;i++)
        answer+=tmp[m*i+p];
    return answer;
}