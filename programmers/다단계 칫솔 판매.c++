#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string,int> idx;
vector<int> parent,ans;

void sell(int sellerIdx,int cost){
    int pCost=cost/10;
    ans[sellerIdx]+=(cost-pCost);
    if(parent[sellerIdx]==sellerIdx||pCost==0)    return;
    sell(parent[sellerIdx],pCost);
    return;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    ans.resize(enroll.size());
    parent.resize(enroll.size());
    
    for(int i=0;i<enroll.size();i++)
        idx[enroll[i]]=i;
    
    for(int i=0;i<referral.size();i++)
        if(referral[i]=="-")    parent[i]=i;
        else    parent[i]=idx[referral[i]];
    
    for(int i=0;i<seller.size();i++)
        sell(idx[seller[i]],amount[i]*100);
    
    return ans;
}