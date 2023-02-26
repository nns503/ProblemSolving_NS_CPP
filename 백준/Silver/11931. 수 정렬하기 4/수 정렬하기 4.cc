#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

bool cmp(int a, int b){
	return a>b;
} 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(), cmp);
	
	for(int i=0;i<n;i++){
		cout << v[i] << '\n';
	}
	
	return 0;
}