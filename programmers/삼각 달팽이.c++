#include <string>
#include <vector>
enum{D,R,U_L};
using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> a(n,vector<int>(n,0));
    int N,d=0,y=-1,x=0,s=0;
    for(int i=n;i>0;i--){
        N=i;
        if(d==D)    while(N--)   a[++y][x]=++s;
        else if(d==R)   while(N--)   a[y][++x]=++s;
        else    while(N--)   a[--y][--x]=++s;
        d=(d+1)%3;
    }
    vector<int> answer;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            answer.push_back(a[i][j]);
    return answer;
}