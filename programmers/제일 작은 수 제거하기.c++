#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min=0x7fffffff;
    for(int a : arr)
        min=min<a?min:a;
    for(int a : arr)
        if(a!=min)  answer.push_back(a);
    if(answer.empty())  answer.push_back(-1);
    return answer;
}