#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> dq;
    for(auto s:operations){
        if(s[0]=='I'){
            dq.emplace_back(stoi(s.substr(1)));
            sort(dq.begin(),dq.end());
        }
        else if(dq.size()){
            if(stoi(s.substr(1))==1)    dq.pop_back();
            else    dq.pop_front();
        }
    }
    if(dq.size()==0) return vector<int>{0,0};
    else if(dq.size()==1) return vector<int>{dq.front(),dq.front()};
    else return vector<int>{dq.back(),dq.front()};
}