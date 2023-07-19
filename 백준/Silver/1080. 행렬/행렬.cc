#include <bits/stdc++.h>

using namespace std;

int n, m, answer;
int A[51][51];
int B[51][51];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int y=0; y<n; y++){
		string a; cin >> a;
		for(int x=0; x<m; x++){
			A[y][x] = a[x] - '0';
		}
	}
	
	for(int y=0; y<n; y++){
		string b; cin >> b;
		for(int x=0; x<m; x++){
			B[y][x] = b[x] -'0';
		}
	}
	
	for(int y=0; y<n-2; y++){
		for(int x=0; x<m-2; x++){
			if(A[y][x] != B[y][x]){
				answer++;
				for(int i=y; i<y+3 && i<n; i++){
					for(int j=x; j<x+3 && j<m; j++){
						A[i][j] = !A[i][j];
					}
				}
			}
		}
	}

	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			if(A[y][x] != B[y][x]){
				cout << -1;
				return 0;
			}
		}
	}	
	
	cout << answer;
	return 0;
}