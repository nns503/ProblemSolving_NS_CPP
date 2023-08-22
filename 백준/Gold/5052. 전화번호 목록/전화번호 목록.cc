#include <bits/stdc++.h>

using namespace std;

int T;
int main(void){
	
	cin >> T;
	
	while(T--){
		map<string, bool> m;
		vector<string> arr;
		bool chk = false;
		int n;
		cin >> n;
		while(n--){
			string s; cin >> s;
			arr.push_back(s);
		}
		
		sort(arr.begin(), arr.end());
		
		for(int i=0; i<arr.size(); i++){
			string temp = "";
			for(int k=0; k<arr[i].size(); k++){
				temp.push_back(arr[i][k]);
				if(m[temp]){
					chk = true;
				}
			}
			m[temp] = true;
		}
		
		cout << (chk?"NO":"YES") << '\n';
	}
}