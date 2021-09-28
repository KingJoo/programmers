#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer=0,c;
    for(int i=left;i<=right;i++){
        c=1;
        for(int j=2;j<=i;j++)
            if(i%j==0)  c++;
        if(c&1) answer-=i;
        else answer+=i;
    }
    return answer;
}