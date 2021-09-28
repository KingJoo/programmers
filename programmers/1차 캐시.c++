#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize==0)    return cities.size()*5;
    
    int answer = 0;
    vector<string> cache;
    bool hit;
    
    for(string &s :cities){
        transform(s.begin(),s.end(),s.begin(),::tolower);
        hit=false;
        for(int i=0;i<cache.size();i++){
            if(s==cache[i]){
                cache.emplace_back(s);
                cache.erase(cache.begin()+i);
                hit=true;
                break;
            }
        }
        if(hit) answer++;
        else{
            answer+=5;
            cache.emplace_back(s);
            if(cacheSize<cache.size())  cache.erase(cache.begin());
        }
    }
    return answer;
}