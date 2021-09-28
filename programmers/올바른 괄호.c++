#include <string>
#include <stack>

using namespace std;

bool solution(string s){
    stack<char> st;
    for(char c:s){
        if(st.empty()||c=='(')  st.push(c);
        else if(st.top()=='(')    st.pop();
    }
    return st.empty();
}