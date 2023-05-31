#include <bits/stdc++.h>

using namespace std;

int z, x, c;
char c1;
char c2 = '!';

bool sum(int a, int b, int t){
	return (t == (a + b)); 
}

bool min(int a, int b, int t){
	return (t == (a - b));
}

bool div(int a, int b, int t){
	return (t == (a / b));
}

bool mul(int a, int b, int t){
	return (t == (a * b));
}

void answer(){
	cout << z << c1 << x << c2 << c;
}

int main(void){
	
	cin >> z >> x >> c;
	
	c1 = '=';
	
	if(sum(x, c, z)){
		c2 = '+';		
		answer();
	}
	else if(min(x, c, z)){
		c2 = '-';		
		answer();
	}
	else if(div(x, c, z)){
		c2 = '/';		
		answer();
	}
	else if(mul(x, c, z)){
		c2 = '*';		
		answer();
	}
	
	if(c2 != '!') return 0;
	
	c2 = '=';
	if(sum(z, x, c)){
		c1 = '+';		
		answer();
	}
	else if(min(z, x, c)){
		c1 = '-';		
		answer();
	}
	else if(div(z, x, c)){
		c1 = '/';		
		answer();
	}
	else if(mul(z, x, c)){
		c1 = '*';		
		answer();
	}	


	return 0;
}
