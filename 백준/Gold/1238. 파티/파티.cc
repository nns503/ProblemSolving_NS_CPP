#include <bits/stdc++.h>

using namespace std;

int d[1001][1001];
int n, m, x;
int sum[1001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> x;
	
	for(int i=1; i<=n; i++) fill(d[i], d[i]+1001, 10000000);
	for(int i=1; i<=n; i++) d[i][i] = 0;
	
	while(m--){
		int a, b, t;
		cin >> a >> b >> t;
		d[a][b] = t;
	}
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	
	for(int i=1; i<=n; i++) sum[i] = d[i][x] + d[x][i];
	cout << *max_element(sum+1, sum+n+1);

	
	
	return 0;
}