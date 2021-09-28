#include <string>
using namespace std;
bool visit[11][11][11][11];
int ans;

void move(int y, int x, int py, int px){
    if(visit[y][x][py][px])  return;
    visit[py][px][y][x]=visit[y][x][py][px]=true;
    ans++;
    return;
}

int solution(string dirs) {
    int y=5, x=5;
    for(char &c : dirs){
        if(c=='U'&&y!=10)   move(y,x,++y,x);
        else if(c=='D'&&y!=0)   move(y,x,--y,x);
        else if(c=='L'&&x!=0)   move(y,x,y,--x);
        else if(c=='R'&&x!=10)  move(y,x,y,++x);
    }
    return ans;
}