#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> snack;

bool solve(int x){
	int num = 0;
	for(int i=0; i<n; i++){
		num += snack[i]/x;
	}
	return num>=m;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		snack.push_back(a);
	}
	sort(snack.begin(), snack.end());
	int st = 0;
	int en = snack[n-1];
	while(st<en){
		int mid = (st+en+1)/2;
		if(solve(mid)) st = mid;
		else{
			en = mid-1;
		}
	}
	cout << st;
	return 0;
}