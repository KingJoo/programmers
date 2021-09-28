#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> st;
    int n=board.size();
    int tmp;
    for(int i=0;i<moves.size();i++){
        tmp=0;
        for(int j=0;j<n;j++){
            if(board[j][moves[i]-1]){
                tmp=board[j][moves[i]-1];
                board[j][moves[i]-1]=0;
                break;
            }
        }
        if(tmp){
            if(st.size()&&st.back()==tmp){
                answer+=2;
                st.pop_back();
            }
            else    st.push_back(tmp);
        }
    }
    return answer;
}