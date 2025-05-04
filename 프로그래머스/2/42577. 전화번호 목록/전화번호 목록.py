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
    for i in range(len(phone_book) - 1):
        # 다음 번호의 시작 번호가 다르다면 continue
        # 해당 로직으로 인해 접두어 번호가 접두사 번호보다 길어질 일이 없다
        if phone_book[i][0] != phone_book[i + 1][0]:
            continue
        
        # 접두어 번호를 포함하는지 확인
        if phone_book[i] == phone_book[i + 1][:len(phone_book[i])]:
            answer = False
            break
    
    return answer