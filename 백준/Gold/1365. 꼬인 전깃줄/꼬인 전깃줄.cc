#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> seq;

int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	seq.push_back(1000000);
	
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		
		int b = seq.back();
		
		// 증가 
		if(b > a){
			seq[(upper_bound(seq.begin(), seq.end(), a) - seq.begin())] = a;
		}
		else if(a > b){
			seq.push_back(a);
		}
		

	}
	
	answer = n - seq.size();
	cout << answer;
	return 0;
}

