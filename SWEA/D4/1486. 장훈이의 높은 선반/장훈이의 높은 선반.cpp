#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void dfs(vector<int>& tall, vector<bool> &item, int idx, int sum) {

	if (idx == tall.size()) {
		item[sum] = true;
		return;
	}

	dfs(tall, item, idx + 1, sum);
	dfs(tall, item, idx + 1, sum + tall[idx]);
}

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, b;
		cin >> n >> b;

		int max_height = 0;
		vector<int> tall(n);
		for (int i = 0; i < n; i++) {
			cin >> tall[i];

			max_height += tall[i];
		}
		
		vector<bool> item(max_height + 1, false);
		dfs(tall, item, 0, 0);

		for (int i = 0; i < max_height / 2; i++) {
			if (item[b + i]) {
				cout << "#" << t << " " << abs(b - (b + i)) << "\n";
				break;
			} 
		}
	}
}