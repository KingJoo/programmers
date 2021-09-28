#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	if (get<0>(a) == get<0>(b)) {
		if (get<1>(a) == get<1>(b))	return get<2>(a) < get<2>(b);
		else return get<1>(a) > get<1>(b);
	}
	else return get<0>(a) > get<0>(b);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m;
	//장르,장르합
	for (int i = 0; i < plays.size(); i++)
		m[genres[i]] += plays[i];
	//장르합,횟수,고유번호
    vector<tuple<int, int, int>> v;
	for (int i = 0; i < plays.size(); i++)
		v.push_back({m[genres[i]],plays[i],i});
	//정렬및 정답넣기
	sort(v.begin(),v.end(),cmp);
	int sum = 0, cnt = 0;
	for (auto t : v) {
		if (sum != get<0>(t)) {
			sum = get<0>(t);
			cnt=1;
			answer.push_back(get<2>(t));
		}
		else {
			if (cnt == 1) {
				cnt++;
				answer.push_back(get<2>(t));
			}
		}
	}
	return answer;
}