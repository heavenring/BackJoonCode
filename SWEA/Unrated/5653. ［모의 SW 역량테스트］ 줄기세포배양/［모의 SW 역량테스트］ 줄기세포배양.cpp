#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define cell_size 500
#define offset cell_size / 2

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, m, k;
		cin >> n >> m >> k;

		queue<pair<int, int>> que;
		vector<vector<pair<int, int>>> cell(cell_size, vector<pair<int, int>>(cell_size, {0, 0}));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> cell[i + offset][j + offset].first;

				if (cell[i + offset][j + offset].first > 0) {
					que.push({ i + offset, j + offset });
				}
			}
		}

		for (int i = 0; i < k; i++) {
			int que_size = que.size();
			for (int j = 0; j < que_size; j++) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				// 세포가 생존한 시간 증가
				cell[x][y].second++;

				// 세포 활성화 후 1시간 뒤 세포 번식
				if (cell[x][y].first + 1 == cell[x][y].second) {
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						// 현재 세대의 세포가 동일 위치에 번식 시도 시, 
						// 생명력이 가장 높은 세포로 갱신
						if (cell[nx][ny].second == -1) {
							cell[nx][ny].first = max(cell[nx][ny].first, cell[x][y].first);
						} else if (cell[nx][ny].first == 0) {
							// 세포가 번식할 수 있는 위치인 경우, 세포 번식
							cell[nx][ny].first = cell[x][y].first;

							// 번식된 세포는 아직 활성화되지 않은 상태
							cell[nx][ny].second = -1; 
							que.push({ nx, ny });
						}
					}
				}

				// 세포가 살아있을 경우, 다음 시간에도 큐에 추가
				if (cell[x][y].first * 2 > cell[x][y].second) {
					que.push({ x, y });
				}
			}

			// 다음 세대의 세포 활성화
			for (int j = 0; j < que.size(); j++) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				if (cell[x][y].second == -1) {
					cell[x][y].second++;
				}

				que.push({ x, y });
			}
		}

		cout << "#" << t << " " << que.size() << "\n";
	}
}