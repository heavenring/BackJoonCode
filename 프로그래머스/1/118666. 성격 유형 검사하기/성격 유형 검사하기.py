# 각 성격 유형이 담긴 dict 사용
# dict = {'R': 0, 'T': 1 ~ 'A': 6, 'N': 7}
# 유형이 들어오면 point[dict[survey[0] or survey[1]]] += 3 - abs(choices % 6)
# 반복문으로 2칸씩 뛰며 높은 점수 선택
# 만약 점수가 같다면 작은 성격 유형 선택

def solution(survey, choices):
    answer = ''
    
    # 각 성격 유형이 담긴 dict
    dic = {'R': 0, 'T': 1, 'C': 2, 'F': 3, 'J': 4, 'M': 5, 'A': 6, 'N': 7}
    point = [0 for i in range(8)] # 성격유형 인덱스 마다 할당할 점수 리스트
    for mental, choice in zip(survey, choices):
        if (choice - 1)  < 3: # 검사 결과의 앞쪽 성향일 경우
            point[dic[mental[0]]] += abs(3 - (choice - 1) % 6)
        else: # 검사 결과의 뒷쪽 성향일 경우
            point[dic[mental[1]]] += abs(3 - (choice - 1) % 6)
    
    # 인덱스 기준 성격 유형을 탐색하는 dict
    rev_dic = {'0': 'R', '1': 'T', '2': 'C', '3': 'F', '4': 'J', '5': 'M', '6': 'A', '7': 'N'}
    for i in range(0, len(point), 2): # 더 높은 점수의 성격 유형 선택
        if point[i] < point[i + 1]:
            answer += rev_dic[str(i + 1)]
        elif point[i] > point[i + 1]:
            answer += rev_dic[str(i)]
        else: # 같은 점수일 경우 사전 순으로 성격 유형 선택
            answer += min(rev_dic[str(i)], rev_dic[str(i + 1)])
    
    return answer