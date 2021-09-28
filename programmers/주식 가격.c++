#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int l=prices.size()-1,s;
    for(int i=0;i<l;i++){
        s=0;
        for(int j=i+1;j<=l;j++){
            if(prices[i]>prices[j]){
                s=j-i;
                break;
            }
        }
        if(s==0)    answer.push_back(l-i);
        else    answer.push_back(s);
    }
    answer.push_back(0);
    return answer;
}