#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>

using namespace std;

int main(void){
	using namespace std;
	
	int t,h,w,n;
	int room;
	int x,y;
	
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> h >> w >> n ;
		if(n%h==0) y=h;
		else y=n%h;
		
		x=ceil((double)n/h);
		
		room = y*100+x;
		cout << room << "\n";
	}
	
	return 0;
}

