def solution(data, ext, val_ext, sort_by):
    answer = []
    
    data_name = ["code", "date", "maximum", "remain"]
    
    for one_data in data:
        if one_data[data_name.index(ext)] < int(val_ext):
            answer.append(one_data)
    
    # 특정 인덱스 기준 리스트 정렬 공부 필요
    answer.sort(key = lambda x:x[data_name.index(sort_by)])
            
    
    return answer