#include <string>
#include <vector>
using namespace std;
vector<int> Sum;

int solution(vector<int> cookie) {
    int answer=0, frontSum, backSum, n=cookie.size();
    Sum=vector<int>(n+1,0);
    for(int i=0;i<n;i++)
        Sum[i+1]+=Sum[i]+cookie[i];
    
    for(int s=0;s<n-1;s++){
        for(int e=n-1;e>s;e--){
            frontSum=Sum[e]-Sum[s];
            if(answer>frontSum) break;
            for(int ee=n;ee>e;ee--){
                backSum=Sum[ee]-Sum[e];
                if(frontSum<backSum)    continue;
                else if(frontSum>backSum)   break;
                else    answer=answer<backSum?backSum:answer;
            }
        }
    }
    return answer;
}