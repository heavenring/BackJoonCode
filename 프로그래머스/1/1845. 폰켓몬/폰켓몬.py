def solution(nums):
    answer = []

    for poncketmon in nums:
        if poncketmon not in answer:
            answer.append(poncketmon)
        
        if len(answer) == len(nums) // 2:
            break
    
    return len(answer)