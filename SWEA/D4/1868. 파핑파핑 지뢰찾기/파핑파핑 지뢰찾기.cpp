#include <iostream>
#include <vector>
#include <string>

using namespace std;


int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };


/* 주변 폭탄 개수 확인 및 폭탄이 없을경우 추가 탐색 */
string zero_boom(vector<vector<string>>& board, int x, int y) {

	int boom_cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) {
			continue;
		}

		if (board[nx][ny] == "*") {
			boom_cnt++;
		} 
	}

	// 주변에 폭탄이 없을경우 주변 8칸도 탐색
	if (!boom_cnt) {
		board[x][y] = "0";

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) {
				continue;
			}

			if (board[nx][ny] == ".") {
				board[nx][ny] = zero_boom(board, nx, ny);
			}
		}
	}

	return to_string(boom_cnt);
}


/* 나머지 폭탄 확인 */
void boom_check(vector<vector<string>>& board, int x, int y) {
	int boom_cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) {
			continue;
		}

		if (board[nx][ny] == "*") {
			boom_cnt++;
		}
	}

	board[x][y] = to_string(boom_cnt);
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<vector<string>> board(n, vector<string>(n));
		for (int i = 0; i < n; i++) {
			string load_map;
			cin >> load_map;

			for (int j = 0; j < n; j++) {
				board[i][j] = load_map[j];
			}
		}

		int answer = 0;
		// 주변에 폭탄이 없는 칸 먼저 확인
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == ".") {
					zero_boom(board, i, j);

					if (board[i][j] == "0") {
						answer++;
					}
				}
			}
		}

		// 나머지 칸 확인
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == ".") {
					boom_check(board, i, j);
					answer++;
				}
			}
		}

		cout << "#" << t << " " << answer << endl;
	}
}