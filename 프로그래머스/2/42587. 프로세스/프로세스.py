from collections import deque

# 2가지 풀이
def solution(priorities, location):
    answer = 0
    
#     # 1.
#     # 우선순위 순서대로 데이터를 정렬시켜둔다
#     high_pri_list = sorted(priorities)
    
#     while len(priorities):
#         # 현재 프로세스의 우선순위가 가장 높다면
#         if priorities[0] == high_pri_list[-1]:
#             answer += 1            
#             # 실행을 기다리는 프로세스인지 확인한다.
#             if not location:
#                 break;
#             # 아니라면
#             else:
#                 del priorities[0]
#                 del high_pri_list[-1]
#                 location -= 1
#         # 우선순위가 낮은 프로세스라면
#         else:
#             # 현재 프로세스를 뒤로 보낸다
#             priorities.append(priorities[0])
#             del priorities[0]
            
#             # 실행을 기다리는 프로세스인지 확인한다.
#             if not location:
#                 location = len(priorities) - 1
#             # 아니라면
#             else:
#                 location -= 1

    # 2.
    priorities = deque(priorities)
    
    # 우선 순위대로 데이터를 정렬시킨다.
    high_pri_list = sorted(priorities)
    
    while len(priorities):
        # 현재 프로세스를 proc_num에 할당 후 deque에서 제거
        proc_num = priorities.popleft() 
        
        # 현재 프로세스의 우선순위가 높다면
        if proc_num == high_pri_list[-1]:
            # 가장 높은 우선순위 데이터 제거
            del high_pri_list[-1]
            answer += 1
            
            # 실행 대기중인 프로세스라면 반복문 탈출
            if not location:
                break;
        # 현재 프로세스의 우선순위가 낮다면
        else:
            # 실행 대기 deque에 재할당
            priorities.append(proc_num)
            
            # 실행 대기중인 프로세스의 위치값 업데이트
            if not location:
                location = len(priorities)
        
        # 실행 대기중인 프로세스의 위치값 업데이트
        location -= 1
            
            
    return answer