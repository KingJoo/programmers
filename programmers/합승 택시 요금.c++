#include <string>
#include <vector>

using namespace std;

int cost[201][201], INF=201*100000;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           cost[i][j]=INF;
    
    for(auto v:fares)
        cost[v[0]][v[1]]=cost[v[1]][v[0]]=v[2];
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(cost[i][k]==INF||cost[k][j]==INF)    continue;
                else    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
    
    answer=min(cost[s][a]+cost[s][b],min(cost[s][a]+cost[a][b],cost[s][b]+cost[b][a]));
    
    for(int i=1;i<=n;i++){
        if(i==s||i==a||i==b)    continue;
        answer=min(answer,cost[s][i]+cost[i][a]+cost[i][b]);
    }
    
    return answer;
}