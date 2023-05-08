#include <bits/stdc++.h>

using namespace std;

int n, k;
int answer;
vector<int> arr(201);
vector<bool> rob(201);

void moveArr(){
	int temp = arr[2*n];
	for(int i=2*n; i>1; i--){
		arr[i] = arr[i-1];
		arr[i-1] = 0;
		rob[i] = rob[i-1];
		rob[i-1] = false;
	}
	arr[1] = temp;
	if(rob[n]) rob[n] = false;
}

void moveRob(){
	for(int i=2*n-1; i>=1; i--){
		if(!rob[i]) continue;
		if(!rob[i+1] && arr[i+1] > 0){
			arr[i+1]--;
			rob[i+1] = true;
			rob[i] = false;
		}
	}
	if(rob[n]) rob[n] = false;
	
}

int getZ(){
	int cnt = 0;
	for(int i=1; i<=2*n; i++){
		if(arr[i] == 0) cnt++;
	}	
	return cnt;
} 


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=1; i<=2*n; i++) cin >> arr[i];
	
	while(getZ() < k){
		answer++;
		moveArr();
		moveRob();
		if(arr[1] > 0){
			arr[1]--;
			rob[1] = true;
		}
	}
	
	cout << answer;
	return 0;
}