# pregresses와 speed의 맨 앞 데이터를 꺼낸다
# 완성 가능일을 계산한다 (99 - progress) // speed + 1
# 다음 데이터를 꺼낸 후 완성 가능일을 계산한다
# 이전 데이터보다 짧다면 complete += 1
# 길다면 answer.append(complete)

def solution(progresses, speeds):
    # 첫번째 프로세스는 for 문에서 한번 중복되기 때문에
    # 첫번째 프로세스 배포일에 배포하는 프로세스 수를 0으로 설정
    answer = [0] 
    
    # 첫번째 프로세스의 배포일 계산
    pre_complete_day = (99 - progresses[0]) // speeds[0] + 1
    for progress, speed in zip(progresses, speeds):
        # 현재 프로세스의 배포일 계산
        complete_day = (99 - progress) // speed + 1
        
        # 이전 프로세스보다 배포일이 빠르다면 
        if complete_day <= pre_complete_day:
            # 한번에 배포되는 프로세스 개수에 + 1
            answer[-1] += 1
        
        # 이전 프로세스보다 배포일이 늦다면
        else:
            # 이후 배포되는 프로세스를 추가한 후
            answer.append(1)
            # 현재 배포일을 이전 배포일에 저장
            pre_complete_day = complete_day

        
    return answer