#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long a=x;
    for(int i=0;i<n;i++){
        answer.emplace_back(a);
        a+=x;
    }
    return answer;
}