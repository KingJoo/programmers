#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp{bool operator()(vector<int> a, vector<int> b){return a[1]>b[1];}};

int solution(vector<vector<int>> jobs) {
    int answer=0, idx=0, stime=0;
    sort(jobs.begin(),jobs.end());
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    while(!pq.empty()||idx<jobs.size()){
        while(idx<jobs.size()&&stime>=jobs[idx][0]) pq.emplace(jobs[idx++]);
        if(pq.empty()){
            stime=jobs[idx][0];
        }
        else{
            stime+=pq.top()[1];
            answer+=stime-pq.top()[0];
            pq.pop();
        }
    }
    return answer/jobs.size();
}