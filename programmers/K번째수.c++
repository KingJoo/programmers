#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int arr[100],range,start;
    for(int i=0;i<commands.size();i++){
        range = commands[i][1]-commands[i][0]+1;
        start = commands[i][0]-1;
        for(int j=0;j<range;j++)
            arr[j]=array[start++];
        sort(arr,arr+range);
        answer.push_back(arr[commands[i][2]-1]);
    }
    return answer;
}