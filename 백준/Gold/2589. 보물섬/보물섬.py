from collections import deque
import sys

input = sys.stdin.readline

W, H = map(int, input().rstrip().split())
map = [list(input().rstrip()) for i in range(W)]


def bfs(stY, stX, board):
    n = len(board)
    m = len(board[0])
    max_len = 0

    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]

    q = deque()
    dist = [[-1] * m for _ in range(n)]

    q.append((stY, stX))
    dist[stY][stX] = 0

    max_len = 0
    while q:
        cur_y, cur_x = q.popleft()
        

        for i in range(4):
            ny = cur_y + dy[i]
            nx = cur_x + dx[i]

            if not (0 <= ny < n and 0 <= nx < m):
                continue

            if board[ny][nx] == 'W':
                continue

            if dist[ny][nx] != -1:
                continue

            dist[ny][nx] = dist[cur_y][cur_x] + 1
            q.append((ny, nx))

            max_len = max(max_len, dist[ny][nx])
    return max_len


tmp = 0
for i in range(W):
    for j in range(H):
        if map[i][j] != 'W':
            tmp = max(tmp, bfs(i, j, map))

print(tmp)
