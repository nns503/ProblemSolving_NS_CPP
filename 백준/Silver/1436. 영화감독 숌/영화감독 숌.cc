#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>

using namespace std;

bool con_six(int *num,int len);

int main(void){
	using namespace std;
	
	int n;
	int temp;
	int count=0;
	int len=0;
	int num[20];
	int result;
	cin >> n; 
	
	for(int i=666;;i++){
		temp = i;
		for(int j=0;temp>0;j++){
			num[j] = temp%10;
			temp /= 10;
			len++; 
		}
		if(con_six(num,len)==true) count++;
		if(count==n){
			result = i;
			break;
		}
		len = 0;
	}
	
	cout << result;
	return 0;
}

bool con_six(int *num,int len){
	bool check = false;
	for(int i=0;i<len-2;i++){
		if(num[i]==6&&num[i+1]==6&&num[i+2]==6) check = true;
	}
	return check;
}
