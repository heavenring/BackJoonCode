def solution(nums):
    answer = []
    
    for poncketmon in nums:
        # 보유한 폰켓몬 번호인지 확인
        if poncketmon not in answer:
            answer.append(poncketmon)
        
        # 보유 가능한 폰켓몬 수의 도달했는지 확인
        if len(answer) == len(nums) // 2:
            break
    
    return len(answer)