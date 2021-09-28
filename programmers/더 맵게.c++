#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    while(pq.top()<K){
        if(pq.size()==1)    return -1;
        int t=pq.top();
        pq.pop();
        t+=(pq.top()<<1);
        pq.pop();
        pq.emplace(t);
        answer++;
    }
    return answer;
}