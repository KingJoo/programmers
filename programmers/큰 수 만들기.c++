/*#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int mxi=0, l=number.size()-k-1;
    char mx=' ';
    while(l>=0){
        for(int i=mxi;i<number.size()-l;i++){
            if(mx<number[i]){
                mx=number[i];
                mxi=i+1;
            }
        }
        answer+=mx;
        mx=' ';
        l--;
    }
    return answer;
}*/
/*
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) { //큰 수 만들기 - success
    string answer = "";
    int size = number.length() - k;
    stack<char> st;
    for(int i = 0; i < number.length(); i++){
        char cur = number.at(i); //처리할 숫자
        while(!st.empty() && k > 0){ //
            char top = st.top(); //스택의 가장 맨 위의 값
            if(top < cur){ //값 비교
                st.pop(); //처리할 값이 더 크기 때문에 pop 수행
                k--; //제거 횟수 감소
            }
            else break; //비교할 때 값이 같거나 스택에 있는 값이 더 큰 경우
        } 
        st.push(cur); //처리하는 값이 큰 경우를 제외하고 모든 경우 스택에 삽입
    }
    //처리하고 남은 스택의 사이즈와 제거하고 남아야하는 수가 같아야함.
    //아닌 경우 같아질 때까지 제거(스택에 남아있다는 것은 제거할 원소보다 이전 원소가 작거나 같다는 의미이므로)
    while(st.size() != size) st.pop(); 
    while(!st.empty()){ //결과값 생성
        answer += st.top();
        st.pop();
    }
    //위에서 거꾸로 값이 이어졌기 때문에 reverse 수행
    reverse(answer.begin(), answer.end()); 
    return answer;
}*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    answer = number.substr(k); 
    int sz = number.size() - k;
    for(int i = k-1;i >=0;i--){
        int j = 0;
        while(1){
            if(number[i] >= answer[j]){
                char temp = answer[j];
                answer[j] = number[i];
                number[i] = temp;
                j++;
            }
            else break;
        }
    }
    return answer;
}