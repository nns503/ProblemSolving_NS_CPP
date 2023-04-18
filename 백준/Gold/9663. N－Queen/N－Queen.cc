#include <bits/stdc++.h>

using namespace std;

bool arr1[250]; // x
bool arr2[50]; // 좌하향 대각선 x+y 
bool arr3[50]; // 우하향 대각선 x-y+n
int n, answer;


void func(int y){
	if(y == n){
		answer++;
		return;
	}
	for(int nx=0; nx<n; nx++){
		if(arr1[nx] || arr2[nx+y] || arr3[nx-y+n]) continue;
		arr1[nx] = true;
		arr2[nx+y] = true;
		arr3[nx-y+n] = true;
		func(y+1);
		arr1[nx] = false;
		arr2[nx+y] = false;
		arr3[nx-y+n] = false;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << answer;
	return 0;
}