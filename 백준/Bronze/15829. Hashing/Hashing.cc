#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>
#include <vector>
#define M 1234567891

using namespace std;

int main(void){
	
	int l;
	long long int sum = 0;
	long long int r=1;
	string word;
	cin >> l >> word;
	for(int i=0;i<l;i++){
		sum = (sum+(word[i]-'a'+1)*r)%M;
		r = r*31%M;
	}
	
	cout << sum;
	
	return 0;
}

