#include <bits/stdc++.h>

using namespace std;

int TC;
int n, m, w;
int d[501][501];
const int INF = 10001;

int main(void){
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	cin >> TC;
	
	while(TC--){
		int s, e, t;
		for(int i=1; i<=500; i++){
			fill(d[i], d[i]+501, INF);
		}
		
		cin >> n >> m >> w;
		
		for(int i=1; i<=n; i++) d[i][i] = 0;
		
		while(m--){
			cin >> s >> e >> t;
			if(d[s][e] > t) d[s][e] = t;
			if(d[e][s] > t) d[e][s] = t;
		}	
		
		while(w--){
			cin >> s >> e >> t;
			if(d[s][e] > -t) d[s][e] = -t;
		}
		
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
		bool chk = false;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(d[i][j] + d[j][i] < 0){
					cout << "YES\n";
					chk = true;
					break;
				}
			}
			if(chk) break;
		}
		if(!chk) cout << "NO\n";
	}	
	return 0;
}