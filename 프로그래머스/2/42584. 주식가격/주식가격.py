# 2가지 풀이

# 1. deque를 활용한 브루트포스 방식
# 주식 가격의 등락을 입력 받는다
# 0번째 주식을 n번째 까지 반복시켜서
# 가격이 낮은걸 만나면 break 및 answer.append()
# 이걸 배열이 빌 때 까지 반복
# -> o(n!)

# 2. stack을 활용한 방식
# .. 자세한 로직은 코드 주석 확인

from collections import deque

def solution(prices):
#     answer = []
    
#     prices = deque(prices)
    
#     i = 0
#     while len(prices):
#         count = 0
#         price = prices.popleft()
#         for p in prices:
#             count += 1
#             if price > p:
#                 break
            
#         answer.append(count)
        
    
    answer = [0] * len(prices)
    stack = [] # 주식 가격이 들어갈 stack
    for i in range(len(prices)):
        # stack에 들어간 주식 가격이 떨어진다면
        while stack != [] and stack[-1][1] > prices[i]:
            # 해당 주식이 떨어질때 까지 걸린 시간 계산
            index, _ = stack.pop()
            answer[index] = i - index
        
        # stack에 현재 주식 저장
        stack.append([i, prices[i]])
    
    # 마지막까지 떨어지지 않은 주식 계산
    for i, _ in stack:
        answer[i] = len(prices) - i - 1
        
    return answer