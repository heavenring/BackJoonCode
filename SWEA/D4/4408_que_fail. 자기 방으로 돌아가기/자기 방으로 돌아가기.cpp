#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		
		// 방 번호 정보 및 단위시간 입력
		queue<pair<pair<int, int>, int>> que;
		for (int i = 0; i < n; i++) {
			int start, end;
			cin >> start >> end;
			
			que.push({ {(min(start, end) - 1) / 2, (max(start, end) - 1) / 2}, 1 });
		}

		/**
		* 각 시간별 방의 이동 범위를 기록해야 한다
		* min, max로 기록하려 했으나, 이동 구간이 나뉘어 있을 수 있으므로 안된다
		* ex) 1 ~ 6,  99 ~ 110 구간을 이동했다면 -> 7 ~ 98 구간 이동 가능
		* 
		* vector를 통해 이동 구간 기록은 안된다 -> 시간 초과
		* 
		* que를 통한 구간 기록 시도
		* 1. que에 시작 ~ 끝의 구간을 기록한다
		* 2. que의 크기만큼 반복시켜 que에 있는 구간 기록을 모두 확인한다
		* 3. min_area, max_area에 구간을 저장하며
		* 4. 만일, 모든 범위에 포함되지 않았을 경우 que에 해당 범위를 저장한다
		* 5. 단위 시간이 변경될 경우 que도 초기화한다
		* 
		*/


		int answer = 0;
		queue<pair<int, int>> log_que;
		while (!que.empty()) {
			int start = que.front().first.first;
			int end = que.front().first.second;
			int time = que.front().second;
			que.pop();

			//cout << "now student: (" << start << ", " << end << ")\n";

			//cout << "time: " << time << "\n";
			if (answer != time) {
				answer = time;

				// 로그 큐 초기화
				while (!log_que.empty()) {
					log_que.pop();
				}

				// 현재 기록 추가
				log_que.push({ start, end });
				continue;
			}

			//cout << "log check\n";
			bool check = true;
			int lq_size = log_que.size();
			for (int i = 0; i < lq_size; i++) {
				int min_area = log_que.front().first;
				int max_area = log_que.front().second;
				log_que.pop();
				log_que.push({ min_area, max_area });

				//cout << "now log check: (" << min_area << ", " << max_area << ")\n";
				// 시작 방 번호 or 도착 방 번호가 범위안에 있다면
				if ((start >= min_area && start <= max_area) 
					|| (end >= min_area && end <= max_area) 
					|| (start <= min_area && end >= max_area)) {

					//cout << "over area\n";
					// 다음 단위 시간으로 넘김
					que.push({ {start, end}, time + 1 });
					check = false;
					break;
				} 
			}

			if (check) {
				log_que.push({ start, end });
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}