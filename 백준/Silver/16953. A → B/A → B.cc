#include <bits/stdc++.h>
#define X first
#define Y second


using namespace std;

int a, b;
queue<pair<int, int>> Q;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	
	Q.push({a, 1});
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		if(cur.X == b){
			cout << cur.Y;
			return 0;
		}
		if(b >= cur.X * 2){
			Q.push({cur.X*2, cur.Y + 1});
		}
		if(99999999 >= cur.X){
			Q.push({cur.X*10+1, cur.Y + 1});
		}
	}
	
	cout << -1;
	return 0;
}