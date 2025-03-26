def solution(ingredient):
    answer = 0
    
    burger = []
    for i in ingredient:
        # 재료를 하나씩 넣어
        burger.append(i)
        # 햄버거가 완성되는걸 확인
        if burger[-4:] == [1, 2, 3, 1]:
            answer += 1
            del burger[-4:]
    
    return answer