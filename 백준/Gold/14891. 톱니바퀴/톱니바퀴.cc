#include <bits/stdc++.h>

using namespace std;

string wheel[5];
int K;

void setWheel(int n, int dir){
	int temp;
	int start = wheel[n][0];
	int end = wheel[n][7];	
	if(dir==1){
		temp = start;
		for(int i=0;i<7;i++){
			int t = wheel[n][i+1];
			wheel[n][i+1] = temp;
			temp = t;
			
		}
		wheel[n][0] = temp;
		
	}
	else{
		temp = end;		
		for(int i=7;i>0;i--){
			int t = wheel[n][i-1];
			wheel[n][i-1] = temp;
			temp = t;
		}	
		wheel[n][7] = temp;
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