#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, q;
		cin >> n >> q;

		vector<int> box(n + 1, 0);
		for (int i = 1; i <= q; i++) {
			int l, r;
			cin >> l >> r;

			for (int j = l; j <= r; j++) {
				box[j] = i;
			}
		}

		cout << "#" << t;
		for (int i = 1; i <= n; i++) {
			cout << " " << box[i];
		}
		cout << "\n";
	}
}