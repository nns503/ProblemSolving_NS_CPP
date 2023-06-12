#include <bits/stdc++.h>

using namespace std;

int n, m;
int t1, t2;
vector<int> arr[101];
int d[101];
queue<int> q;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> t1 >> t2;
	cin >> m;
	
	fill(d, d+101, -1);
	while(m--){
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}	
	
	q.push(t1);
	d[t1] = 0;
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int nxt : arr[cur]){
			if(d[nxt] != -1) continue;
			d[nxt] = d[cur] + 1;
			q.push(nxt);
		}
	}
	
	cout << d[t2];
	
	return 0;
}