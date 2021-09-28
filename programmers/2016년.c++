#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int m[]={31,29,31,30,31,30,31,31,30,31,30};
    string r[]={"THU","FRI","SAT","SUN","MON","TUE","WED"};
    for(int i=0;i<a-1;i++)
        b+=m[i];
    return r[b%7];
}