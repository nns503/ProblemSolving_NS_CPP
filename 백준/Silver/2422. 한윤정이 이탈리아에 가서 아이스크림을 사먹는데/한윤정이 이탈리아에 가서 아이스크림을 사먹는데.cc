#include <bits/stdc++.h>

using namespace std;
int n, m;
bool cant[201][201];
long long answer;
int arr[2];

void func(int st, int cnt){
	if(st > n) return;
	if(cnt == 2){
		if(!cant[arr[0]][st] && !cant[arr[1]][st]){
			answer++;
		}
		func(st+1, cnt);
	}
	else{
		for(int i=st; i<n; i++){
			if(cant[arr[0]][i]) continue;
			if(cant[arr[1]][i]) continue;
			arr[cnt] = i;
			func(i+1, cnt+1);
			arr[cnt] = 0;
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		cant[a][b] = true;
		cant[b][a] = true;
	}
	
	func(1, 0);
	
	cout << answer;
	
	return 0;
}