#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
typedef struct{int y,x;}P;
P pad[]={{4,2},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}},l={4,1},r={4,3};
string answer = "";

inline void select(int n,char c){
    if(c=='l'){answer+="L";l=pad[n];}
    else{answer+="R";r=pad[n];}
    return;
}

string solution(vector<int> numbers, string hand) {
    int ll,rl;
    for(int n:numbers){
        if(n==1||n==4||n==7)    select(n,'l');
        else if(n==3||n==6||n==9)   select(n,'r');
        else{
            ll=pad[n].x-l.x+abs(pad[n].y-l.y);
            rl=r.x-pad[n].x+abs(r.y-pad[n].y);
            if(ll==rl)  hand=="left"?select(n,'l'):select(n,'r');
            else    rl>ll?select(n,'l'):select(n,'r');
        }
    }
    return answer;
}