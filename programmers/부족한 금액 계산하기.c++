using namespace std;

long long solution(int price, int money, int count){
    long long answer = ((count+1)*count)>>1;
    answer=answer*price-money;
    return answer>0?answer:0;
}