#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int v, e;
		cin >> v >> e;

		// 정점간 간선 정보 및 가중치 저장
		vector<vector<pair<int, int>>> graph(v + 1);
		for (int i = 0; i < e; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			graph[a].push_back({ b, c });
			graph[b].push_back({ a, c });
		}

		// 방문 기록
		// 시작 정점(1번 노드) 방문 표시
		vector<bool> visit(v + 1, false);
		visit[1] = true;

		// 최소 가중치 순으로 정점 탐색을 위한 우선순위 큐
		// 1번 정점부터 시작
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for (int i = 0; i < graph[1].size(); i++) {
			pq.push({ graph[1][i].first, graph[1][i].second });
		}

		// 최소 가중치 결과 값
		long long answer = 0;

		// 가지치기용 방문 노드 개수 확인
		long long visit_cnt = 0;

		// 가중치가 가장 작은 순으로 방문 탐색
		while (!pq.empty() && visit_cnt < v) {
			int node = pq.top().first;
			int weight = pq.top().second;
			pq.pop();

			// 방문하지 않은 정점일 경우
			if (!visit[node]) {
				visit_cnt++;
				answer += weight;

				// 방문 처리
				visit[node] = true;

				// 이동 가능 정점 탐색
				for (int i = 0; i < graph[node].size(); i++) {
					int nextNode = graph[node][i].first;
					int nextWeight = graph[node][i].second;

					if (!visit[nextNode]) {
						pq.push({ nextNode, nextWeight });
					}
				}
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}