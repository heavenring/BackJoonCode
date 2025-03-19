#include<iostream>
#include<vector>
#include<map>
#include<algorithm>


using namespace std;
typedef pair<int, int> pii;


void make_tree(vector<int>& node, map<int, pii>& tree, vector<int>& line, int parent, int index) {

	int seed = node[index];
	line.push_back(parent);

	//cout << "seed : " << seed << "  parent : " << parent << "\n";
	if (seed < parent) {
		if (tree[parent].first == 0) {
			//cout << "--------------------------------------------------\n";
			//cout << "parent : " << parent << " left seed : " << seed << "\n";
			//cout << "--------------------------------------------------\n\n";
			tree[parent].first = seed;

			index++;
			if (index < node.size())
				make_tree(node, tree, line, seed, index);
		}
		else
			make_tree(node, tree, line, seed, index);
	}

	else {
		int parent_index = line.size() - 1;
		while (parent_index > -1) {
			if (line[parent_index] > seed)
				break;
			else
				parent_index--;
		}
		parent_index++;

		while (parent_index < line.size()) {
			if (tree[line[parent_index]].second == 0) {
				//cout << "--------------------------------------------------\n";
				//cout << "parent : " << line[parent_index] << " right seed : " << seed << "\n";
				//cout << "--------------------------------------------------\n\n";
				tree[line[parent_index]].second = seed;

				for(int i = line.size(); i > parent_index; i--)
					line.pop_back();

				index++;
				if (index < node.size())
					make_tree(node, tree, line, seed, index);
				break;
			}
			else {
				parent_index++;
			}
		}


	}
}


void postorder(map<int, pii>& tree, int parent) {
	int left = tree[parent].first;
	int right = tree[parent].second;

	if (left != 0)
		postorder(tree, left);
	if (right != 0)
		postorder(tree, right);
	cout << parent << "\n";
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> node;

	int num;
	while (cin >> num) {
		node.push_back(num);
	}
	map<int, pii> tree;

	vector<int> line;
	make_tree(node, tree, line, node[0], 1);

	postorder(tree, node[0]);

}