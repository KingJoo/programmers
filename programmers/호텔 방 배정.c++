#include <vector>
#include <unordered_map>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, int> um;
    for(auto a:room_number){
        while(um.count(a)!=0)   a+=um[a]++;
        um[a]=1;
        answer.emplace_back(a);
    }
    return answer;
}