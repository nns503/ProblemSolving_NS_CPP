#include <bits/stdc++.h>

using namespace std;

int n;
string multi(string num){
	int len = num.size();
	int p = 0; 
	for(int i=0; i<len; i++){
		int temp = num[i] - '0';
		temp *= 2;
		temp += p;
		p = temp / 10;
		num[i] = ((temp % 10) + '0');
	}
	while(p > 0){
		num.push_back((p % 10) + '0');
		p /= 10;
	}
	return num;
}

string min(string num){
	if(num[0] != '0'){
		num[0] = num[0] - 1;
		return num;
	}
	int p = -1;
	int len = num.size();
	for(int i=1; i<len; i++){
		int temp = num[i] - '0';
		if(temp == 0){
			num[i] = 9 + '0';
		}
		else{
			num[i] = temp - 1 + '0';
			return num;
		}
	}
}

void hanoi(int t, int a, int to, int b){
	if(t == 1){
		cout << a << ' ' << b << '\n';
		return;
	}
	else{
		hanoi(t-1, a, b, to);
		cout << a << ' ' << b << '\n';
		hanoi(t-1, to, a, b);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	string s = "1";
	int t = n;
	while(t--){
		s = multi(s);
	}
	s = min(s);
	reverse(s.begin(), s.end());
	cout << s << '\n';
	if(n <= 20) hanoi(n, 1, 2, 3);
	

	return 0;
}