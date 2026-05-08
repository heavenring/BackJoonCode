#include <iostream>
#include <vector>

using namespace std;


/* 최상위 부모 탐색 */
int find_parent(vector<int>& parent, int people) {
	if (parent[people] == people) {
		return people;
	} else {
		return parent[people] = find_parent(parent, parent[people]);
	}
}



void update_parent(vector<int>& parent, int a, int b) {
	
	if (a < b) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, m;
		cin >> n >> m;
		
		vector<int> parent(n + 1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			
			int root_a = find_parent(parent, a);
			int root_b = find_parent(parent, b);

			if (root_a != root_b) {
				update_parent(parent, root_a, root_b);
			}
		}

		long long answer = 0;
		for (int i = 1; i <= n; i++) {
			if (parent[i] == i) {
				answer++;
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}