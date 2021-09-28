#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> arrows) {
    int d[][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int answer = 0,y=0,x=0,yy,xx;
    map<pair<int,int>,bool> vtx; vtx[{0,0}]=1;
    map<pair<pair<int,int>,pair<int,int>>,bool> edge;
    for(auto a:arrows){
        for(int i=0;i<2;i++){
            yy=y+d[a][0];
            xx=x+d[a][1];
            if(vtx[{yy,xx}]&&!edge[{{y,x},{yy,xx}}]) answer++;
            vtx[{yy,xx}]=edge[{{y,x},{yy,xx}}]=edge[{{yy,xx},{y,x}}]=1;
            y=yy;
            x=xx;
        }
    }
    return answer;
}