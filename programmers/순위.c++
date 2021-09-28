/*#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<bool>> win(101,vector<bool>(101,0)),lose(101,vector<bool>(101,0));

int Cnt(int n,vector<vector<bool>>& v,vector<bool>& visit){
    visit[n]=true;
    int c=0;
    for(int i=1;i<N;i++)
        if(v[n][i]&&!visit[i])  c+=1+Cnt(i,v,visit);
    return c;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    N=n+1;  n--;
    for(auto a:results)
        win[a[0]][a[1]]=lose[a[1]][a[0]]=1;
    for(int i=1;i<N;i++){
        vector<bool> v1(N,0),v2(N,0);
        if(Cnt(i,win,v1)+Cnt(i,lose,v2)==n) answer++;
    }
    return answer;
}*/
#include <string>
#include <vector>
using namespace std;
bool a[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer=0;
    for(auto t:results)
        a[t[0]][t[1]]=1;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][k]&a[k][j]) a[i][j]=1;
    int c;
    for(int i=1;i<=n;i++){
        c=0;
        for(int j=1;j<=n;j++)
            c+=a[i][j]+a[j][i];
        if(c==n-1)  answer++;
    }
    return answer;
}