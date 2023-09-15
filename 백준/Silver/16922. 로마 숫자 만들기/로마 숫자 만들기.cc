#include <bits/stdc++.h>

using namespace std;

int n;
int num[4] = {1, 5, 10, 50}; 
vector<int> arr = {1, 5, 10, 50}; 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=2; i<=n; i++){
		vector<int> temp;
		for(int j=0; j<arr.size(); j++){
			for(int k=0; k<4; k++){
				int t = arr[j] + num[k];
				if(find(temp.begin(), temp.end(), t) == temp.end()){
					temp.push_back(t);
				}
			}
		}
		arr.swap(temp);
	}
	
	cout << arr.size();
	return 0;
}