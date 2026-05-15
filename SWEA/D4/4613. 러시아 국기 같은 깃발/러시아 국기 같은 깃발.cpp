#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;


/* 색칠 과정 출력용 함수 */
void test_output(vector<vector<string>>& flag) {
	for (int i = 0; i < flag.size(); i++) {
		for (int j = 0; j < flag[i].size(); j++) {
			cout << flag[i][j];
		}
		cout << endl;
	}
}


/* 색 칠하기 */
long long color_change(vector<vector<string>> flag, int start_row, int end_row, string color) {
	
	long long cnt = 0;
	for (int i = start_row; i <= end_row; i++) {
		for (int j = 0; j < flag[i].size(); j++) {
			if (flag[i][j] != color) {
				flag[i][j] = color;
				cnt++;
			}
		}
	}

	//cout << "color: " << color << ", cnt: " << cnt << endl;
	//test_output(flag);
	//cout << "\n";

	return cnt;
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, m;
		cin >> n >> m;

		vector<vector<string>> flag(n, vector<string>(m));
		for (int i = 0; i < n; i++) {
			string input;
			cin >> input;

			for (int j = 0; j < m; j++) {
				flag[i][j] = input[j];
			}
		}


		long long answer = LLONG_MAX;
		// 0 ~ n - 3까지 흰색으로 칠하기
		for (int i = 0; i < n - 2; i++) {
			long long white_cnt = 0;
			vector<vector<string>> flag_copy = flag;
			white_cnt += color_change(flag_copy, 0, i, "W");

			// i + 1 ~ n - 2까지 파란색으로 칠하기
			for (int j = i + 1; j < n - 1; j++) {
				long long cnt = white_cnt;
				cnt += color_change(flag_copy, i + 1, j, "B");

				// 나머지 빨간색으로 칠하기
				cnt += color_change(flag_copy, j + 1, n - 1, "R");

				answer = min(answer, cnt);
			}
		}

		cout << "#" << t << " " << answer << endl;
	}
}