#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    /*
    for(int i=0;i<n>>1;i++)
        answer+="수박";
    if(n&1) answer+="수
    
테스트 1 〉	통과 (0.01ms, 3.94MB)
테스트 2 〉	통과 (0.03ms, 3.83MB)
테스트 3 〉	통과 (0.03ms, 3.93MB)
테스트 4 〉	통과 (0.05ms, 3.97MB)
테스트 5 〉	통과 (0.03ms, 3.96MB)
테스트 6 〉	통과 (0.01ms, 3.94MB)
테스트 7 〉	통과 (0.01ms, 3.79MB)
테스트 8 〉	통과 (0.01ms, 3.93MB)
테스트 9 〉	통과 (0.01ms, 3.93MB)
테스트 10 〉	통과 (0.01ms, 3.93MB)
테스트 11 〉	통과 (0.01ms, 3.93MB)
테스트 12 〉	통과 (0.01ms, 3.93MB)
테스트 13 〉	통과 (0.01ms, 3.97MB)
테스트 14 〉	통과 (0.01ms, 3.93MB)
테스트 15 〉	통과 (0.08ms, 3.97MB)
테스트 16 〉	통과 (0.01ms, 3.94MB)
    */
    for(int i=1;i<=n;i++)
        i&1==1?answer+="수":answer+="박";
    return answer;
}