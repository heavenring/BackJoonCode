import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        // 유저 id와 index 매칭
        Map<String, Integer> map = new HashMap();
        for (int i = 0; i < id_list.length; i++){
             map.put(id_list[i], i);
        }
        
        // report 중복 제거
        Set<String> distinctReport = new HashSet<>(Arrays.asList(report));
        
        // 신고 당한 사람과 신고자 리스트 Map
        Map<String, ArrayList<String>> idReport = new HashMap<>();
        
        
        for (String data : distinctReport){
            String reporter = data.split(" ")[0];
            String reported = data.split(" ")[1];
            
            // 신고 당한적 없는 사람의 경우 map에 리스트 추가
            idReport.putIfAbsent(reported, new ArrayList<>());
            idReport.get(reported).add(reporter);
        }
        
        for (String id : id_list){
            // 신고 당한적 없는 사람의 경우 map에 리스트 추가
            idReport.putIfAbsent(id, new ArrayList<>());
            
            // 신고 횟수가 넘었으면 메일 발송
            if (idReport.get(id).size() >= k){
                for (String reporter : idReport.get(id)) {
                    answer[map.get(reporter)]++;
                }
            }
        }
        
        return answer;
    }
}