#include <bits/stdc++.h>

using namespace std;

int T, n;

int cul(string s){
	deque<int> num;
	deque<char> op;
	for(int i=0; i<s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num.push_back(s[i] - '0');
		}
		else if(s[i] == ' '){
			int temp = num.back(); num.pop_back();
			temp *= 10;
			temp += s[i+1] - '0';
			i++;
			num.push_back(temp);
		}
		else{
			op.push_back(s[i]);
		}
	}
	
	int sum = num.front(); num.pop_front();
	while(!num.empty()){
		if(op.front() == '+'){
			sum += num.front();
			num.pop_front();
			op.pop_front();
		}
		else{
			sum -= num.front();
			num.pop_front();
			op.pop_front();
		}
	}
	
	return sum;
} 

void func(int cnt, string s){
	if(cnt == n){
		if(cul(s) == 0){
			cout << s << '\n';
		}
		return ;
	}
	cnt++;
	s.push_back(' '); s.push_back(cnt + '0'); 
	func(cnt, s); 
	s.replace(s.end() - 2, s.end() - 1, "+"); 
	func(cnt, s);
	s.replace(s.end() - 2, s.end() - 1, "-");
	func(cnt, s);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		string s = "1";
		func(1, s);
		cout << '\n';
		
	}
	return 0;
}