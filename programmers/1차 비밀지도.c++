#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++){
        string s="";
        arr1[i]|=arr2[i];
        for(int j=n-1;j>=0;j--){
            arr1[i]&1?s='#'+s:s=' '+s;
            arr1[i]>>=1;
        }
        answer.emplace_back(s);
    }
    return answer;
}