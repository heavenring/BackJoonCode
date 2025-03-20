import re

def solution(new_id):
    answer = ''
    
    # 알파벳 소문자로 치환
    new_id = new_id.lower()
    
    # 알파벳 소문자, 숫자, -, _, .을 제외한 문자 제거
    new_id = re.sub(r"[^a-z0-9-_.]", "", new_id)
    
    # '.'이 2개 이상 연속할경우 1개로 치환
    new_id = re.sub(r"\.{2,}", ".", new_id)
    
    # '.'으로 시작할 경우 '.' 삭제
    while new_id and new_id[0] == '.':
        new_id = new_id[1:]
    
    # '.'으로 끝날 경우 '.' 삭제
    while new_id and new_id[-1] == '.':
        new_id = new_id[:-1]
    
    # 문자열이 비었을 경우 'a' 저장
    if new_id == '':
        new_id = 'a'
    
    # 15자 이상일 경우 자르기
    new_id = new_id[:15]
    
    # 자른 문자열 마지막이 'a'일 경우 삭제
    while new_id and new_id[-1] == '.':
        new_id = new_id[:-1]
    
    # 문자열이 3자 이하라면 마지막 문자 붙이기
    while len(new_id) < 3:
        new_id += new_id[-1]
            
    answer = new_id        
    
    return answer