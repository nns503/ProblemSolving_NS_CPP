#include <bits/stdc++.h>

using namespace std;

int n;
string code[51];

int getSum(string s){
	int sum = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum += (s[i]-'0');
		}
	}
	return sum;
}

bool cmp(string a, string b){
	
	if(a.size()==b.size()){
		if(getSum(a)==getSum(b)) return a < b;
		return getSum(a) < getSum(b);
	}
	return a.size() < b.size();
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> code[i];
	}
	
	sort(code, code+n, cmp);
	
	for(int i=0; i<n; i++){
		cout << code[i] << '\n';
	}
		
	return 0;
}