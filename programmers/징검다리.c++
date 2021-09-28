#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer=0;
    sort(rocks.begin(),rocks.end());
    int s=1,e=distance,m,removeCnt,prev;
    while (s<=e) {
        m=(s+e)>>1;
        removeCnt=prev=0;
        for(int &rock:rocks)
            rock-prev<m?removeCnt++:prev=rock;
        if(distance-prev<m) removeCnt++;
        if(removeCnt>n)   e=m-1;
        else{s=m+1;answer=answer<m?m:answer;}
    }
    return answer;
}