#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		arr.push_back(a);
	}
	
	sort(arr.begin(), arr.end());
	
	cout << arr.front() * arr.back();
	return 0;
}