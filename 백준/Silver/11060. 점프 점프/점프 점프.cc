#include <bits/stdc++.h>

using namespace std;

int n, a;
vector<int> arr;
int vis[1001]; 
queue<int> q;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	arr.push_back(0);
	for(int i=0; i<n; i++){
		cin >> a;
		arr.push_back(a);
	}
	
	fill(vis, vis+1001, 1001);
	vis[1] = 0;
	q.push(1);
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		int jump = arr[cur];
		for(int i=1; i<=jump; i++){
			if(cur + i > n) break;
			if(vis[cur + i] <= vis[cur] + 1) continue;
			vis[cur+i] = vis[cur] + 1;
			q.push(cur+i);
		}
	}
	
	if(vis[n] == 1001) vis[n] = -1;
	cout << vis[n];
	
}