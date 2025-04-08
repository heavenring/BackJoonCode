# pregresses와 speed의 맨 앞 데이터를 꺼낸다
# 완성 가능일을 계산한다 (99 - progress) // speed + 1
# 다음 데이터를 꺼낸 후 완성 가능일을 계산한다
# 이전 데이터보다 짧다면 complete += 1
# 길다면 answer.append(complete)
def solution(progresses, speeds):
    answer = [0]
    
    pre_complete_day = (99 - progresses[0]) // speeds[0] + 1
    for progress, speed in zip(progresses, speeds):
        complete_day = (99 - progress) // speed + 1
        
        if complete_day <= pre_complete_day:
            answer[-1] += 1
        else:
            answer.append(1)
            pre_complete_day = complete_day

        
        
    return answer