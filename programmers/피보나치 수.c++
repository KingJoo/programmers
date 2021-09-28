#include<vector>
using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator* (const matrix &b) const{
  int n = b.size();
  matrix a(n, vector<long long>(n));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      for(int k=0; k<n; k++)
        a[i][j] += a[i][k] * b[k][j];
  return a;
}

long long fibonacci(int n)
{
  matrix res = {{1, 0},{0, 1}};
  matrix fib = {{1, 1},{1, 0}};
  while(n) {
    if(n&1) res *= fib;
    fib = fib *fib;
    n >>= 1;
  }
  return res[0][1];
}

int solution(int n){ 
    return (int)fibonacci(n);
}