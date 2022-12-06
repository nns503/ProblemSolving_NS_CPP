#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>

using namespace std;

int binary_search(int* data, int k, int target);

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
			
	int n,m;
	cin >> n;
	int data[n];
	
	for(int i=0;i<n;i++){
		cin >> data[i];
	}
	
	sort(data,data+n);
	
	cin >> m;
	int num[m];
	for(int i=0;i<m;i++){
		cin >> num[i];
	}
	
	for(int i=0;i<m;i++){
		cout << upper_bound(data, data + n, num[i]) - lower_bound(data, data + n, num[i]) << " ";
	}	
	
	
	return 0;
}

