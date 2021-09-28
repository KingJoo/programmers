#include <string>

using namespace std;

int solution(string dartResult) {
    int answer=0,i=0,e=0,f=0;
    while(i<dartResult.size()){
        answer+=f;  f=e;
        
        //숫자
        if(dartResult[i]=='1'&&dartResult[i+1]=='0'){e=10;i++;}
        else    e=dartResult[i]-'0';
        i++;
        
        //영어
        if(dartResult[i]=='D')  e*=e;
        else if(dartResult[i]=='T') e*=e*e;
        i++;
        
        //기호
        if(dartResult[i]=='*'){f<<=1;e<<=1;i++;}
        else if(dartResult[i]=='#'){e=-e;i++;}
    }
    answer+=f+e;
    return answer;
}