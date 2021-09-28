#include <iostream>

using namespace std;
int solution(int n){
    int a=0;
    while(n){
        a+=(n%10);
        n/=10;
    }
    return a;
}