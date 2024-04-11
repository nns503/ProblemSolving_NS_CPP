#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m, a, b, cnt;
    
    T = 1;

    while(T--){
        cin >> n >> m;
        vector<int> num(n+1);
        vector<vector<int>> adj(n+1);
        
        for(int i=0; i<m; i++){
            cin >> cnt;
            cin >> a;
            for(int k=1; k<cnt; k++){
                cin >> b;
                num[b]++;
                adj[a].push_back(b);
                a = b;
            }
        }

        int number = 0;
        queue<int> q;
        vector<int> answer;
        for(int i=n; i>=1; i--){
            if(num[i] == 0) {
                number++;
                q.push(i);
                answer.push_back(i);
            }
        }

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur]){
                num[nxt]--;
                if(num[nxt] == 0){
                    answer.push_back(nxt);
                    q.push(nxt);
                    number++;
                }
            }
        }

        if(number < n) cout << 0;
        else{
            for(auto cur : answer){
                cout << cur << '\n';
            }
        }

        

    }
    return 0;
}