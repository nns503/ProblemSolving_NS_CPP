#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v[51];
vector<pair<int, int>> score;
int dist[51];

int main(void){
	cin >> n;
	while(true){
		int a, b;
		cin >> a >> b;
		if(a == -1 && b == -1) break;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++){
		fill(dist, dist+51, -1);
		queue<int> q;
		q.push(i);
		dist[i] = 0;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(int i=0; i<v[cur].size(); i++){
				if(dist[v[cur][i]] != -1) continue;
				dist[v[cur][i]] = dist[cur] + 1;
				q.push(v[cur][i]); 
			}
		}
		score.push_back({*max_element(dist, dist+n+1), i});
	}
	sort(score.begin(), score.end());
	vector<pair<int ,int>> answer;
	answer.push_back(score[0]);
	for(int i=1; i<n; i++){
		if(score[i-1].first == score[i].first) answer.push_back(score[i]);
		else break;
	}
	cout << answer[0].first << ' ' << answer.size() << '\n';
	for(auto a : answer){
		cout << a.second << ' ';
	}
	return 0;
}