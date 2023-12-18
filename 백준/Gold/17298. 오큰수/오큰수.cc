#include <bits/stdc++.h>
#define A first
#define B second
using namespace std;

int arr[1000001];
int n;
stack<pair<int ,int>> stk;


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	int h;
	fill(arr, arr+1000001, -1);
	stk.push({0x3f3f3f3f, 0});
		
	for(int i=1; i<=n; i++){
		cin >> h;
		
		while(stk.top().A < h){
			arr[stk.top().B] = h;
			stk.pop();
		}
		
		stk.push({h, i});
	}
	
	for(int i=1; i<=n; i++){
		cout << arr[i] << ' ';
	}
	return 0;
}