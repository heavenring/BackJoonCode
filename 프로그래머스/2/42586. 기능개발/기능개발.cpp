#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int count = 0;
    int pre_day = ceil((double)(100 - progresses[0]) / speeds[0]);
    for(int i = 0; i < progresses.size(); i++){
        // day가 같거나 작다면 count++
        // day가 크다면 count 추가 및 day 엎어쓰기 count = 1
        int now_day = ceil((double)(100 - progresses[i]) / speeds[i]);
        if (pre_day >= now_day){
            count++;
        } else {
            answer.push_back(count);
            pre_day = now_day;
            count = 1;
        }
    }
    answer.push_back(count);
    
    
    return answer;
}