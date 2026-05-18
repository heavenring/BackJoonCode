#include <iostream>
#include <string>

#define zisu 30

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		long long n, m;
		cin >> n >> m;

		string two_num = "";
		int now_zisu = zisu;
		while (now_zisu > -1) {
			// 이진수 생성
			if (m - (1 << now_zisu) < 0) {
				two_num += "0";
			} else {
				m -= (1 << now_zisu);
				two_num += "1";
			}

			now_zisu--;
		}

		bool check = true;
		for (int i = two_num.size() - 1; i >= two_num.size() - n; i--) {
			if (two_num[i] == '0') {
				check = false;
				break;
			}
		}

		if (check) {
			cout << "#" << t << " ON\n";
		} else {
			cout << "#" << t << " OFF\n";
		}
	}
}