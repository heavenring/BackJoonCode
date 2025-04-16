def solution(priorities, location):
    answer = 0
    
    # 우선순위 순서대로 데이터를 정렬시켜둔다
    high_pri_list = []
    for i in priorities:
        high_pri_list.append(i)
    high_pri_list.sort()
    
    while len(priorities):
        # 현재 프로세스가 우선순위가 가장 높다면
        if priorities[0] == high_pri_list[-1]:
            answer += 1            
            # 실행을 기다리는 프로세스인지 확인한다.
            if not location:
                break;
            # 아니라면
            else:
                del priorities[0]
                del high_pri_list[-1]
                location -= 1
        # 우선순위가 낮은 프로세스라면
        else:
            # 현재 프로세스를 뒤로 보낸다
            priorities.append(priorities[0])
            del priorities[0]
            
            # 현재 프로세스가 실행 대기중인 프로세스라면
            if not location:
                location = len(priorities) - 1
            # 아니라면
            else:
                location -= 1
                
            
    return answer