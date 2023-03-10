#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[100010];
int answer = 2000000001;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}	
	sort(num, num+n);
	
	for(int i=0; i<n; i++){
		auto l = lower_bound(num, num + n, num[i] + m);
		int temp = l - num;
		if(num[temp] - num[i] >= m){
			answer = min(answer, num[temp] - num[i]);
		}
	}
	
	cout << answer;
	return 0;
}
