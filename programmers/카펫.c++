#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int AplusB=(brown-4)>>1;
    for(int i=1;i<=(AplusB+1)>>1;i++){
        if(i*(AplusB-i)==yellow){
            answer.emplace_back(AplusB-i+2);
            answer.emplace_back(i+2);
            return answer;
        }
    }
}