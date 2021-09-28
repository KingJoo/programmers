#include <string>
#include <vector>
#include <regex>

using namespace std;

vector<string> n={"zero","one","two","three","four","five","six","seven","eight","nine","ten"};

int solution(string s) {
    for(int i = 0; i < n.size(); i++)
        s = regex_replace(s, regex(n[i]), to_string(i));
    return stoi(s);
}