import re

def solution(new_id):
    answer = ''
    
    if new_id == '':
        new_id = 'a'
        
    new_id = new_id.lower()
    
    new_id = re.sub(r"[^a-z0-9-_.]", "", new_id)
    
    new_id = re.sub(r"\.{2,}", ".", new_id)
    
    while new_id and new_id[0] == '.':
        new_id = new_id[1:]
    
    while new_id and new_id[-1] == '.':
        new_id = new_id[:-1]
    
    if new_id == '':
        new_id = 'a'
    
    new_id = new_id[:15]
    
    
    while new_id and new_id[-1] == '.':
        new_id = new_id[:-1]
        
    while len(new_id) < 3:
        new_id += new_id[-1]
            
    answer = new_id        
    
    return answer