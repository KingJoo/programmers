#include <vector>
using namespace std;

int solution(vector<vector<int> > land){
    int mx,nxtMx,answer=0;
    for(int i=1;i<land.size();i++){
        if(land[i-1][0]>land[i-1][1]){mx=0;nxtMx=1;}
        else{mx=1;nxtMx=0;}
        for(int j=2;j<4;j++){
            if(land[i-1][j]>land[i-1][mx]){nxtMx=mx;mx=j;}
            else if(land[i-1][j]>land[i-1][nxtMx])  nxtMx=j;  
        }
        for(int j=0;j<4;j++){
            if(j==mx)   land[i][j]+=land[i-1][nxtMx];
            else    land[i][j]+=land[i-1][mx];
        }
    }
    for(int i=0;i<4;i++)
        answer=answer<land[land.size()-1][i]?land[land.size()-1][i]:answer;
    return answer;
}