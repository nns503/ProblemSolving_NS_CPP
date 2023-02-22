#include <bits/stdc++.h>

using namespace std;

int N,S;	
int num[20];
bool chk[20];
int result=0;


void func(int cnt, int sum){
	if(cnt==N){
		if(sum==S) result++;
		return;
	}
	func(cnt+1,sum);
	func(cnt+1,sum+num[cnt]);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> S;
	for(int i=0;i<N;i++) cin >> num[i];
	sort(num,num+N);
	
	func(0,0);
	if(S==0) result--;
	cout << result;
	
	return 0;
}