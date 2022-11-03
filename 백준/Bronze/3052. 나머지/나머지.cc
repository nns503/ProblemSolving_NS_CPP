#include <iostream>
#include <algorithm>
#include <cmath>	

using namespace std;

int main(void){
	using namespace std;
	
	int num[10];
	int n=1;
	
	for(int i=0;i<10;i++){
		cin >> num[i];
		num[i] %= 42;
	}
	
	sort(num,num+10);
	
	for(int i=0;i<9;i++){
		if(num[i]!=num[i+1]){
			n++;
		}
	}
	
	cout << n;
	
	return 0;
}