#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Ticket{
public:
    string start,end;
    int idx;
    Ticket(string s,string e,int i){
        this->start=s;
        this->end=e;
        this->idx=i;
    }
};

vector<bool> visit;
vector<Ticket> tk;
vector<string> ans;
string findS="ICN";
int Size,depth=0;
bool rt;

bool cmp(vector<string> a,vector<string> b){
    if(a[0]==b[0])  return a[1]<b[1];
    return a[0]<b[0];
}

int findIdx(int s,int e){
    if(s>e) return -1;
    int m=(s+e)>>1;
    if(findS<tk[m].start)  return findIdx(s,m-1);
    else if(findS>tk[m].start) return findIdx(m+1,e);
    else{
        if(m==0)    return 0;
        else if(findS==tk[m-1].start)    return findIdx(s,m-1);
        else    return m;
    }
}

void dfs(){
    if(depth==Size){rt=true;return;}
    int i=findIdx(0,Size-1);
    if(i==-1) return;
    string prev=findS;
    while(tk[i].start==prev){
        if(visit[tk[i].idx]){i++;continue;}
        visit[tk[i].idx]=true;
        ans.emplace_back(tk[i].end);
        findS=tk[i].end;
        depth++;
        dfs();
        if(rt)  return;
        depth--;
        ans.pop_back();
        visit[tk[i].idx]=false;
        i++;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    Size=tickets.size();
    sort(tickets.begin(),tickets.end(),cmp);
    visit.resize(Size);
    for(int i=0;i<Size;i++)
        tk.emplace_back(Ticket(tickets[i][0],tickets[i][1],i));
    ans.emplace_back("ICN");
    dfs();
    return ans;
}