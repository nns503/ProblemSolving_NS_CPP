#include <bits/stdc++.h>

using namespace std;

int n;
int L[21];
int J[21];
int answer = 0;
int pr = 0;
int hp = 100;

void func(int cnt){
	
	if(hp <= 0){
		answer = max(answer, pr - J[cnt-1]);
		return ;
	}
	if(cnt == n){
		answer = max(answer, pr);
		return ;
	}
	
	
	for(int i=cnt; i<n; i++){
		hp -= L[i];
		pr += J[i];
		func(i+1);
		hp += L[i];
		pr -= J[i];
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++) cin >> L[i];
	for(int i=0; i<n; i++) cin >> J[i];
	
	func(0);
	cout << answer;
	
	
}