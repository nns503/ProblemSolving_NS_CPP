#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int T, n;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	
	while(T--){
		
		cin >> n;
		
		vector<int> arr;
		int answer = 0;

		for(int i=0; i<20; i++){
			int a; 
			cin >> a;
			arr.push_back(a);
			for(int i = arr.size() - 1 ; i>0; i--){
				if(arr[i] < arr[i-1]){
					swap(arr[i], arr[i-1]);
					answer++;
				}
				else break;
			}
		}
		
		cout << n << ' ' << answer << '\n';		
	}
	
	return 0;
}