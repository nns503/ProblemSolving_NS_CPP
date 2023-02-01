#include <iostream>

using namespace std;

bool half(int t, int a){
	if(a>=t){
		return true;
	}
	else{
		return false;
	} 
} 

int Z(int n, int r, int c){
	int t = 1 << n;
	int xt = t/2;
	int yt = t/2;
	int z = 0;
	int s = 1 << 2*(n-1);
	for(int i=1;i<=n;i++){
		t /= 2;
		if(half(xt,c)&&half(yt,r)){
			xt += t/2;
			yt += t/2;
			z += s*3;
		}
		else if(!half(xt,c)&&half(yt,r)){
			xt -= t/2;
			yt += t/2;
			z += s*2;			
		}
		else if(half(xt,c)&&!half(yt,r)){
			xt += t/2;
			yt -= t/2;
			z += s;			
		}
		else if(!half(xt,c)&&!half(yt,r)){
			xt -= t/2;
			yt -= t/2;			
		}				
		s /= 4;
	}
	return z;
}

int main(void){
	int n,r,c;
	cin >> n >> r >> c;
	cout << Z(n,r,c);
	return 0;
}

