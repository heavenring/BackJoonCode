#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 단조 증가하는 수 여부 */
long long check_increse(long long origin_num) {

	int num = origin_num;
	int prev = num % 10;
	num /= 10;
	while (num > 0) {
		int curr = num % 10;
		if (curr > prev) {
			return -1;
		}

		prev = curr;
		num /= 10;
	}

	return origin_num;
}


int main() {
	int tc;
	cin >> tc;

	for (int i = 0 ; i < tc ; i++) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (int j = 0; j < n; j++) {
			cin >> nums[j];
		}


		// 단조 증가하는 수 중 가능 큰 수 조회
		long long answer = -1;
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				answer = max(answer, check_increse((long long)nums[j] * nums[k]));
			}
		}

		cout << "#" << i + 1 << " " << answer << endl;
	}
}