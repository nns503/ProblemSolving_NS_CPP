#include <iostream>
#include <algorithm>
#include <string>

int main(void){
	using namespace std;
	
	string s;
	cin >> s;
	
	int n = s.size();
	int num[n];
	
	for(int i=0;i<n;i++){
		num[i] = s[i]-'0';
	}
	
	sort(num,num+n,greater<int>());
	
	for(int i=0;i<n;i++){
		cout << num[i];
	}
	
	return 0;
}
