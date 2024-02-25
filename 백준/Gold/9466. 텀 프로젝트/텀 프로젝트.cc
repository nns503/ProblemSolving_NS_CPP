    #include <bits/stdc++.h>

    using namespace std;

    int T, n;
    int nxt[100001];
    int vis[100001];

    int main(void){
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> T;

        while(T--){
            fill(vis, vis+100001, 0);
            cin >> n;
            int answer = n;

            for(int i=1; i<=n; i++){
                cin >> nxt[i];
            }

            for(int i=1; i<=n; i++){
                if(vis[i] != 0) continue;
                int cur = i;
            
                while(true){
                    if(vis[cur] != i && vis[cur] != 0) break;
                    if(vis[cur] == 0){
                        vis[cur] = i;
                    }
                    else if(vis[cur] == i){
                        vis[cur] = -1;
                        answer--;
                    }
                    cur = nxt[cur];
                }
                
            }

            cout << answer << '\n';

        }
        return 0;
    }