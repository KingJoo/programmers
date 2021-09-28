#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0;i<new_id.size();i++){
        //1
        if('A'<=new_id[i]&&new_id[i]<='Z')
            answer+=(new_id[i]-'A'+'a');
        //2
        else if(('a'<=new_id[i]&&new_id[i]<='z')||
                ('0'<=new_id[i]&&new_id[i]<='9')||
                new_id[i]=='-'||new_id[i]=='_')
            answer+=new_id[i];
        //3
        else if(new_id[i]=='.'&&answer.back()!='.')
            answer+='.';
    }
    //4
    if(answer.front()=='.') answer=answer.substr(1);
    if(answer.back()=='.')  answer.pop_back();
    //5
    if(answer.empty())  answer+='a';
    //6
    if(answer.size()>15){
        answer=answer.substr(0,15);
        if(answer.back()=='.')  answer.pop_back();
    }
    //7
    while(answer.size()<3)  answer+=answer.back();
    
    return answer;
}