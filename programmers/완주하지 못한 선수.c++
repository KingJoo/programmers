#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    int s=participant.size()-1;
    for(int i=0;i<s;i++){
        if(participant[i]!=completion[i]){
            answer=participant[i];
            break;
        }
    }
    if(answer=="")  answer=participant[s];
    return answer;
}