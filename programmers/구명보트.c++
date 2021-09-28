#include <vector>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector<int> kg(241);
    for(int &i:people)  kg[i]++;
    for(int i=40;i<=240;i++){
        if(kg[i]==0)   continue;
        if(limit<(i<<1)){answer+=kg[i];continue;}
        for(int j=limit-i;j>=i;j--){
            if(kg[j]==0)    continue;
            if(i==j){answer+=(kg[i]&1)+(kg[i]>>1);break;}
            if(kg[i]<=kg[j]){answer+=kg[i];kg[j]-=kg[i];break;}
            else{answer+=kg[j];kg[i]-=kg[j];kg[j]=0;}
        }
    }
    return answer;
}