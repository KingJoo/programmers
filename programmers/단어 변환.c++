#include <string>
#include <vector>
using namespace std;
#define MX 0x7fffffff
int mn=MX;
vector<bool> visit(false,50);
string bg,tg;
vector<string> wd;

bool oneDiffer(string a, string b){
    int c=0;
    for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])  c++;
    if(c==1)    return true;
    else return false;
}

void dfs(int cnt){
    if(bg==tg){mn=mn<cnt?mn:cnt;   return;}
    string tmp;
    for(int i=0;i<wd.size();i++){
        if(!visit[i]&&oneDiffer(bg,wd[i])){
            visit[i]=true;  tmp=bg; bg=wd[i];
            dfs(cnt+1);
            visit[i]=false; bg=tmp;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    bg=begin;   tg=target;  wd=words;
    dfs(0);
    if(mn==MX)  return 0;
    return mn;
}