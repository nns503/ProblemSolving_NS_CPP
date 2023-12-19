#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int n, l;
int num;
deque<pair<int, int>> dq;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> l;
	for(int i=1; i<=n; i++){
		cin >> num;
		if(dq.empty() || num <= dq.front().A){
			dq.clear();
			dq.push_front({num, i});
		}
		else{
			while(!dq.empty() && dq.front().B < i-l+1){
				dq.pop_front();
			}
			while(!dq.empty() && dq.back().A >= num){
				dq.pop_back();
			}
			dq.push_back({num, i});
		}
		cout << dq.front().A << ' ';
	}	
	return 0;
}