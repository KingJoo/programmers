#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer=0,sum=0;
    sort(d.begin(),d.end());
    for(int a:d){
        sum+=a;
        if(sum>budget)  break;
        answer++;
    }
    return answer;
}