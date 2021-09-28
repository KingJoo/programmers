#include <vector>
#include <algorithm>
 
using namespace std;
vector<int> parent;

bool cmp(vector<int> a, vector<int> b) {return a[2] < b[2];}
int getParent(int x) {return parent[x] == x ? x : getParent(parent[x]);}
bool find(int a,int b) {return getParent(a) != getParent(b);}
void unionParent(int a,int b) {
    a=getParent(a);
    b=getParent(b);
    a<b?parent[b]=a:parent[a]=b;
    return;
}
 
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    parent=vector<int>(n);
    for(int i = 0; i < n; i++)  parent[i]=i;
    for(auto a : costs) {
        if(find(a[0],a[1])){
            answer+=a[2];
            unionParent(a[0],a[1]);
        }
    }
    return answer;
}