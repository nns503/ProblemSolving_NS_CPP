#include <bits/stdc++.h>

using namespace std;

class cmp{
public:
	bool operator()(long long a, long long b){
		if(abs(a) == abs(b)){
			if(a==b) return false;
			return a > b;
		}
		return abs(a) > abs(b);
	}
};
priority_queue<long long, vector<long long>, cmp> Q;
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		if(a==0){
			if(Q.empty()) cout << 0 << '\n';
			else{
				cout << Q.top() << '\n';
				Q.pop();
			}
		}
		else{
			Q.push(a);
		}
	}
	return 0;
}