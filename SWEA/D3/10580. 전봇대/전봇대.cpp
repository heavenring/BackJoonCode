#include <iostream>
#include <vector>

using namespace std;

/* 교차한 선 개수 반환 */
int get_cross_cnt(vector<pair<int, int>>& line) {
	int cnt = 0;
	for (int i = 0; i < line.size(); i++) {
		for (int j = i + 1; j < line.size(); j++) {
			if ((line[i].first < line[j].first && line[i].second > line[j].second) ||
				(line[i].first > line[j].first && line[i].second < line[j].second)) {
				cnt++;
			}
		}
	}

	return cnt;
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<pair<int, int>> line(n);
		for (int i = 0; i < n; i++) {
			cin >> line[i].first >> line[i].second;
		}

		int answer = get_cross_cnt(line);
		cout << "#" << t << " " << answer << "\n";
	}
}