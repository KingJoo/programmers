#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int max,min,rem;
    if(n>m){
        max=n;
        min=m;
    }
    else{
        max=m;
        min=n;
    }
    while(1){
        rem=max%min;
        if(rem==0){
            answer.emplace_back(min);
            break;
        }
        max=min;
        min=rem;
    }
    answer.emplace_back(n*m/answer[0]);
    return answer;
}