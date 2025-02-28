#include <bits/stdc++.h>

using namespace std;

vector<int> p(1000001, -1);
vector<int> adj[1000001];
vector<int> vis(1000001, false);

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int ans = 0;
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        if(p[edge[0]] == -1){
            p[edge[0]] = 0;
        }
        if(p[edge[1]] == -1){
            p[edge[1]] = 0;
        }
        p[edge[1]]++;
    }
    for(int i=1; i<=1000000; i++){
        if(p[i] == 0 && adj[i].size() >= 2){
            ans = i;
            break;
        }
    }
    
    answer.push_back(ans);
    
    int z = 0, w = 0, e = 0;
    for(auto cur : adj[ans]){
        int a = 0;
        int b = 0;
        queue<int> q;
        q.push(cur);
        vis[cur] = true;
        while(!q.empty()){
            auto x = q.front(); q.pop();
            a++;
            for(auto nxt : adj[x]){
                b++;
                if(vis[nxt]) continue;
                vis[nxt] = true;
                q.push(nxt);
            }
        }
        if(a == b) z++;
        else if(a == b + 1) w++;
        else e++;
    }
    answer.push_back(z);
    answer.push_back(w);
    answer.push_back(e);
    return answer;
}

// 1:00