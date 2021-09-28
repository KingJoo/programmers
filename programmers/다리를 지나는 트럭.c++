#include <string>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0, w = 0, remain;
    queue<int> truckQ;
    deque<pair<int, int>> bridgeQ;
    for (auto a : truck_weights)
        truckQ.push(a);
    while (1) {
        if (truckQ.empty()) {
            if (!bridgeQ.empty())
                time += bridgeQ.back().second;
            break;
        }
        if (truckQ.front() + w > weight) {
            remain = bridgeQ.front().second;
            for (auto &a : bridgeQ)
                a.second -= remain;
            w -= bridgeQ.front().first;
            bridgeQ.pop_front();
            time += remain;
            if(truckQ.front() + w <= weight){
                bridgeQ.push_back({truckQ.front(),bridge_length});
                w+=truckQ.front();
                truckQ.pop();
            }
        }
        else {
            time++;
            for (auto &a : bridgeQ)
                a.second--;
            if (bridgeQ.front().second == 0){
                w -= bridgeQ.front().first;
                bridgeQ.pop_front();
            }
            w += truckQ.front();
            bridgeQ.push_back({ truckQ.front(),bridge_length });
            truckQ.pop();
        }
    }
    return time;
}