#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


long long answer;


/* 삼각형의 조건 확인 및 넓이 계산 */
void calc(vector<pair<int, int>>& forward, vector<int>& select_idx) {
	long long x_len, y_len;
	bool x_check, y_check;
	x_check = y_check = false;

	int n = select_idx.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// 각 좌표의 평행 여부 확인
			if (forward[select_idx[i]].first == forward[select_idx[j]].first) {
				x_check = true;
				
				// x축과 평행한 삼각형이므로 y_len 계산
				y_len = abs(forward[select_idx[i]].second - forward[select_idx[j]].second);
			} else if (forward[select_idx[i]].second == forward[select_idx[j]].second) {
				y_check = true;

				// y축과 평행한 삼각형이므로 x_len 계산
				x_len = abs(forward[select_idx[i]].first - forward[select_idx[j]].first);
			}
		}
	}

	// x축과 y축이 평행한 삼각형일 경우 넓이 계산
	// 최대 넓이의 2배를 출력해야 하므로 x_len * y_len 계산
	if (x_check && y_check) {
		answer = max(answer, x_len * y_len);
	}
}


/* 3개의 좌표를 선택하는 조합 함수 */
void combination(vector<pair<int, int>>& forward, vector<int>& select_idx, int idx) {

	// 3개의 좌표를 선택한 경우 넓이 계산
	if (select_idx.size() == 3) {
		calc(forward, select_idx);
		return;
	}

	int n = forward.size();
	for (int i = idx; i < n; i++) {
		select_idx.push_back(i);
		combination(forward, select_idx, i + 1);
		select_idx.pop_back();
	}
}


int main() {
	/**
	* 다수의 좌표가 주어졌을 때, 
	* 이 중 3개의 점을 골라 삼각형을 만들것이다.
	* 
	* 만들 수 있는 삼각형 중 가장 넓이가 큰 삼각형의 넓이를 구하라
	* 
	* ※ 삼각형의 두 변은 x와 y축과 평행해야 한다
	* ※ 출력 시 삼각형의 넓이 * 2 하여 출력한다
	* 
	* -- 자연어 풀이 --
	* 1. 입력받은 좌표들을 vector<pair<int, int>>에 저장한다
	* 2. combination을 이용하여 좌표 3개를 고른다
	* 3. x축과 y축이 평행한 삼각형인지 확인한다
	*    ㄴ 3개의 점 끼리 비교할 때 x와 y가 평행한지 확인하는 bool 변수 사용
	*    ㄴ ex) a좌표의 x와 b좌표의 x가 같다면 x_check == true
	*       ㄴ y_len = abs(a.second - b.second)
	* 4. if (x_check && y_check) 라면 넓이를 구한다
	*    ㄴ answer = x_len * y_len
	* 5. answer 출력
	* 
	*/

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<pair<int, int>> forward(n);
		for (int i = 0; i < n; i++) {
			cin >> forward[i].first >> forward[i].second;
		}

		// 선택한 좌표의 인덱스 기록
		vector<int> select_idx;

		answer = 0;
		combination(forward, select_idx, 0);

		cout << answer << "\n";
	}
}