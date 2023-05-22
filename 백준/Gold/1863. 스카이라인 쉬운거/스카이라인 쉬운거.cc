#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> s;
int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	s.push(-1);
	while(n--){
		int x, y;
		cin >> x >> y;
		int t = s.top();
		
		if(y == 0){
			while(s.top() != -1){
				answer++;
				s.pop();
			}
		}
		else if(y > t) s.push(y);
		else if(y < t){
			while(s.top() != -1 && y < s.top()){
				s.pop();
				answer++;
			}  	
			if(s.top() != y) s.push(y);
		}
	}	

	cout << answer + s.size() - 1;
}