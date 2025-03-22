# statistics 표본 계산(?) 모듈
# mean(arr) 평균
# median(arr) 중앙값
# stdev(arr) 표준편차
# variance(arr) 분산

import statistics

def solution(arr):
    answer = 0
    
#    answer = sum(arr) / len(arr)
    answer = statistics.mean(arr)
    
    return answer