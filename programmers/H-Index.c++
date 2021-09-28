/*#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer=0,i=0;
    sort(citations.begin(),citations.end());
    for(int a : citations){
        if(a<=citations.size()-i)   answer=a;
        else break;
        i++;
    }
    while(answer<citations[i]){
        if(answer+1>citations.size()-i) break;
        answer++;
    }
    return answer;
}*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); ++i)
        if (citations[i] < i + 1) return i;
    return citations.size();
}