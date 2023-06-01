#include <bits/stdc++.h>

using namespace std;

int n;
bool chk[1000001];
bool vis[1000001];
vector<int> arr;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=2; i<=1000000; i++){
		if(vis[i]) continue;
		if(i % 2) {
			chk[i] = true;
			arr.push_back(i);
		}
		for(int j=i; j<=1000000; j+=i){
			vis[j] = true;
		}
	}

	while(true){
		int i = 0;
		bool o = false;
		cin >> n;
		if(n == 0) return 0;
		while(n - arr[i] >= arr[i]){
			if(chk[n - arr[i]]){
				cout << n << " = " << arr[i] << " + " << n - arr[i] << '\n';
				o = true;
				break;
			}
			i++;
		}
		if(!o) cout << "Goldbach's conjecture is wrong.\n";
	}
	
	return 0;
}