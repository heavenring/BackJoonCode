#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		int max_num = 0;
		vector<int> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			max_num += nums[i];
		}

		vector<bool> can_make(max_num + 1, false);
		can_make[0] = true;

		vector<int> maked_num;
		maked_num.push_back(0);
		for (int i = 0; i < nums.size(); i++) {
			int now_size = maked_num.size();
			for (int j = 0; j < now_size; j++) {
				int new_num = maked_num[j] + nums[i];
				if (!can_make[new_num]) {
					can_make[new_num] = true;
					maked_num.push_back(new_num);
				}
			}
		}

		long long answer = 0;
		for (int i = 0; i < can_make.size(); i++) {
			if (can_make[i]) {
				answer++;
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}