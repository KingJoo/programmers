#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> map;
queue<int> tmp;
int Min;

void save(int t){if(t<Min)Min=t;tmp.push(t);}

void overwrite(int x,int y){map[x][y]=tmp.front();tmp.pop();}

void change(int x1,int y1,int x2,int y2,vector<int> & ans){
    Min=10001;
    //save
    for(int i=y1;i<=y2;i++)
        save(map[x1][i]);
    for(int i=x1+1;i<=x2;i++)
        save(map[i][y2]);
    for(int i=y2-1;i>=y1;i--)
        save(map[x2][i]);
    for(int i=x2-1;i>x1;i--)
        save(map[i][y1]);
    //overwrite
    for(int i=y1+1;i<=y2;i++)
        overwrite(x1,i);
    for(int i=x1+1;i<=x2;i++)
        overwrite(i,y2);
    for(int i=y2-1;i>=y1;i--)
        overwrite(x2,i);
    for(int i=x2-1;i>=x1;i--)
        overwrite(i,y1);
    //min
    ans.emplace_back(Min);
    return;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    map=vector<vector<int>>(rows+1,vector<int>(columns+1));
    for(int i=1;i<=rows;i++)
        for(int j=1;j<=columns;j++)
            map[i][j]=(i-1)*columns+j;
    for(auto t :queries)
        change(t[0],t[1],t[2],t[3],answer);
    return answer;
}