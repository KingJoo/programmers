#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool upper=true;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){upper=true;continue;}
        if(upper){
            if('a'<=s[i]&&s[i]<='z')    s[i]=s[i]-'a'+'A';
            upper=false;
        }
        else if('A'<=s[i]&&s[i]<='Z')    s[i]=s[i]-'A'+'a';
    }
    return s;
}