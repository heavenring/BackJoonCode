#include <iostream>
#include <vector>
#include <string>

#define tc 10

using namespace std;


/* 숫자 여부 확인 */
bool num_check (string& str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}

	return true;
}


bool inorder(vector<string>& node, vector<vector<int>>& child, int now) {
	
	bool can_calc = true;
	// 현재 노드가 숫자일 경우
	if (num_check(node[now])) {
		// 자식 노드가 존재하면 연산 불가능
		if (child[now][0] != -1 || child[now][1] != -1) {
			can_calc = false;
		}
	}
	// 현재 노드가 연산자일 경우
	else {
		// 자식 노드가 존재하지 않으면 연산 불가능
		if (child[now][0] == -1 || child[now][1] == -1) {
			can_calc = false;
		} else {
			// 왼쪽 자식 노드의 연산 여부가 true일 경우
			if (inorder(node, child, child[now][0])) {
				// 오른쪽 자식 노드의 연산 여부 확인
				if (inorder(node, child, child[now][1])) {
					can_calc = true;

				} else {
					can_calc = false;
				}
			} else {
				can_calc = false;
			}
		}
	}

	return can_calc;
}


int main() {

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<string> node(n + 1);
		vector<vector<int>> child(n + 1, vector<int>(2, -1));
		for (int i = 0; i < n; i++) {
			int node_num;
			string node_value;
			cin >> node_num >> node_value;

			node[node_num] = node_value;

			// 좌측 자식 노드가 존재 가능 시
			if (node_num * 2 <= n) {
				cin >> child[node_num][0];
			}

			// 우측 자식 노드가 존재 가능 시
			if (node_num * 2 + 1 <= n) {
				cin >> child[node_num][1];
			}
		}
		 
		cout << "#" << t << " " << (inorder(node, child, 1) ? 1 : 0) << "\n";
	}
}