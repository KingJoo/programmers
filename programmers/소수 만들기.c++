#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int ck[3001];

int solution(vector<int> nums) {
    int answer = 0;
    for(int i=2;i<=sqrt(3001);i++){
        if(ck[i])   continue;
        for(int j=i*i;j<3001;j+=i)
            ck[j]=true;
    }
    
    for(int i=0;i<nums.size()-2;i++)
        for(int j=i+1;j<nums.size()-1;j++)
            for(int k=j+1;k<nums.size();k++)
                if(!ck[nums[i]+nums[j]+nums[k]]) answer++;
    return answer;
}