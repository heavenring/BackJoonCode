import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        ArrayList<String> phoneBook = new ArrayList(Arrays.asList(phone_book));
        
        Collections.sort(phoneBook);
        
        for (int i = 0; i < phoneBook.size() - 1; i++){
            if (phoneBook.get(i + 1).startsWith(phoneBook.get(i))){
                answer = false;
                break;
            }
        }
        
        
        return answer;
    }
}