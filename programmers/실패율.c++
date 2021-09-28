#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double,int> a, pair<double,int> b){
    if(a.first==b.first)    return a.second<b.second;
    return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stg(N+1,0);
    //스테이지에 도달하여 클리어 못한 수
    for(int a:stages)
        stg[a]++;
    //실패율과 스테이지 번호
    int total=stages.size();
    vector<pair<double,int>> v;
    for(int i=1;i<=N;i++){
        if(total==0){v.emplace_back(0,i);   continue;}
        v.emplace_back((double)stg[i]/total,i);
        total-=stg[i];
    }
    sort(v.begin(),v.end(),cmp);
    for(auto a:v)
        answer.emplace_back(a.second);
    return answer;
}