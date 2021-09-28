#include <string>
using namespace std;

class Stack{
public:
    char a[1000001];int t=-1;
    bool empty(){return t==-1?true:false;}
    void push(char c){a[++t]=c;}
    void pop(){t--;}
    char top(){return a[t];}
};

int solution(string s){
    Stack st;
    for(char c:s){
        if(st.empty())  st.push(c);
        else{
            if(st.top()==c) st.pop();
            else    st.push(c);
        }
    }
    return st.empty()?1:0;
}