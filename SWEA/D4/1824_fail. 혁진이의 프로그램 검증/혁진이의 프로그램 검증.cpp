#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool answer;

void dfs(vector<vector<pair<string, int>>>& area, int x, int y, string forward, int memory) {

	// 종료 지점에 도달했을 때 
	if (area[x][y].first == "@") {
		answer = true;
		return;
	}

	// 이미 방문한 적이 있을 때
	// 그 때의 메모리 값과 현재 메모리 값이 같다면 무한 루프이므로 종료
	if (area[x][y].second == memory) {
		return;
	} 
	// 그 외 방문한 적이 없다면 현재 메모리 값으로 방문 표시
	else if (area[x][y].second == -1) {
		area[x][y].second = memory;
	}

	if (!answer) {
		// 방향에 따른 이동
		if (area[x][y].first == ">") {
			dfs(area, x, (y + 1) % area[0].size(), area[x][y].first, memory);
		}
		else if (area[x][y].first == "<") {
			dfs(area, x, (y - 1 + area[0].size()) % area[0].size(), area[x][y].first, memory);
		}
		else if (area[x][y].first == "^") {
			dfs(area, (x - 1 + area.size()) % area.size(), y, area[x][y].first, memory);
		}
		else if (area[x][y].first == "v") {
			dfs(area, (x + 1) % area.size(), y, area[x][y].first, memory);
		}
		// 메모리 값에 따른 좌 우 이동
		else if (area[x][y].first == "_") {
			if (memory == 0) {
				dfs(area, x, (y + 1) % area[0].size(), ">", memory);
			}
			else {
				dfs(area, x, (y - 1 + area[0].size()) % area[0].size(), "<", memory);
			}
		}
		// 메모리 값에 따른 상 하 이동
		else if (area[x][y].first == "|") {
			if (memory == 0) {
				dfs(area, (x + 1) % area.size(), y, "v", memory);
			}
			else {
				dfs(area, (x - 1 + area.size()) % area.size(), y, "^", memory);
			}
		}
		// 모든 방향 이동
		else if (area[x][y].first == "?") {
			dfs(area, x, (y + 1) % area[0].size(), ">", memory);
			dfs(area, x, (y - 1 + area[0].size()) % area[0].size(), "<", memory);
			dfs(area, (x - 1 + area.size()) % area.size(), y, "^", memory);
			dfs(area, (x + 1) % area.size(), y, "v", memory);
		}
		// 아무것도 안할 시 그대로 이동
		else if (area[x][y].first == ".") {
			if (forward == ">") {
				dfs(area, x, (y + 1) % area[0].size(), forward, memory);
			}
			else if (forward == "<") {
				dfs(area, x, (y - 1 + area[0].size()) % area[0].size(), forward, memory);
			}
			else if (forward == "^") {
				dfs(area, (x - 1 + area.size()) % area.size(), y, forward, memory);
			}
			else if (forward == "v") {
				dfs(area, (x + 1) % area.size(), y, forward, memory);
			}
		}
		// 메모리 값을 1 증가 시킨 후 이동
		else if (area[x][y].first == "+") {
			memory = (memory + 1) % 16;
			if (forward == ">") {
				dfs(area, x, (y + 1) % area[0].size(), forward, memory);
			}
			else if (forward == "<") {
				dfs(area, x, (y - 1 + area[0].size()) % area[0].size(), forward, memory);
			}
			else if (forward == "^") {
				dfs(area, (x - 1 + area.size()) % area.size(), y, forward, memory);
			}
			else if (forward == "v") {
				dfs(area, (x + 1) % area.size(), y, forward, memory);
			}
		}
		// 메모리 값을 1 감소 시킨 후 이동
		else if (area[x][y].first == "-") {
			memory = (memory - 1 + 16) % 16;
			if (forward == ">") {
				dfs(area, x, (y + 1) % area[0].size(), forward, memory);
			}
			else if (forward == "<") {
				dfs(area, x, (y - 1 + area[0].size()) % area[0].size(), forward, memory);
			}
			else if (forward == "^") {
				dfs(area, (x - 1 + area.size()) % area.size(), y, forward, memory);
			}
			else if (forward == "v") {
				dfs(area, (x + 1) % area.size(), y, forward, memory);
			}
		}
		// 숫자일 경우 메모리에 저장 후 그대로 이동
		else {
			memory = stoi(area[x][y].first);
			if (forward == ">") {
				dfs(area, x, (y + 1) % area[0].size(), forward, memory);
			}
			else if (forward == "<") {
				dfs(area, x, (y - 1 + area[0].size()) % area[0].size(), forward, memory);
			}
			else if (forward == "^") {
				dfs(area, (x - 1 + area.size()) % area.size(), y, forward, memory);
			}
			else if (forward == "v") {
				dfs(area, (x + 1) % area.size(), y, forward, memory);
			}
		}
	}
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int r, c;
		cin >> r >> c;

		// 종료 지점이 존재하는지 여부
		bool exist_goal = false;
		// 미방문: -1, 방문: 초기 방문 메모리 값
		vector<vector<pair<string, int>>> area(r, vector<pair<string, int>>(c, {" ", -1}));
		for (int i = 0; i < r; i++) {
			string input;
			cin >> input;

			for (int j = 0; j < c; j++) {
				area[i][j].first = input[j];
				
				if (input[j] == '@') {
					exist_goal = true;
				}
			}
		}

		answer = false;

		// 종료지점이 존재할 경우 탐색 시작
		if (exist_goal) {
			dfs(area, 0, 0, ">", 0);
		}

		cout << "#" << t << " " << (answer ? "YES" : "NO") << endl;
	}
}