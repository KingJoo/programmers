#include <vector>
using namespace std;

vector<int> solution(vector<int> arr){
    vector<int> answer;
    int tmp=arr[0];
    answer.push_back(tmp);
    for(int i=1;i<arr.size();i++){
        if(tmp!=arr[i]){
            tmp=arr[i];
            answer.push_back(tmp);
        }
    }
    return answer;
}