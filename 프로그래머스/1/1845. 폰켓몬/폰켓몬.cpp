#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    sort(nums.begin(), nums.end());
    
    // 중복되지 않은 번호 저장
    vector<int> poncketmon;
    int now_num = 0;
    for (int num : nums) {
        if (now_num != num) {
            poncketmon.push_back(num);
            now_num = num;
        }
    }
    
    answer = min(poncketmon.size(), nums.size() / 2);
    return answer;
}