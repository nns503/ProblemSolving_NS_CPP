#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
deque<pair<int, int>> dq;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		int a; cin >> a;
		dq.push_back({a, i});
	}	
	
	while(dq.size() > 1){
		auto cur = dq.front(); dq.pop_front();
		int cnt = cur.X;
		cout << cur.Y << ' ';
		if(cnt > 0){
			cnt--;
			while(cnt--){
				auto temp = dq.front(); dq.pop_front();
				dq.push_back(temp);
			}
		}
		else if(cnt < 0){
			cnt *= -1;
			while(cnt--){
				auto temp = dq.back(); dq.pop_back();
				dq.push_front(temp);
			}
		}
	}
	
	cout << dq.front().Y;
	return 0;
}