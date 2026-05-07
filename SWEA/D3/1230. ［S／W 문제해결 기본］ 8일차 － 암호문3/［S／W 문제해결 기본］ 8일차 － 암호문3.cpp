#include <iostream>
#include <vector>

#define tc 10
#define output_size 10

using namespace std;


/* 삽입 명령어 */
void mode_i(vector<int>& nums) {
	int idx, cnt;
	cin >> idx >> cnt;

	for (int i = idx; i < idx + cnt; i++) {
		int num;
		cin >> num;

		nums.insert(nums.begin() + i, num);
	}
}


/* 삭제 명령어 */
void mode_d(vector<int>& nums) {
	int idx, cnt;
	cin >> idx >> cnt;

	nums.erase(nums.begin() + idx, nums.begin() + idx + cnt);
}


/* 추가 명령어 */
void mode_a(vector<int>& nums) {
	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		int num;
		cin >> num;

		nums.push_back(num);
	}
}


int main() {

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}

		int command_cnt;
		cin >> command_cnt;

		for (int i = 0; i < command_cnt; i++) {
			string command;
			cin >> command;

			if (command == "I") {
				mode_i(nums);
			} else if (command == "D") {
				mode_d(nums);
			} else if (command == "A") {
				mode_a(nums);
			}
		}

		cout << "#" << t << " ";
		for (int i = 0; i < output_size; i++) {
			cout << nums[i] << " ";
		}
		cout << "\n";
	}

}