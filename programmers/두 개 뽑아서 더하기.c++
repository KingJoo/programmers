#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<bool> ck(201,0);
    for(int i=0;i<numbers.size()-1;i++)
        for(int j=i+1;j<numbers.size();j++)
            ck[numbers[i]+numbers[j]]=1;
    vector<int> answer;
    for(int i=0;i<201;i++)
        if(ck[i])   answer.emplace_back(i);
    return answer;
}