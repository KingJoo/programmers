#include <string>
#include <vector>
#include <queue>
#define MAX 20001

using namespace std;
vector<vector<int>> e(MAX,vector<int>(MAX,0));
vector<bool> v(MAX,0);
queue<int> q;
int N,sz,c;

void visit(int n){
    for(int i=1;i<N;i++)
        if(e[n][i]&&!v[i]){v[i]=true;  q.emplace(i);}
    return;
}

int solution(int n, vector<vector<int>> edge) {
    N=n+1;
    for(auto t:edge)
        e[t[0]][t[1]]=e[t[1]][t[0]]=1;
    v[1]=1;
    visit(1);
    c=sz=q.size();
    while(sz--){
        visit(q.front());
        q.pop();
        if(sz==0){
            sz=q.size();
            if(sz==0)   return c;
            else    c=sz;
        }
    }
    return 0;
}