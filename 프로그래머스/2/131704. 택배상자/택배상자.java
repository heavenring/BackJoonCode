import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        
        ArrayList<Integer> stack = new ArrayList();
        
        int now = 1;
        for (int i = 0; i < order.length; i++){
            // 현재 박스 번호가 맞다면
            if (now == order[i]){
                answer++;
                now++;
                continue;
            }
            
            // 현재 박스 번호를 스택에서 탐색
            else if (!stack.isEmpty()){
                // 박스 번호가 틀린데 원하는 번호보다 커진다면 배송 출발
                if (stack.get(stack.size() - 1) == order[i]){
                    answer++;
                    stack.remove(stack.size() - 1);
                    continue;
                } else if (stack.get(stack.size() - 1) > order[i]) {
                    break;
                }
                
            } 
            
            stack.add(now++);
            i--;
            
        }
       
        return answer;
    }
}