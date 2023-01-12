	#include <iostream>
	#include <string>
	#include <vector>
	#include <algorithm>
	#include <cmath>
	using namespace std;
	
	int cipher(int a,int p){
		int sum = 0;
		while(a>0){
			sum += pow(a%10,p);
			a/=10;
		}
		return sum;		
	}
			
	void Recurring(int a,int p, bool check[]){
		check[a] = true;
		int sum = cipher(a,p);
		if(check[sum]==true) {
			check[sum] = false;
		}
		else{
			check[sum] = true;
			Recurring(sum,p,check);
		}	
	}
	
	
	int main(void){
		int a,p;
		cin >> a >> p;
		bool check[1000000];
		fill_n(check,1000000,false);	
		Recurring(a,p,check);
		int n = 0;
		while(check[a]){
			n++;
			a = cipher(a,p);
		}
		cout << n;
		return 0;
	}
