def solution(arr):
    answer = []
    
    # 첫번째 값 리스트에 저장
    answer.append(arr[0])
    for num in arr: 
        if answer[-1] != num: # 리스트의 마지막 요소와 다를경우 저장
            answer.append(num)
    
    return answer