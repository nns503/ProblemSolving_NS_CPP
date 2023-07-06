#include <bits/stdc++.h>

using namespace std;

int n[3];
int sum;
bool vis[1501][1501]; 
queue<tuple<int, int, int>> q;

bool chk(int z, int w, int e){
	return (z == w && z == e);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n[0] >> n[1] >> n[2];
	sum = n[0] + n[1] + n[2];
	
	if(sum % 3 != 0){
		cout << 0;
		return 0;
	}
	
	sort(n, n+3);
	
	vis[n[0]][n[1]] = true;
	vis[n[0]][n[2]] = true;
	vis[n[1]][n[0]] = true;
	vis[n[2]][n[0]] = true;
	vis[n[1]][n[2]] = true;
	vis[n[2]][n[1]] = true;
	
	q.push(make_tuple(n[0], n[1], n[2]));
	
	while(!q.empty()){
		tie(n[0], n[1], n[2]) = q.front(); q.pop();
		sort(n, n+3);
	
		int t1, t2, t3;

		t1 = n[0] + n[0];
		t2 = n[1] - n[0];
		t3 = n[2];
		
		if(!vis[t1][t2]){
			vis[t1][t2] = true;
			vis[t2][t1] = true;
			q.push(make_tuple(t1, t2, t3));
		}
		
		t1 = n[0] + n[0];
		t2 = n[2] - n[0];
		t3 = n[1];
		
		if(!vis[t1][t2]){
			vis[t1][t2] = true;
			vis[t2][t1] = true;
			q.push(make_tuple(t1, t2, t3));			
		}
		
		t1 = n[1] + n[1];
		t2 = n[2] - n[1];
		t3 = n[0];
		
		if(!vis[t1][t2]){
			vis[t1][t2] = true;
			vis[t2][t1] = true;
			q.push(make_tuple(t1, t2, t3));
		}
	}
	
	if(vis[sum/3][sum/3]) cout << 1;
	else cout << 0;
	return 0;
}
