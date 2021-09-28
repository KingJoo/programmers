#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){return a+b>b+a;}

string solution(vector<int> numbers) {
    vector<string> n;
    for(auto a: numbers)    n.emplace_back(to_string(a));
    sort(n.begin(),n.end(),cmp);
    if(n[0]=="0")   return "0";
    string answer = "";
    for(auto a:n)   answer+=a;
    return answer;
}