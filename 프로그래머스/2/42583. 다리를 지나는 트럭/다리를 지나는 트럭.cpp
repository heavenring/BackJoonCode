#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int bridge_weights = 0;
    vector<vector<int>> que;
    while(!truck_weights.empty() || !que.empty()) {
        answer++;
        
        // 건너는 중인 트럭들의 위치 이동
        int qs = que.size();
        for(int i = 0; i < qs; i++){
            if (que[0][1] < bridge_length) {
                que.push_back({que[0][0], ++que[0][1]});
            } else {
                bridge_weights -= que[0][0];
            }
            
            que.erase(que.begin());
        }
        
        // 건너지 못한 트럭이 있고, 다리 위에 올릴 수 있다면 추가
        if (!truck_weights.empty() && bridge_weights + truck_weights[0] <= weight){
            que.push_back({truck_weights[0], 1});
            bridge_weights += truck_weights[0];
            
            truck_weights.erase(truck_weights.begin());
        }
    }
    
    return answer;
}