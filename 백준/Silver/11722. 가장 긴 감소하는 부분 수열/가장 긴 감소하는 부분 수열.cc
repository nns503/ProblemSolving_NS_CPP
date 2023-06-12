#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	while(n--){
		int a;
		cin >> a;
		if(arr.empty()) arr.push_back(a);
		else{
			int d = lower_bound(arr.begin(), arr.end(), a, greater<int>()) - arr.begin();
			if(arr.size() == d){
				arr.push_back(a);
			}
			else arr[d] = a; 			
		}
	}	
	cout << arr.size();
	return 0;
}