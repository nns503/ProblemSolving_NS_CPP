#include <bits/stdc++.h>

using namespace std;

int n, len;
int num[2];
vector<int> arr(21);
int answer = 0x3f3f3f3f;

void func(int l, int move){
	if(l == len){
		if(answer > move) answer = move;
		return;
	}
	
	for(int i=0; i<2; i++){
		int cur = arr[l];
		move += abs(num[i] - cur);
		swap(num[i], cur);
		func(l+1, move);
		move -= abs(num[i] - cur);
		swap(num[i], cur);
	} 
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	cin >> num[0] >> num[1];

	cin >> len;
	
	for(int i=0; i<len; i++) cin >> arr[i];
	
	func(0, 0);
	
	cout << answer;
	
	return 0;
}