#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    double a=pow(n,0.5);
    return  a!=(int)a?-1:(long long)(a+1)*(a+1);
}