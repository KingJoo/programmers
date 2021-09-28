#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    int cur_num=1;
    unordered_map<string,int> dic;
    for(int i=0;i<26;i++){
        string s="";
        s+=(char)('A'+i);
        dic[s]=cur_num++;
    }
    int cur_i=0;
    while(cur_i<msg.size()){
        string w="";
        w+=msg[cur_i++];
        char c=msg[cur_i];
        while(dic.count(w+c)!=0){
            w+=c;
            cur_i++;
            if(cur_i==msg.size())   break;
            c=msg[cur_i];
        }
        answer.emplace_back(dic[w]);
        if(cur_i!=msg.size())   dic[w+c]=cur_num++;   
    }
    return answer;
}