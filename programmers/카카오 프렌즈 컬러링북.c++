#include <vector>
#include <queue>
using namespace std;
bool visited[100][100];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

void visit(int y,int x,vector<vector<int>> &picture,vector<int> &answer,int m, int n){
    int cnt=0,qSize=1,Y,X,value=picture[y][x];
    answer[0]++;
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=true;
    while(qSize){
        y=q.front().first;
        x=q.front().second;
        q.pop();
        qSize--;
        cnt++;
        for(int i=0;i<4;i++){
            Y=y+dy[i];
            X=x+dx[i];
            if(Y<0||X<0||Y==m||X==n)    continue;
            if(visited[Y][X]||picture[Y][X]!=value) continue;
            q.push({Y,X});
            visited[Y][X]=true;
        }
        if(qSize==0)    qSize=q.size();
    }
    if(cnt>answer[1])   answer[1]=cnt;
    return;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);//[0] number_of_area //[1] max_size_of_one_area;
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            visited[i][j]=false;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j])   continue;
            if(picture[i][j])   visit(i,j,picture,answer,m,n);
            else    visited[i][j]=true;
        }
    }
    
    return answer;
}