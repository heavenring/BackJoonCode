#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    vector<char> stack;
    
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            stack.push_back(s[i]);
        } else if (stack.empty()){
            answer = false;
            break;
        } else {
            stack.pop_back();
        }
    }
    
    if (!stack.empty()){
        answer = false;
    }
    
    return answer;
}