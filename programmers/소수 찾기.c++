#include <string>
#include <vector>
#include <cmath>
using namespace std;

int c,t;
bool prime[10000000];
bool num[10000000];
bool visit[7];

void dfs(string r,string& numbers,int depth,int len){
    if(depth==len){
        t=stoi(r);
        if(!num[t]){
            num[t]=1;
            if(!prime[t]) c++;
        }
        return;
    }
    for(int i=0;i<numbers.size();i++){
        if(!visit[i]){
            visit[i]=1;
            dfs(r+numbers[i],numbers,depth+1,len);
            visit[i]=0;
        }
    }
}

int solution(string numbers) {
    int mx=1;
    for(int i=0;i<numbers.size();i++)
        mx*=10;
    //소수 찾기(0이면 소수)
    prime[0]=prime[1]=1;
    for(int i=2;i<sqrt(mx);i++){
        if(!prime[i]){
            for(int j=i<<1;j<mx;j+=i)
                prime[j]=1;
        }
    }
    //1자리부터 numbers길이까지 만들면서 cnt
    for(int i=1;i<=numbers.size();i++)
        dfs("",numbers,0,i);
    return c;
}