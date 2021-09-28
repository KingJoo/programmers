#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer=0, time, start;
    vector<vector<int>> e(N+1,vector<int>(N+1,2e9));
    for(auto a:road)
        if(e[a[0]][a[1]]>a[2])
            e[a[0]][a[1]]=e[a[1]][a[0]]=a[2];
    vector<bool> visit(N+1);
    priority_queue<pair<int, int>> pq;
    vector<int> dist(N+1,2e9);
    pq.push({dist[1]=0,1});
    while(!pq.empty()) {
        time = -pq.top().first;
        start = pq.top().second;
        pq.pop();
        if(visit[start])    continue;
        visit[start]=true;
        if(time <= K)    answer++;
        for(int next=2; next<=N; next++) {
            if(visit[next]||e[start][next]==2e9)    continue;
            if(time+e[start][next]<dist[next]){
                dist[next]=time+e[start][next];
                pq.push({-dist[next],next});
            }
        }
    }
    return answer;
}

/*
#include <vector>
#include <queue>
using namespace std;
 
vector<pair<int,int>> V[55];
vector<int> Dist;
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Dijkstra(int N)
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, 1));
    Dist[1] = 0;
 
    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
 
        for (int i = 0; i < V[Cur].size(); i++)
        {
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;
 
            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
}
 
int solution(int N, vector<vector<int> > road, int K)
{
    Dist.resize(N + 1, 2e9);
    for (int i = 0; i < road.size(); i++)
    {
        int N1 = road[i][0];
        int N2 = road[i][1];
        int Dist = road[i][2];
 
        V[N1].push_back(make_pair(N2, Dist));
        V[N2].push_back(make_pair(N1, Dist));
    }
 
    Dijkstra(N);
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (Dist[i] <= K) answer++;
    }
 
    return answer;
}
테스트 1 〉	통과 (0.01ms, 3.94MB)
테스트 2 〉	통과 (0.01ms, 3.95MB)
테스트 3 〉	통과 (0.01ms, 3.95MB)
테스트 4 〉	통과 (0.01ms, 3.93MB)
테스트 5 〉	통과 (0.01ms, 3.97MB)
테스트 6 〉	통과 (0.01ms, 3.97MB)
테스트 7 〉	통과 (0.01ms, 3.97MB)
테스트 8 〉	통과 (0.03ms, 3.93MB)
테스트 9 〉	통과 (0.01ms, 3.97MB)
테스트 10 〉	통과 (0.01ms, 3.96MB)
테스트 11 〉	통과 (0.01ms, 3.77MB)
테스트 12 〉	통과 (0.02ms, 3.96MB)
테스트 13 〉	통과 (0.02ms, 3.99MB)
테스트 14 〉	통과 (0.13ms, 3.97MB)
테스트 15 〉	통과 (0.19ms, 3.95MB)
테스트 16 〉	통과 (0.01ms, 3.96MB)
테스트 17 〉	통과 (0.01ms, 3.92MB)
테스트 18 〉	통과 (0.06ms, 3.97MB)
테스트 19 〉	통과 (0.16ms, 3.98MB)
테스트 20 〉	통과 (0.05ms, 3.96MB)
테스트 21 〉	통과 (0.21ms, 4.01MB)
테스트 22 〉	통과 (0.07ms, 3.97MB)
테스트 23 〉	통과 (0.19ms, 3.98MB)
테스트 24 〉	통과 (0.13ms, 3.98MB)
테스트 25 〉	통과 (0.24ms, 3.94MB)
테스트 26 〉	통과 (0.23ms, 4.05MB)
테스트 27 〉	통과 (0.24ms, 3.95MB)
테스트 28 〉	통과 (0.25ms, 3.98MB)
테스트 29 〉	통과 (0.24ms, 3.94MB)
테스트 30 〉	통과 (0.21ms, 3.99MB)
테스트 31 〉	통과 (0.02ms, 3.96MB)
테스트 32 〉	통과 (0.02ms, 3.96MB)*/