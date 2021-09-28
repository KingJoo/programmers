#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int no = 0, sk[26]={},order;
    for(int i=0;i<skill.size();i++)
        sk[skill[i]-'A']=i+1;
    for(string s : skill_trees){
        order=1;
        for(int i=0;i<s.size();i++){
            if(sk[s[i]-'A']==0) continue;
            if(sk[s[i]-'A']==order) order++;
            else{no++;break;}
        }
    }
    return skill_trees.size()-no;
}