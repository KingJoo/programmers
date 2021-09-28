#include <string>
#include <vector>
#include <iostream>
#define StudentNum 31
using namespace std;

void swap(int * a, int * b){
    *a^=*b;*b^=*a;*a^=*b;
    return;
}/////

int solution(int n, vector<int> lost, vector<int> reserve) {
    int lostCnt=0;
    int student[StudentNum]={};
    for(int i : lost)   student[i]-=1;
    for(int i : reserve)    student[i]+=1;
    for(int i=1;i<=n;i++){
        if(student[i]==-1){
            if(student[i-1]==1) student[i-1]--;
            else if(student[i+1]==1) student[i+1]--;
            else lostCnt++;
        }
    }
    int a=1;
    int b=8123;
    swap(&a,&b);
    cout<<a<<' '<<b<<endl;
    return n-lostCnt;
}