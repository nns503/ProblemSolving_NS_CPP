import math
from collections import deque

def solution(progresses, speeds):
    answer = []
    count = 1
    days = deque([])
    for idx in range(0, len(progresses)):
        days.append(math.ceil((100 - progresses[idx]) / speeds[idx]))
    print(days)
    d = days.popleft()
    for idx in range(0, len(days)):
        day = days.popleft()
        if day <= d:
            count += 1

        else:
            answer.append(count)
            count = 1
        d = max(d, day)
    answer.append(count)
    return answer