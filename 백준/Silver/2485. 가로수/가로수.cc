#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
int g;
int answer;

int GCD(int a, int b){
	if(b == 0) return a;
	else return GCD(b, a%b);	
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	while(n--){
		int a; 
		cin >> a;
		arr.push_back(a);
	}
	g = arr[1] - arr[0];
	
	for(int i = 2; i<arr.size(); i++){
		int a = max(g, arr[i] - arr[i-1]);
		int b = min(g, arr[i] - arr[i-1]);
		g = GCD(a, b);	
	}

	for(int i = 1; i<arr.size(); i++){
		int d = arr[i] - arr[i-1]; 
		if(d == g) continue;
		else{
			answer += d / g - 1;  
		}
	}
	
	cout << answer;
	
	return 0;
}

