#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0,p,l;
    bool _push;
    deque<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++)
        q.push_back({priorities[i],i});
    while(q.size()){
        p=q.front().first;
        l=q.front().second;
        q.pop_front();
        _push=false;
        for(int i=0;i<q.size();i++){
            if(q[i].first>p){
                _push=true;
                break;
            }
        }
        if(_push)    q.push_back({p,l});
        else{
            answer++;
            if(l==location) break;
        }
    }
    return answer;
}