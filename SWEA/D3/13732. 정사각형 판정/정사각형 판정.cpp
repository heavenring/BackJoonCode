#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/* 정사각형의 시작점 반환 */
pair<int, int> square_idx(vector<vector<string>>& board) {

	int n = board.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == "#") {
				return { i, j };
			}
		}
	}
}


/* 정사각형 탐색 */
bool square_check(vector<vector<string>>& board, int x, int y, int square_size) {
	//cout << "start idx: " << x << " " << y << "\n";
	bool result = false;
	// 정사각형이 만들어 질 수 있는 크기일 경우 탐색
	if (x + square_size <= board.size() && y + square_size <= board.size()) {
		result = true;
		// 정사각형이 아닐 경우 탐색 종료
		for (int i = x; i < x + square_size && result; i++) {
			for (int j = y; j < y + square_size && result; j++) {

				//cout << "i: " << i << " j: " << j << "\n";
				//cout << "board: " << board[i][j] << "\n\n";
				if (board[i][j] != "#") {
					result = false;
				}
			}
		}
	}

	return result;
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		int cnt = 0;
		vector<vector<string>> board(n, vector<string>(n));
		for (int i = 0; i < n; i++) {
			string input;
			cin >> input;

			for (int j = 0; j < n; j++) {
				board[i][j] = input[j];

				if (board[i][j] == "#") {
					cnt++;
				}
			}
		}

		bool answer = true;
		// #의 개수가 제곱수가 아니라면
		// 정사각형을 만들지 못한다
		if (cnt != (int)sqrt(cnt) * (int)sqrt(cnt)) {
			answer = false;
		}
		else {
			// 정사각형의 시작점 탐색
			pair<int, int> square = square_idx(board);

			// 정사각형 여부 탐색
			answer = square_check(board, square.first, square.second, sqrt(cnt));
		}

		cout << "#" << t << " ";
		if (answer) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}