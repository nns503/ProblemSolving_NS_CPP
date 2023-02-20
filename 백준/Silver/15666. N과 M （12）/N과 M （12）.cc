#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[8];
int num[8];

void func(int cnt, int order){
	if(cnt==m){
		for(int i=0;i<m;i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int temp = 0;
	for(int i=0;i<n;i++){
		if(num[i]<num[order]) continue;
		if(temp == num[i]) continue;
		arr[cnt] = num[i];
		temp = num[i];
		func(cnt+1,i);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++) cin >> num[i];
	sort(num,num+n);
	
	func(0,0);
	
	return 0;
}