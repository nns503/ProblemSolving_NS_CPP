#include <bits/stdc++.h>

using namespace std;

int n, sc, p;
int arr[51];
int rk[51];
int answer = 1;
int scrk = 1;

int main(void){
	ios::sync_with_stdio(0);
//	cin.tie(0);
	
	cin >> n >> sc >> p;
	
	arr[0] = 2000000001;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		if(arr[i-1] == arr[i]) rk[i] = rk[i-1];
		else rk[i] = i;
	}
	
	for(int i=1; i<=n; i++){
		if(arr[i] > sc) scrk++;
		if(arr[i] >= sc) answer++;
	}
	
	if(answer <= p) cout << scrk;
	else cout << -1;

	return 0;
}