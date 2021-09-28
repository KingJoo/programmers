#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int d,mx=0;
    for(int i=0;i<speeds.size();i++){
        d=(99-progresses[i])/speeds[i]+1;
        if(answer.empty()||d>mx) answer.push_back(1);
        else answer.back()++;
        mx=mx>d?mx:d;
    }
    return answer;
}