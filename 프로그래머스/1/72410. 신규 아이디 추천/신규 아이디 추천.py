import re
import string

def solution(new_id):
    answer = ''
    
    # 알파벳 소문자로 치환
    new_id = new_id.lower()
    
#     # 정규 표현식
#     # 알파벳 소문자, 숫자, -, _, .을 제외한 문자 제거
#     new_id = re.sub(r"[^a-z0-9-_.]", "", new_id)
    
#     # '.'이 2개 이상 연속할경우 1개로 치환
#     new_id = re.sub(r"\.{2,}", ".", new_id)
    
    # 사용 가능한 문자의 문자열
    can_use_letter = string.ascii_lowercase + "0123456789-_."
    
    # 슬라이싱으로 사용 불가능한 문자 제거
    i = 0
    while i < len(new_id):
        if new_id[i] not in can_use_letter:
            new_id = new_id[:i] + new_id[i + 1:]
            i -= 1
        i += 1
    
    # '.'이 연속적으로 사용될 경우 하나만 남김
    i = 0
    dot_count = 0 
    while i < len(new_id):
        if new_id[i] == '.': # '.'을 연속적으로 사용했는지 확인
            if dot_count > 0:
                new_id = new_id[:i] + new_id[i + 1:]
                i -= 1
            else:
                dot_count += 1
        else:
            dot_count = 0    
        i += 1
    
    # '.'으로 시작할 경우 '.' 삭제
    if new_id and new_id[0] == '.':
        new_id = new_id[1:]
    
    # '.'으로 끝날 경우 '.' 삭제
    if new_id and new_id[-1] == '.':
        new_id = new_id[:-1]
    
    # 문자열이 비었을 경우 'a' 저장
    if new_id == '':
        new_id = 'a'
    
    # 15자 이상일 경우 자르기
    new_id = new_id[:15]
    
    # 자른 문자열 마지막이 '.'일 경우 삭제
    while new_id and new_id[-1] == '.':
        new_id = new_id[:-1]
    
    # 문자열이 3자 이하라면 마지막 문자 붙이기
    while len(new_id) < 3:
        new_id += new_id[-1]
            
    answer = new_id        
    
    return answer