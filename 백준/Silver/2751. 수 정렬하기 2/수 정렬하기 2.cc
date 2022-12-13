#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>
#include <vector>

using namespace std;


int main(void){
	
	int n;
	cin >> n;
	vector<int> num;
	
	for(int i=0;i<n;i++){
		int x = 0;
		cin >> x;
		num.push_back(x);
	}
	
	sort(num.begin(),num.end());
	
	vector<int>::iterator iter;
	
	for (iter = num.begin(); iter != num.end(); iter++) {
		cout << *iter << "\n";
	}
}

