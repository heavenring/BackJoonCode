#include <iostream>
#include <vector>

#define trump_card_size 14

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		// 스페이드, 다이아, 하트, 클로버 각각 13장의 카드 배열
		vector<bool> s(trump_card_size, false);
		vector<bool> d(trump_card_size, false);
		vector<bool> h(trump_card_size, false);
		vector<bool> c(trump_card_size, false);

		string input;
		cin >> input;

		bool error_check = false;
		for (int i = 0; i < input.size(); i += 3) {
			char suit = input[i];
			int num = (input[i + 1] - '0') * 10 + (input[i + 2] - '0');

			switch (suit) {
			case 'S':
				if (s[num]) {
					error_check = true;
				}

				s[num] = true;
				break;
			case 'D':
				if (d[num]) {
					error_check = true;
				}

				d[num] = true;
				break;
			case 'H':
				if (h[num]) {
					error_check = true;
				}

				h[num] = true;
				break;
			case 'C':
				if (c[num]) {
					error_check = true;
				}

				c[num] = true;
				break;
			}
		}

		if (error_check) {
			cout << "#" << t << " ERROR" << endl;
		} else {
			int s_count, d_count, h_count, c_count;
			s_count = d_count = h_count = c_count = 0;

			for (int i = 1; i < trump_card_size; i++) {
				if (!s[i]) s_count++;
				if (!d[i]) d_count++;
				if (!h[i]) h_count++;
				if (!c[i]) c_count++;
			}

			cout << "#" << t << " " << s_count << " " << d_count << " " << h_count << " " << c_count << endl;
		}
	}
}