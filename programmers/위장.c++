#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int r=1;
    unordered_map<string,int> m;
    for(vector<string> v:clothes)
        m[v[1]]++;
    for(pair<string,int> t:m)
        r*=(t.second+1);
    if(r!=1)    r--;
    return r;
}