#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1[5]={1,2,3,4,5};
    int p2[8]={2,1,2,3,2,4,2,5};
    int p3[10]={3,3,1,1,2,2,4,4,5,5};
    int per[3]={};
    for(int i=0;i<answers.size();i++){
        if(p1[i%5]==answers[i]) per[0]++;
        if(p2[i%8]==answers[i]) per[1]++;
        if(p3[i%10]==answers[i])    per[2]++;
    }
    int mx=per[0]>per[1]?per[0]:per[1];
    mx=mx>per[2]?mx:per[2];
    for(int i=0;i<3;i++)
        if(mx==per[i])  answer.push_back(i+1);
    return answer;
}