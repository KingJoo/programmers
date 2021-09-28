#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string &a,string &b){
    return a.size()<b.size();
}

bool isBeing(vector<int> &ans, vector<bool> &ck,int val){
    for(int i=0;i<ck.size();i++){
        if(ck[i])   continue;
        if(ans[i]==val){
            ck[i]=true;
            return true;
        }
    }
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> str;
    stringstream ss(s.substr(0,s.size()-1));
    string token;
    while (getline(ss, token, '}'))
        str.emplace_back(token.substr(2));
    sort(str.begin(),str.end(),cmp);
    answer.emplace_back(stoi(str[0]));
    for(int i=1;i<str.size();i++){
        stringstream ss(str[i]);
        vector<bool> ck(i);
        bool same=false;
        while(getline(ss,token,',')){
            if(!isBeing(answer,ck,stoi(token))){
                answer.emplace_back(stoi(token));
                break;
            }
        }
    }
    return answer;
}