#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> r(3);
vector<char> bk;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		char a;
		cin >> a;
		bk.push_back(a);
	}
	
	r[0] = abs(n - 100);
	if(m == 10) {
		cout << r[0];
		return 0;
	}
	int t = n;
	
	while(true){
		string s = to_string(t);
		bool chk = true;
		for(int i=0; i<m; i++){
			if(s.find(bk[i]) != string::npos){
				chk = false; 
			}
		}
		if(chk) {
			r[1] += s.size();
			break;
		}
		r[1]++;
		t--;
		if(t<0){
			r[1] = 1000000;
			break;
		}
		if(r[1]>500000) break;
	}
	
	t = n;
	while(true){
		string s = to_string(t);
		bool chk = true;
		for(int i=0; i<m; i++){
			if(s.find(bk[i]) != string::npos){
				chk = false; 
			}
		}
		if(chk) {
			r[2] += s.size();
			break;
		}
		r[2]++;
		t++;
		if(r[2]>500000) break;
	}	
	int answer = *min_element(r.begin(), r.end());
	cout << answer;
	return 0;
}