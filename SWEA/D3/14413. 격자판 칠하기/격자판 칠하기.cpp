#include <iostream>
#include <vector>

using namespace std;


/* 첫번째 색 블록의 좌표 및 색 반환 */
pair<pair<int, int>, string> find_first_block(const vector<vector<string>>& board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == "#" || board[i][j] == ".") {
				return {{i, j}, board[i][j]};
			}
		}
	}

	return {{-1, -1}, ""};
}



int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, m;
		cin >> n >> m;

		vector<vector<string>> board(n, vector<string>(m));
		for (int i = 0; i < n; i++) {
			string input;
			cin >> input;

			for (int j = 0; j < m; j++) {
				board[i][j] = input[j];
			}
		}

		/**
		* 격자판 내 첫번째 검은 정사각형의 위치를 찾는다.
		* 0번째 인덱스의 짝수 번째에 있을 때
		* 짝수 인덱스의 홀수 번째에 검은색이 있으면 안된다
		* 짝수 인덱스에 짝수 번째에 검은색이 있을 때
		* 짝수 인덱스의 홀수 번쨰에 검은색이 있으면 안된다
		* 즉 (i + j) % 2 == 0 이 검은색 일 때, 
		* ㄴ (i + j) % 2 == 1인 검은색이 존재하거나 (i + j) % 2 == 0인 흰색이 존재한다면 실패
		* 이는 흰색도 규칙이 동일하다
		* 
		* 고로, 보드를 전탐하며 # or .인 경우를 찾아 좌표와 색을 저장 후
		* 기준 좌표와 동일할 떄는 색이 같아야 하고, 다를 때는 색이 다른 경우를 체크한다.
		* 
		*/

		pair<pair<int, int>, string> first_block;
		first_block = find_first_block(board);

		// 블록의 색이 정해진게 없다면, 모든 칸이 빈칸이므로 가능
		bool possible = true;
		if (first_block.first.first != -1) {
			int base_i = first_block.first.first;
			int base_j = first_block.first.second;
			string base_color = first_block.second;

			for (int i = 0; i < n && possible; i++) {
				for (int j = 0; j < m && possible; j++) {
					// 현재 칸의 색이 정해져 있을 때
					if (board[i][j] == "#" || board[i][j] == ".") {

						// 같은 색 배열에 있어야할 때
						if ((i + j) % 2 == (base_i + base_j) % 2) {
							// 다른 색이 해당 위치에 있을 경우 불가능
							if (board[i][j] != base_color) {
								possible = false;
							}
						} else {
							// 다른 색 배열에 있어야할 때
							// 같은 색이 해당 위치에 있을 경우 불가능
							if (board[i][j] == base_color) {
								possible = false;
							}
						}
					}
				}
			}
		}

		cout << "#" << t << " " << (possible ? "possible" : "impossible") << endl;
	}
}