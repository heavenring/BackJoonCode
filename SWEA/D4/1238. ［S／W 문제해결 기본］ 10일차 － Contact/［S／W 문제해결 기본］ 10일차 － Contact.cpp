#include <iostream>
#include <vector>
#include <queue>

#define tc 10

using namespace std;


/* 마지막 연락을 받은 사람 중 번호가 가장 큰 사람 반환 */
long long last_contact_node(vector<int>& visited, int last_contact_cnt) {

	long long result = -1;
	for (long long i = 1; i < visited.size() - 1; i++) {
		if (visited[i] == last_contact_cnt) {
			result = max(result, i);
		}
	}

	return result;
}


/* 연락망 탐색 */
long long bfs (vector<vector<int>>& contact, int start) {
	queue<pair<int, int>> que;
	vector<int> visited(101, -1);

	que.push({start, 0});
	visited[start] = 0;

	int now_num, last_cnt;
	while (!que.empty()) {
		now_num = que.front().first;
		last_cnt = que.front().second;
		que.pop();

		for (int i = 0; i < contact[now_num].size(); i++) {
			int next_num = contact[now_num][i];
			if (visited[next_num] == -1) {
				visited[next_num] = last_cnt + 1;
				que.push({next_num, last_cnt + 1});
			}
		}
	}

	return last_contact_node(visited, last_cnt);
}


int main() {
	
	for (int t = 1; t <= tc; t++) {
		int n, start;
		cin >> n >> start;

		vector<vector<int>> contact(101);
		for (int i = 0; i < n / 2; i++) {
			int from, to;
			cin >> from >> to;
			contact[from].push_back(to);
		}

		cout << "#" << t << " " << bfs(contact, start) << "\n";
	}
}