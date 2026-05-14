#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		long long answer = 0;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;

			// 좌표 거리 및 점수 계산
			long long p = -(sqrt(x * x + y * y) / 20 - 11);
			if (p >= 1 && p <= 10) {
				answer += p;
			}
			// (0,0) 저격 시 p가 11이 되므로
			// 10점으로 처리
			else if (p == 11) {
				answer += 10;
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}