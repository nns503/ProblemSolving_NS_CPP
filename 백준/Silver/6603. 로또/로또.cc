#include <bits/stdc++.h>

using namespace std;

int k;
int num[14];
int arr[14];
bool chk[14];

void lotto(int cnt, int order){
	if(cnt == 6){
		for(int i=0;i<6;i++) cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	
	for(int i=order;i<k;i++){
		if(chk[i]==true) continue;
		chk[i] = true;
		arr[cnt] = num[i];
		lotto(cnt+1,i);
		chk[i] = false;
	}
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		cin >> k;
		if(k==0) return 0;
		for(int i=0;i<k;i++) cin >> num[i];
		sort(num,num+k);
		lotto(0,0);
		cout << '\n';
	}
}