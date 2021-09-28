#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer="";
    int ansScore=0;
    
    for(string s:table){
        int score=5;
        stringstream ss(s);
        string token;
        getline(ss,token,' ');
        string tName=token;
        int tScore=0;
        while(getline(ss,token,' ')){
            string l=token;
            for(int i=0;i<languages.size();i++){
                if(l==languages[i]){
                    tScore+=score*preference[i];
                    break;
                }
            }
            score--;
        }
        if(tScore>ansScore){
            ansScore=tScore;
            answer=tName;
        }
        else if(tScore==ansScore)
            answer=answer<tName?answer:tName;
    }
    return answer;
}