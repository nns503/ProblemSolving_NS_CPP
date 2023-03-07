#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int tower[500001];

int main(void){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	stack<pair<int, int>> S;
	
	int n;
	cin >> n;
	
	S.push({100000001, 0});
	for(int i=1; i<=n; i++){
		cin >> tower[i];
	}
	
	for(int i=1; i<=n; i++){
		while(S.top().X<=tower[i]){
			S.pop();
		}
		cout << S.top().Y << ' ';
		S.push({tower[i], i});
	}
	
	return 0;
}