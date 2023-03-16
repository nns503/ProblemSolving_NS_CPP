#include <bits/stdc++.h>

using namespace std;

int s, e, q, cnt;
map<string, int> m;

int convertTime(string s){
	return ((int)(s[0]-'0')*10 + s[1] -'0')*60 + ((int)(s[3]-'0')*10 + s[4] -'0'); 
	
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string temp1, temp2, temp3;
	cin >> temp1 >> temp2 >> temp3;
	s = convertTime(temp1);
	e = convertTime(temp2);
	q = convertTime(temp3);
	
	while(true){
		string time, name;
		cin >> time >> name;
		if(cin.eof() == true) break; 
		int ct = convertTime(time);
		if(m.find(name) == m.end()){
			if(ct <= s) m[name] = ct; 
		}
		else{
			if(m[name] != -1 && ct >= e && ct <= q) {
				cnt++;
				m[name] = -1;
			}
		}
	}
	
	cout << cnt;
	return 0;
}