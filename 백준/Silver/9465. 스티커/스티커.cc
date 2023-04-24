#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int T, n;
int answer;
int score[2][100001];
int dp[2][100001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0; i<2; i++){
			for(int j=1; j<=n; j++) {
				int a;
				cin >> score[i][j];
			}
		}
		
		dp[0][1] = score[0][1];
		dp[1][1] = score[1][1];
		for(int x=2; x<=n; x++){
			for(int y=0; y<2; y++){
				dp[y][x] = max(max(dp[y][x-2] + score[(y+1)%2][x-1], dp[(y+1)%2][x-2]),dp[(y+1)%2][x-1]) + score[y][x]; 
			}
		}
		
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return 0;
}