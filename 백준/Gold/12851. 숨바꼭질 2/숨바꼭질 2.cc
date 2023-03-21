#include <bits/stdc++.h>

using namespace std;

int n, k;
int t[100001];
int v[100001];
int cnt = 0;

queue<int> q;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	fill(t, t+100001, -1);
	q.push(n);
	t[n] = 0;
	v[n] = 1;
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=0; i<3; i++){
			int ncur;
			if(i==0) ncur = cur + 1;
			else if(i==1) ncur = cur + -1;
			else if(i==2) ncur = cur * 2;
			if(ncur > 100001 || ncur < 0) continue;
			if(t[ncur] == -1){
				v[ncur] = v[cur];
				t[ncur] = t[cur] + 1;
				q.push(ncur);	
			}
			else{
				if(t[ncur] == t[cur] + 1){
					v[ncur] += v[cur];
				}
			}
		}
	}

	
	cout << t[k] << '\n' << v[k];
	
	return 0;
}