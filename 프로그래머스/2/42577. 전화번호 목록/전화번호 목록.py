# 문자 기준 정렬이기 때문에
# 접두어 번호와 접두사 번호를 늘 순서대로 정렬된다 
# ex) 119, 1195524421
#     152, 15267, 242
# 때문에 현재 번호와 다음 번호만 비교하면 된다

def solution(phone_book):
    answer = True
    
    # 문자 기준으로 정렬한다
    phone_book.sort()
    
    # 현재 번호와 다음 번호를 비교한다
    for now_num, next_num in zip(phone_book, phone_book[1:]):
        if next_num.startswith(now_num):
            answer = False
            break
    
    return answer