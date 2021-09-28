#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int min=s.size();
    string tmp;
    int tmpC,tmpMin;
    for(int i=1;i<=s.size()>>1;i++){
        tmp=s.substr(0,i);
        tmpC=1;
        tmpMin=0;
        for(int j=i;j<s.size();j+=i){
            if(s.substr(j,i)==tmp)  tmpC++;
            else{
                tmpMin+=i;
                if(tmpC>999)  tmpMin+=4;
                else if(tmpC>99) tmpMin+=3;
                else if(tmpC>9)    tmpMin+=2;
                else if(tmpC>1)    tmpMin+=1;
                tmp=s.substr(j,i);
                tmpC=1;
            }
        }
        if(tmpC==1) tmpMin+=tmp.size();
        else{
            tmpMin+=i;
            if(tmpC>999)  tmpMin+=4;
            else if(tmpC>99) tmpMin+=3;
            else if(tmpC>9)    tmpMin+=2;
            else    tmpMin+=1;
        }
        min=min<tmpMin?min:tmpMin;
    }
    return min;
}