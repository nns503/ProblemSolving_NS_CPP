#include <bits/stdc++.h>

using namespace std;

int n,m;
int num[8];
int arr[8];
bool chk[8];

void func(int cnt){
	if(cnt==m){
		for(int i=0;i<m;i++){
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for(int i=0;i<n;i++){
		if(chk[i]) continue;
		arr[cnt]=num[i];
		chk[i]=true;
		func(cnt+1);
		chk[i]=false;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> num[i];
	sort(num,num+n);
	func(0);
	return 0;
}