#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class file{
public:
    string origin,head;
    int num;
    file(string s){
        int i=0;
        this->origin=s;
        while(i<s.size()){
            if('0'<=s[i]&&s[i]<='9')    break;
            else if('A'<=s[i]&&s[i]<='Z')    this->head+=(s[i]-'A'+'a');
            else    this->head+=s[i];
            i++;
        }
        this->num=stoi(s.substr(i,5));
    }
};

bool cmp(const file & f1,const file & f2){
    if(f1.head==f2.head)  return f1.num<f2.num;
    return f1.head<f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> F;
    for(auto s : files)
        F.emplace_back(file(s));
    stable_sort(F.begin(),F.end(),cmp);
    for(auto f : F)
        answer.emplace_back(f.origin);
    return answer;
}