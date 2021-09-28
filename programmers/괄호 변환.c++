#include <string>
#include <vector>
using namespace std;

bool isRight(string s){
    int c=0;
    for(char b : s){
        if(b=='(')  c++;
        else    c--;
        if(c<0) return 0;
    }
    return c==0;
}

string solution(string p) {
    //1
    if(p.empty())   return p;
    //2
    string u,v;
    int i,a=0;
    for(i=0;i<p.size();i++){
        if(p[i]=='(')   a--;
        else    a++;
        if(a==0)    break;
    }
    i++;
    u=p.substr(0,i);
    v=p.substr(i);
    //3
    if(isRight(u))  return u+solution(v);
    //4
    for(char &a : u)  a=a=='('?')':'(';
    return "("+solution(v)+")"+u.substr(1,u.size()-2);
}