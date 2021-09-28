#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    vector<bool> a(n+1,0);
    int c=0;
    for(int i=2;i<=sqrt(n);i++)
        if(!a[i])
            for(int j=i+i;j<=n;j+=i)
                a[j]=1;
    for(int i=2;i<=n;i++)
        if(!a[i])   c++;
    return c;
}