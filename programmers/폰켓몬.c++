#include <vector>
using namespace std;
bool ck[200001];

int solution(vector<int> nums)
{
    int answer = 0;
    for(int a : nums)
        if(!ck[a]){ck[a]=true;answer++;}
    if(answer>(nums.size()>>1)) answer = nums.size()>>1;
    return answer;
}