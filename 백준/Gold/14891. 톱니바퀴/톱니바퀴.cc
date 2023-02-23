#include <bits/stdc++.h>

using namespace std;

string wheel[5];
int K;

void setWheel(int n, int dir){
	if(dir==1){
		rotate(wheel[n].begin(), wheel[n].begin()+7, wheel[n].end());	
	}
	else{
		rotate(wheel[n].begin(), wheel[n].begin()+1, wheel[n].end());
	}
}

void moveRight(int cur, int dir){
	if(cur>=4) return;
	if(wheel[cur][2+dir]!=wheel[cur+1][6]) {
		setWheel(cur+1, -dir);
		moveRight(cur+1, -dir);
	}
}

void moveLeft(int cur, int dir){
	if(cur<=1) return;
	if(wheel[cur][6+dir]!=wheel[cur-1][2]) {
		setWheel(cur-1, -dir);
		moveLeft(cur-1, -dir);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=1;i<=4;i++){
		cin >> wheel[i];
	}
	cin >> K;
	while(K--){
		int n, dir;
		cin >> n >> dir;
		setWheel(n,dir);
		moveRight(n,dir);
		moveLeft(n,dir);
	}
	

	int answer = 0;
	for(int i=1;i<=4;i++){
		if(wheel[i][0]=='1'){
			answer += (1<<(i-1));
		}
	}
	
	cout << answer;
	
	
	return 0;
}