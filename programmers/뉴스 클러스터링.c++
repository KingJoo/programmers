#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 65536;
    transform(str1.begin(),str1.end(),str1.begin(),::tolower);
    transform(str2.begin(),str2.end(),str2.begin(),::tolower);
    unordered_map<string,int> um;
    int t=0,ab=0;
    for(int i=0;i<str1.size()-1;i++){
        if('a'<=str1[i]&&str1[i]<='z'&&'a'<=str1[i+1]&&str1[i+1]<='z'){
            t++;
            if(!um.count(str1.substr(i,2)))   um[str1.substr(i,2)]=1;
            else    um[str1.substr(i,2)]++;
        }
    }
    for(int i=0;i<str2.size()-1;i++){
        if('a'<=str2[i]&&str2[i]<='z'&&'a'<=str2[i+1]&&str2[i+1]<='z'){
            t++;
            if(!um.count(str2.substr(i,2))||um[str2.substr(i,2)]==0)  continue;
            um[str2.substr(i,2)]--;
            ab++;
        }
    }
    if(t!=ab)   answer=(ab*65536)/(t-ab);
    return answer;
}