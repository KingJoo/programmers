#include <string>
#include <vector>

using namespace std;

bool ck[200];
int sz,r;
vector<vector<int>> cpt;

void dfs(int s){
    ck[s]=1;
    for(int i=0;i<sz;i++)
        if(!ck[i]&&cpt[s][i])   dfs(i);
    return;
}

int solution(int n, vector<vector<int>> computers) {
    sz=computers.size();
    cpt=move(computers);
    for(int i=0;i<n;i++)
        if(!ck[i]){dfs(i);r++;}
    return r;
}