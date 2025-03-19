#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	
	for (int t = 1; true; t++) {
		int answer = 0;
		int size, n;
		cin >> size >> n;

		if (size == 0 && n == 0)
			break;

		vector<vector<int>> V(size + 1);

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;

			V[a].push_back(b);
			V[b].push_back(a);
		}

		vector<bool> start_V(size + 1, true);
		for (int i = 1; i <= size; i++) {
			vector<bool> visit_V(size + 1, true);
			visit_V[i] = false;

			int past_V = 0;
			if (start_V[i]) {
				queue<pair<int, int>> que;
				que.push({ -1 , i});
				start_V[i] = false;

				bool check = true;
				while (!que.empty() && check) {
					int now_V = que.front().second;
					past_V = que.front().first;

					for (int j = 0; j < V[now_V].size(); j++) {
						int next_V = V[now_V][j];

						if (visit_V[next_V]) {
							start_V[next_V] = false;
							visit_V[next_V] = false;
							que.push({ now_V, next_V });
						}
						else if (past_V != next_V) {
							check = false;
							break;
						}
					}
					que.pop();
				}

				if (check) {
					answer++;
					/*cout << i << "\n";*/
				}
			}

		}

		if (answer == 0)
			cout << "Case " << t << ": No trees." << "\n";
		else if(answer == 1)
			cout << "Case " << t << ": There is one tree." << "\n";
		else
			cout << "Case " << t << ": A forest of " << answer << " trees." << "\n";

	}

}