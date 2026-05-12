#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		long long answer = 0;
		// 1 ~ n, 2 ~ n, ..., n ~ n 까지의 연속된 수들의 합 탐색
		for (int i = 1; i <= n; i++) {
			long long sum = 0;
			for (int j = i; j <= n; j++) {
				sum += j;

				// 연속된 수들의 합이 n과 같으면 answer 증가 후 탐색 종료
				if (sum == n) {
					answer++;
					break;
				}

				// 연속된 수들의 합이 n보다 커지면 탐색 종료
				if (sum > n) {
					break;
				}
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}