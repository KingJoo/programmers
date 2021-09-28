#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer=0,min=20;
    for(char c : name){
        if(c<='N')  answer+=(int)c-'A';
        else answer+='Z'-(int)c+1;
    }
    for(int i=0;i<name.size()>>1;i++){
        int Acnt=0;
        int j=i+1;
        int m=(i<<1)+name.size()-j;
        while(j<name.size()){
            if(name[j++]=='A')    Acnt++;
            else break;
        }
        m-=Acnt;
        min=min<m?min:m;
    }
    return answer+min;
}