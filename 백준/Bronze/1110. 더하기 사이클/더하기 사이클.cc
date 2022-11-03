#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>	

using namespace std;

int main(void){
	using namespace std;
	
		int n;
		cin >> n;
        int firstn = n;
        int temp = 0;
        int trys = 0;
        
        while(true){         
            trys++;   
            temp = n/10 + n%10;    
            n = n%10*10 + temp%10; 
            if(n==firstn) break;            
        } 
		
		cout << trys;     
	return 0;
}

