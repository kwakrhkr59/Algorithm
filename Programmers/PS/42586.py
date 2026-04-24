from collections import deque

def solution(progresses, speeds):
    queue = deque(
        [(100 - p + s - 1) // s for p, s in zip(progresses, speeds)]
    )
    
    answer = []
    
    while queue:
        current = queue.popleft()
        count = 1
        
        while queue and queue[0] <= current:
            queue.popleft()
            count += 1
        
        answer.append(count)
    
    return answer
