#include <iostream>
#include <string>
#include <vector>

#define max_size 1000001

using namespace std;


/* 소수 배열 반환 */
vector<string> set_sosu() {

	vector<string> result;
	vector<bool> nums(max_size, true);
	nums[0] = nums[1] = false;
	for (int i = 2; i < max_size; i++) {
		if (nums[i]) {
			result.push_back(to_string(i));
			for (int j = i + i; j < max_size; j += i) {
				nums[j] = false;
			}
		}
	}

	return result;
}


/* 특별한 소수 여부 반환 */
bool find_sqecial_sosu(string sosu, int d) {

	bool result = false;
	for (int i = 0; i < sosu.size() && !result; i++) {
		if ((sosu[i] - '0') == d) {
			result = true;
		}
	}

	return result;
}


int main() {
	int tc;
	cin >> tc;

	vector<string> sosu = set_sosu();
	for (int t = 1; t <= tc; t++) {
		int d, a, b;
		cin >> d >> a >> b;

		int answer = 0;
		for (int i = 0; i < sosu.size(); i++) {
			if (stoi(sosu[i]) >= a && stoi(sosu[i]) <= b) {
				if (find_sqecial_sosu(sosu[i], d)) {
					answer++;
				}
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}