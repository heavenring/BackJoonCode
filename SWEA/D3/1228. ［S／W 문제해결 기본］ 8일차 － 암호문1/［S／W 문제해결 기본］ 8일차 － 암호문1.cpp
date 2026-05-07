#include <iostream>
#include <vector>

#define tc 10
#define output_size 10

using namespace std;

int main() {

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<long long> plain(n);
		for (int i = 0; i < n; i++) {
			cin >> plain[i];
		}

		int command_cnt;
		cin >> command_cnt;
		for (int i = 0; i < command_cnt; i++) {
			string I;
			int forward, cnt;
			cin >> I >> forward >> cnt;

			for (int j = forward; j < forward + cnt; j++) {
				int num;
				cin >> num;

				plain.insert(plain.begin() + j, num);
			}
		}

		cout << "#" << t;
		for (int i = 0; i < output_size; i++) {
			cout << " " << plain[i];
		}
		cout << "\n";
	}
}