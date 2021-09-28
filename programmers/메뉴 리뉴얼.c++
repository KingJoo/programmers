#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
bool ck[11];
int len,tLen;
string t;
unordered_map<string,int> um;

void select(int depth, int cnt){
    if(depth>tLen)    return;
    if(cnt==len){
        string newCourse="";
        for(int i=0;i<tLen;i++)
            if(ck[i])   newCourse+=t[i];
        
        if(um.count(newCourse)) um[newCourse]++;
        else    um[newCourse]=1;
        
        return;
    }
    ck[depth]=true;
    select(depth+1,cnt+1);
    ck[depth]=false;
    select(depth+1,cnt);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    um.clear();
    
    for(string &s:orders)
        sort(s.begin(),s.end());
    
    for(int cs : course){
        len=cs;
        for(string &s:orders){
            if(s.size()<len)    continue;
            t=s;
            tLen=s.size();
            select(0,0);
        }
        //um에서 제일 높은 count 찾기
        int maxCnt=2;
        for(auto elem:um)
            maxCnt=elem.second>maxCnt?elem.second:maxCnt;
        //제일 높은 count를 가진 key를 answer에 넣기 
        for(auto elem:um)
            if(elem.second==maxCnt)    answer.push_back(elem.first);
        um.clear();
    }
    sort(answer.begin(),answer.end());
    return answer;
}