#include <iostream>
#include <vector>

#define tc 10

using namespace std;


void inorder(const vector<string>& node, const vector<vector<int>>& tree, int node_num) {
	// 왼쪽 자식 노드 방문
	if (tree[node_num][0] != 0) {
		inorder(node, tree, tree[node_num][0]);
	}
	
	// 현재 노드 방문
	cout << node[node_num];
	
	// 오른쪽 자식 노드 방문
	if (tree[node_num][1] != 0) {
		inorder(node, tree, tree[node_num][1]);
	}
}


int main() {
	
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		// 각 정점의 문자와 왼쪽, 오른쪽 자식 노드 번호 저장
		vector<string> node(n + 1);
		vector<vector<int>> tree(n + 1, vector<int>(2));
		for (int depth = 1; depth <= n; depth++) {
			int node_num, left, right;
			string c;
			cin >> node_num>> c;
			node[node_num] = c;

			if (node_num * 2 <= n) {
				cin >> left;
				tree[node_num][0] = left;
			}

			if (node_num * 2 + 1 <= n) {
				cin >> right;
				tree[node_num][1] = right;
			}
		}
		
		cout << "#" << t << " ";
		inorder(node, tree, 1);
		cout << endl;
	}
}