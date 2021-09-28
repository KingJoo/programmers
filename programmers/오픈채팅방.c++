#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class elem{
public:
    string s;
    bool in;
    elem(string S, bool In){
        this->s=S;
        this->in=In;
    }
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<elem> e;
    unordered_map<string,string> um;
    string stat,id,name;
    
    for(string &s:record){
        stringstream ss;
        ss.str(s);
        ss>>stat>>id>>name;
        if(stat=="Enter"){
            um[id]=name;
            e.push_back(elem(id,true));
        }
        else if(stat=="Leave"){
            e.push_back(elem(id,false));
        }
        else    um[id]=name;
    }
    for(auto &t:e){
        string tmp = "";
        tmp+=um[t.s];
        if(t.in)    tmp+="님이 들어왔습니다.";
        else    tmp+="님이 나갔습니다.";
        answer.push_back(tmp);
    }
    return answer;
}