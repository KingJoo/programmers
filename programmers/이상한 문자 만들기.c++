#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool even=false;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ')
            even=!even;
        else{
            even=false;
            continue;
        }
        if(even&&s[i]>='a')
            s[i]-=('a'-'A');
        if(!even&&s[i]<='Z')
            s[i]+=('a'-'A');
    }
    return s;
}