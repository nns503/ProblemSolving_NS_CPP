#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<bool>> &answer, vector<vector<bool>> &board, int n, int st){
    stack<int> s;
    s.push(st);
    vector<bool> vis(n, false);

    while(!s.empty()){
        auto cur = s.top(); s.pop();
        for(int nxt=0; nxt<n; nxt++){
            if(!board[cur][nxt]) continue;
            if(vis[nxt]) continue;
            answer[st][nxt] = true;
            vis[nxt] = true;
            s.push(nxt);
        }
    }

}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, a;
    
    T = 1;

    while(T--){
        cin >> n;
        vector<vector<bool>> board(n, vector<bool>(n));
        vector<vector<bool>> answer(n, vector<bool>(n));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> a;
                if(a) board[i][j] = true;
            }
        }

        for(int i=0; i<n; i++) DFS(answer, board, n, i);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << answer[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}