#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int dy[]={0,0,1,-1},dx[]={1,-1,0,0};
bool v[100][100][2];

void in(queue<tuple<int,int,bool>> &q,int a,int b,bool c){
    q.push({a,b,c});
    v[a][b][c]=1;
    return;
}

int solution(vector<vector<int>> board) {
    queue<tuple<int,int,bool>> q;
    int answer = 0;
    int n=board.size();
    n--;
    in(q,0,1,0);
    int size=q.size();
    int x1,y1,x2,y2,xx1,yy1,xx2,yy2;
    bool col;
    while(size){
        y1=get<0>(q.front());
        x1=get<1>(q.front());
        if(y1==x1&&y1==n)    break;
        col=get<2>(q.front());
        if(col){y2=y1-1;x2=x1;}
        else{y2=y1;x2=x1-1;}
        q.pop();
        size--;        
        //좌우상하 공통
        for(int i=0;i<4;i++){
            yy1=y1+dy[i];
            xx1=x1+dx[i];
            yy2=y2+dy[i];
            xx2=x2+dx[i];
            if(yy1<0||yy2<0||xx1<0||xx2<0||yy1>n||yy2>n||xx1>n||xx2>n)  continue;
            if(board[yy1][xx1]||board[yy2][xx2]||v[yy1][xx1][col]) continue;
            q.push({yy1,xx1,col});
            v[yy1][xx1][col]=1;
        }
        if(col){// 세로일때 가로만들기
            if(x1-1>=0)
            if(board[y2][x2-1]==0&&board[y1][x1-1]==0){
                //왼위돌
                if(v[y2][x2][!col]==0){
                    q.push({y2,x2,!col});
                    v[y2][x2][!col]=1;
                }
                //왼아래돌
                if(v[y1][x1][!col]==0){
                    q.push({y1,x1,!col});
                    v[y1][x1][!col]=1;
                }
            }
            if(x1+1<=n)
            if(board[y2][x2+1]==0&&board[y1][x1+1]==0){
                //오위돌
                if(v[y2][x2+1][!col]==0){
                    q.push({y2,x2+1,!col});
                    v[y2][x2+1][!col]=1;
                }
                //오아래돌
                if(v[y1][x1+1][!col]==0){
                    q.push({y1,x1+1,!col});
                    v[y1][x1+1][!col]=1;
                }
            }
        }
        else{//가로일때 세로만들기
            if(y1+1<=n)
            if(board[y2+1][x2]==0&&board[y1+1][x1]==0){
                //왼아래돌
                if(v[y2+1][x2][!col]==0){
                    q.push({y2+1,x2,!col});
                    v[y2+1][x2][!col]=1;
                }
                //오아래돌
                if(v[y1+1][x1][!col]==0){
                    q.push({y1+1,x1,!col});
                    v[y1+1][x1][!col]=1;
                }
            }
            if(y1-1>=0)
            if(board[y2-1][x2]==0&&board[y1-1][x1]==0){
                //왼위돌
                if(v[y2][x2][!col]==0){
                    q.push({y2,x2,!col});
                    v[y2][x2][!col]=1;
                }
                //오위돌
                if(v[y1][x1][!col]==0){
                    q.push({y1,x1,!col});
                    v[y1][x1][!col]=1;
                }
            }
        }
        if(size==0){
            answer++;
            size=q.size();
        }
    }
    return answer;
}