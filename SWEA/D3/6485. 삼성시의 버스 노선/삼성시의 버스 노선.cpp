#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		// 각 버스의 노선 정보 입력
		vector<pair<int, int>> lines(n);
		for (int i = 0; i < n; i++) {
			cin >> lines[i].first >> lines[i].second;
		}

		// 정류장 개수 입력
		int station_cnt;
		cin >> station_cnt;

		// 정류장 별 필요 비용(?) 입력
		vector<int> station_values(station_cnt);
		for (int i = 0; i < station_cnt; i++) {
			cin >> station_values[i];
		}

		// 정류장 별 방문 버스 개수 계산
		vector<int> answer(station_cnt, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < station_cnt; j++) {
				if (lines[i].first <= station_values[j] && station_values[j] <= lines[i].second) {
					answer[j]++;
				}
			}
		}

		// 출력
		cout << "#" << t << " ";
		for (int i = 0; i < station_cnt; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
}