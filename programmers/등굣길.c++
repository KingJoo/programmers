#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> M(n,vector<int>(m));
    M[0][0]=1;
    for(auto a:puddles)
        M[a.at(1)-1][a.at(0)-1]=-1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==-1){
                M[i][j]=0;
                continue;
            }
            if(i!=0)    M[i][j]+=M[i-1][j]%1000000007;
            if(j!=0)    M[i][j]+=M[i][j-1]%1000000007;
        }
    }
    return M[n-1][m-1]%1000000007;
}