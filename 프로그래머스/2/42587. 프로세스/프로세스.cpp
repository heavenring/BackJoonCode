#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<int> order = priorities;
    sort(order.rbegin(), order.rend());
    
    // 큐에 들어있는 데이터가 빌 떄 까지 반복
    while(!priorities.empty()){
        // 우선순위가 가장 높은 프로세스일 경우
        if(priorities[0] == order[0]){
            answer++;
            priorities.erase(priorities.begin());
            order.erase(order.begin());
            
            // 기다리던 프로세스일 경우
            if (location == 0){
                break;
                
            // 기다리던 프로세스가 아닐 경우
            } else {
                location--;
            }
        
        // 우선 순위가 가장 높지 않은 프로세스일 경우
        } else {
            // 현재 프로세스 재 등록 및 맨 앞단 프로세스 제거
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            
            // 기다리던 프로세스의 인덱스 변경
            if(location == 0){
                location = priorities.size() - 1;
            } else {
                location--;
            }
        }
    }
    
    return answer;
}