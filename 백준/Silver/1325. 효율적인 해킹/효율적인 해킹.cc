#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v[10001];
bool vis[10001];
int cp = 0;
stack<int> s;
vector<int> nums;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++){
		fill(vis, vis+n+1, false);
		vis[i] = true;
		s.push(i);
		int cnt = 0;
		while(!s.empty()){
			int cur = s.top(); s.pop();
			cnt++;
			for(int i=0; i<v[cur].size(); i++){
				int nx = v[cur][i];
				if(vis[nx]) continue;
				s.push(nx);
				vis[nx] = true;
			}
		}
		nums.push_back(cnt);
		cp = max(cp, cnt);
	}
	
	for(int i=0; i<n; i++){
		if(nums[i] == cp) cout << i+1 << ' '; 
	}
	
	return 0;
}