#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int t=x,sum=0;
    while(t){
        sum+=(t%10);
        t/=10;
    }
    return x%sum==0;
}