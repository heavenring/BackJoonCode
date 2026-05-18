#include <iostream>
#include <queue>
#include <vector>

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

			que.push({ {start / 2, end / 2}, 1 });
		}


		int answer = 0;
		vector<int> move(201);
		while (!que.empty()) {
			int start = que.front().first.first;
			int end = que.front().first.second;

			answer = que.front().second;
			que.pop();

			// 이동 경로 확인
			for (int i = start; i <= end; i++) {
				// 현재 단위시간에 이동한 경로일 경우
				if (move[i] == answer) {
					// 이동 초기화
					for (int j = start; j < i; j++) {
						move[j]--;
					}

					// 다음 단위 시간에 이동
					que.push({ {start, end}, answer + 1 });
				}
				else {
					move[i] = answer;
				}
			}

		}

		cout << "#" << t << " " << answer << "\n";
	}
}