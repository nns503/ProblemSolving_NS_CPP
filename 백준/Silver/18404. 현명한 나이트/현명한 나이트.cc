#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

// 문제에서 제시해준 나이트의 움직임
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int n, m;

// ㅎㅇ 
bool OOB(int y, int x){
    return (y <= 0 || x <= 0 || y > n || x > n);
}

vector<vector<int>> solve(pair<int, int> knight){
    // n+1로 한 이유는 문제에서 좌표값 1~n 까지임, 이런거 조심하세유
    vector<vector<int>> dist(n+1, vector<int>(n+1, -1));
    queue<pair<int, int>> q;
    q.push(knight);
    dist[knight.Y][knight.X] = 0; // 시작 좌표이므로 거리를 0으로 합니다.

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int i=0; i<8; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue; // 조건 1, 맵 밖에 나갔냐
            if(dist[ny][nx] != -1) continue; // 조건 2, 방문했는가
            // 조건 3, 장애물인가. 이번 문제도 없네요

            dist[ny][nx] = dist[cur.Y][cur.X] + 1; // 지금 dist + 1 => 다음 좌표로 가는 거리
            q.push({ny, nx});
        }
    }

    return dist;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // n, m 입력
    cin >> n >> m;
    
    // 초기 나이트 위치 입력
    pair<int, int> knight;
    cin >> knight.Y >> knight.X;

    // 상대방 위치 입력
    vector<pair<int, int>> arr(m);
    for(auto &cur : arr){
        cin >> cur.Y >> cur.X;
    }
    
    // 거리를 모은 좌표
    vector<vector<int>> dist = solve(knight);

    // 각 상대편 말을 잡기 위한 최소 이동 수, 입력 시에 상대편 말 정보가 주어졌던 순서에 맞게 차례대로 출력
    for(int i=0; i<m; i++){
        cout << dist[arr[i].Y][arr[i].X] << ' ';
    }

    return 0;
}