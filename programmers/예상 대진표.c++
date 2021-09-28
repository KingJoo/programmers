#include <iostream>

using namespace std;

int solution(int n, int a, int b){
    int answer=0;
    if(a>b){a^=b;b^=a;a^=b;}
    while(++answer){
        if(a+1==b&&(a&1))    break;
        if(a&1) a-=a>>1;    else    a>>=1;
        if(b&1) b-=b>>1;    else    b>>=1;
    }
    return answer;
}