#include <string>
#include <vector>

using namespace std;
int ranking[]={6,6,5,4,3,2,1};
bool winNum[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    int winC=0,zeroC=0;
    for(int w:win_nums)
        winNum[w]=true;
    for(int my:lottos){
        if(my==0)   zeroC++;
        else if(winNum[my]) winC++;
    }
    answer[0]=ranking[winC+zeroC];
    answer[1]=ranking[winC];
    return answer;
}