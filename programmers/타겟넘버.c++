#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int size=1<<numbers.size();
    int tmp,res=0;
    for(int i=1;i<size;i++){
        tmp=0;
        for(int j=0;j<numbers.size();j++){
            if(i&(1<<j))    tmp+=numbers[j];
            else    tmp-=numbers[j];
        }
        if(tmp==target) res++;
    }
    return res;
}