#include <iostream>
#include <vector>

#define tc 10
#define ladder_size 100

using namespace std;


int find_start_point(vector<vector<int>>& ladder, pair<int, int>& end_point) {
	/**
	* 1. 사다리의 끝점에서 시작하여 위로 올라간다
	* 2. 왼쪽, 오른쪽으로 이동할 수 있다면 이동한다
	* 3. 사다리의 시작점에 도달할 때 까지 반복한다
	* 4. 사다리의 시작점이 정답이다
	*/
	int x = end_point.first;
	int y = end_point.second;

	while (x > 0) {
		ladder[x][y] = -1;

		if (y > 0 && ladder[x][y - 1] == 1) {
			y--;
		} else if (y < ladder_size - 1 && ladder[x][y + 1] == 1) {
			y++;
		} else {
			x--;
		}
	}

	return y;
}


int main() {

	for (int i = 0; i < tc; i++) {
		int t;
		cin >> t;


		pair<int, int> end_point;
		vector<vector<int>> ladder(ladder_size, vector<int>(ladder_size, 0));
		for (int j = 0; j < ladder_size; j++) {
			for (int k = 0; k < ladder_size; k++) {
				cin >> ladder[j][k];

				if (ladder[j][k] == 2) {
					end_point.first = j;
					end_point.second = k;
				}
			}
		}

		int answer = find_start_point(ladder, end_point);
		cout << "#" << t << " " << answer << endl;
	}
}