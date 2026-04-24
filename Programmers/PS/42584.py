def solution(prices):
    answer = [0 for _ in range(len(prices))]
    
    stack = []
    for i in range(len(prices)):
        while stack and prices[i] < prices[stack[-1]]:
            j = stack.pop()
            answer[j] = i - j
        stack.append(i)
    
    while stack:
        j = stack.pop()
        answer[j] = len(prices) - j - 1
    return answer
