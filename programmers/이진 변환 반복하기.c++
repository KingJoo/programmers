#include <string>
#include <vector>

using namespace std;

int cnt(int& a1, string s){
    int c=0;
    for(char ch:s)
        if(ch=='1')  c++;
        else    a1++;
    return c;
}

string toBinaryStr(int i){
    string s="";
    while(i){
        if(i&1) s+="1";
        else    s+="0";
        i>>=1;
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(s!="1"){
        s=toBinaryStr(cnt(answer[1],s));
        answer[0]++;
    }
    return answer;
}