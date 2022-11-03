#include <iostream>

using namespace std;

int main(void){
	using namespace std;
	
	int num[8];
	bool asc = true;
	bool des = true; 
	
	for(int i=0;i<8;i++){
		cin >> num[i];
	}    
	
	for(int i=0;i<7;i++){
		if(num[i]+1==num[i+1]&&asc==true){
			des=false;
		}
		else if(num[i]-1==num[i+1]&&des==true){
			asc=false;
		}
		else{
			asc=false;
			des=false;
		}
		if(asc==false&&des==false) break;
	}
	
	if(asc==true) cout << "ascending";
	else if(des==true) cout << "descending";
	else cout << "mixed";
	
	return 0;
}

