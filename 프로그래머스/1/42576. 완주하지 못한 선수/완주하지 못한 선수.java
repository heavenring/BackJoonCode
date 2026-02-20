import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        
        // 익숙한 ArrayList 사용
        ArrayList<String> join = new ArrayList(Arrays.asList(participant));
        ArrayList<String> complate = new ArrayList(Arrays.asList(completion));
        
        // Collections 내림차순 연습
        Collections.sort(join, Collections.reverseOrder());
        Collections.sort(complate, Collections.reverseOrder());
        
        for (int i = 0; i < complate.size(); i++){
            if (!join.get(i).equals(complate.get(i))){
                return join.get(i);
            }
        }
        
        return join.get(join.size() - 1);
    }
}