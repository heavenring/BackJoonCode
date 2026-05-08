#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/* 빈 주차 공간 찾기 */
int find_empty_idx(vector<int>& parking) {
	
	for (int i = 0; i < parking.size(); i++) {
		if (!parking[i]) {
			return i;
		}
	}

	return -1;
}


/* 주차 차량의 인덱스 탐색 */
int find_car_idx(vector<int>& parking, int car_num) {

	for (int i = 0; i < parking.size(); i++) {
		if (parking[i] == car_num) {
			return i;
		}
	}

	return -1;
}



int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, m;
		cin >> n >> m;

		// 주차 요금
		vector<int> price(n);
		for (int i = 0; i < n; i++) {
			cin >> price[i];
		}

		// 주차 현황
		vector<int> parking(n);

		// 차량 무게
		vector<int> car_weight(m + 1);
		for (int i = 1; i <= m; i++) {
			cin >> car_weight[i];
		}

		// 차량 대기
		queue<int> waiting;

		// 명령 처리
		long long answer = 0;
		for (int i = 0; i < m * 2; i++) {
			int car_num;
			cin >> car_num;

			if (car_num > 0) {
				int idx = find_empty_idx(parking);
				if (idx != -1) {
					parking[idx] = car_num;
					answer += price[idx] * car_weight[car_num];
				} else {
					waiting.push(car_num);
				}
			} else if (car_num < 0) {
				int idx = find_car_idx(parking, -car_num);
				parking[idx] = 0;

				if (!waiting.empty()) {
					int next_car = waiting.front();
					waiting.pop();

					parking[idx] = next_car;
					answer += price[idx] * car_weight[next_car];
				}
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}