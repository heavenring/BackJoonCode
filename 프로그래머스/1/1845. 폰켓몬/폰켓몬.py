def solution(nums):
    answer = 0
    
    # 리스트의 중복 값 제거
    pon_set = set(nums)
    
    # 보유 가능한 폰켓몬 종류가 보유 가능한 폰켓몬 수 보다 많은지 확인
    if len(pon_set) >= len(nums) // 2: # 많다면 보유 가능 수 저장
        answer = len(nums) // 2
    else: # 적다면 폰켓몬 종류 저장
        answer = len(pon_set)
    
    return answer
    
#     answer = []
    
#     for poncketmon in nums:
#         # 보유한 폰켓몬 번호인지 확인
#         if poncketmon not in answer:
#             answer.append(poncketmon)
        
#         # 보유 가능한 폰켓몬 수의 도달했는지 확인
#         if len(answer) == len(nums) // 2:
#             break
    
#     return len(answer)