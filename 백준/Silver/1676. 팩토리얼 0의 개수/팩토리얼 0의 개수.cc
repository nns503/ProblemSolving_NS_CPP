#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>
#include <climits>

using namespace std;

int fivecheck(int i){
	int stack = 0;
	while(i%5==0){
		stack++;
		i/=5;
	}
	return stack;
}

int main(void){
	int n;
	cin >> n;
	
	int five=0;
	
	for(int i=1;i<=n;i++){
		if(i%5==0){
			five+=fivecheck(i);
		}
	}
	
	cout << five;
	return 0;
}
