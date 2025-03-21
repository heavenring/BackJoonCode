# del 함수, index 함수 활용 -> 시간초과
# for c in completion:
#       del participant[participant.index(c)]

# sort함수와 max함수 활용 
def solution(participant, completion):
    answer = ''
    
    # 두 리스트를 정렬
    participant.sort()
    completion.sort()
    
    # 정렬된 값이 서로 다르다면 해당 값 저장
    for i in range(len(completion)):
        if participant[i] != completion[i]:
            answer = participant[i]
            break
    
    # 비어있다면 마지막 값 저장
    if not answer:
        answer = max(participant)
        
    return answer