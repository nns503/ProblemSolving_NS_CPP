#include <bits/stdc++.h>

using namespace std;

int n;
int board[21][21];
vector<int> arr;
int answer = 10000000;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> board[i-1][j-1];
		}
	}
	
	for(int i=0; i<n/2; i++) arr.push_back(0);
	for(int i=n/2; i<n; i++) arr.push_back(1);
	
	do{
		int S = 0;
		int L = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(arr[i] == 1 && arr[j] == 1){
					S += board[i][j];
				}
				else if(arr[i] == 0 && arr[j] == 0){
					L += board[i][j];
				}
			}
		}
		answer = min(answer, abs(S-L));
	}while(next_permutation(arr.begin(), arr.end()));
	cout << answer;
	return 0;
}

