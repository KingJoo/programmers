#include <string>
#include <vector>

int _5[5]={1,};

using namespace std;

void init(){
    for(int i=1;i<5;i++)
        _5[i]=_5[i-1]*5;
    for(int i=1;i<5;i++)
        _5[i]+=_5[i-1];
}

int solution(string word) {
    int answer=0;
    int len=word.length();
    init();
    for(int i=0;i<len;i++){
        int a=0;
        if(word[i]=='A')    a=0;
        else if(word[i]=='E')    a=1;
        else if(word[i]=='I')   a=2;
        else if(word[i]=='O')   a=3;
        else    a=4;
        answer+=a*_5[4-i];
    }
    return answer+len;
}