#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int len=scores[0].size(),up,down,total,avg;
    for(int j=0;j<len;j++){
        up=down=total=0;
        for(int i=0;i<len;i++){
            total+=scores[i][j];
            if(scores[i][j]<scores[j][j]) up++;
            else if(scores[i][j]>scores[j][j]) down++;
        }
        if(up==len-1||down==len-1) avg=(total-scores[j][j])/(len-1);
        else avg=total/len;
        if(avg>=90) answer+='A';
        else if(avg>=80) answer+='B';
        else if(avg>=70) answer+='C';
        else if(avg>=50) answer+='D';
        else answer+='F';
    }
    return answer;
}