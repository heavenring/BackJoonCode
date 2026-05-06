#include <iostream>

#define round 9


using namespace std;

long long win_case;
long long lose_case;


void permutation(int k_cards[], int i_cards[], bool visit[], int idx, int k_score, int i_score) {
	if (idx == round) {
		if (k_score > i_score) win_case++;
		else if (k_score < i_score) lose_case++;
		return;
	}

	for (int i = 0; i < round; i++) {
		if (visit[i]) {
			visit[i] = false;

			int k_card = k_cards[idx];
			int i_card = i_cards[i];
			if (k_card > i_card) {
				permutation(k_cards, i_cards, visit, idx + 1, k_score + k_card + i_card, i_score);
			} else if (k_card < i_card) {
				permutation(k_cards, i_cards, visit, idx + 1, k_score, i_score + k_card + i_card);
			}

			visit[i] = true;
		}
	}
}


int main() {
	/**
	* 총 9라운드로 구성됨
	* 높은 수가 적힌 카드를 낸 사람은 두 카드에 적힌 수의 합 만큼 점수 획득
	* 낮은 수가 적힌 카드를 낸 사람은 점수 획득 x
	* 
	* 규영이가 낸 카드가 주어졌을 때,
	* 인영이의 카드 배열에 따른 규영이의 승, 패 경우의 수를 구하라
	* 
	* -- 자연어 풀이 --
	* 1. 규영이가 낸 카드를 입력 받는다
	* 2. 규영이의 카드를 제외한 수로 이루어진 vector를 구한다
	* 3. 해당 vector에 저장된 값으로 조합을 통해 인영이가 낼 수 있는 카드의 모든 경우의 수를 구한다
	* 4. 각 경우의 수를 비교하여 승, 패 경우의 수를 구한다
	*    ㄴ 각 라운드 별로 현재 점수를 계산해서 재귀 인자로 넘긴다
	* 
	*/

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int k_cards[round];
		int i_cards[round];
		for (int j = 0; j < round; j++) {
			cin >> k_cards[j];
		}

		int idx = 0;
		for (int j = 1; j <= 2 * round; j++) {
			bool check = true;
			for (int k = 0; k < round; k++) {
				if (k_cards[k] == j) {
					check = false;
					break;
				}
			}

			if (check) {
				i_cards[idx++] = j;
			}
		}


		win_case = lose_case = 0;
		bool visit[round];
		for (int j = 0; j < round; j++) 
			visit[j] = true;

		permutation(k_cards, i_cards, visit, 0, 0, 0);

		cout << "#" << i + 1 << " " << win_case << " " << lose_case << "\n";
	}
}