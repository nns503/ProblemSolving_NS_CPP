#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>	

using namespace std;

void connect(int *n, int *con1, int *con2, int *max, int *fre);
bool increase(int *n);

int main(void){
	using namespace std;
	
	char c[5]; // 카드 색깔 
	int n[5]; // 카드 숫자 
	int score=0; // 점수 
	int fre=0; // 2개 이상의 연속된 수가 나온 회수 0~2 사이 값 도출  
	int max=0; // 최대 연속 횟수   
	int con1=0 ,con2=0; // 연속된 수열의 끝 
	
	for(int i=0;i<5;i++){
		cin >> c[i] >> n[i];
	}
	
	sort(c,c+5);
	sort(n,n+5);

	connect(n,&con1,&con2,&max, &fre);
	
	if(c[0]==c[4]&&increase(n)==true){
		score=900+n[4];
	}
	else if(max==4){
		score=800+con1;
	}
	else if(max==3&&fre==2){
		if(n[0]==n[2]) score=700+n[2]*10+n[4];
		else score=700+n[2]*10+n[0];
	}
	else if(c[0]==c[4]){
		score=600+n[4];
	}
	else if(increase(n)==true){
		score=500+n[4];
	}
	else if(max==3){
		score=400+con1;
	}
	else if(max==2&&fre==2){
		score=300+con2*10+con1;
	}
	else if(max==2){
		score=200+con1;
	}
	else{
		score=100+n[4];
	}
	
	cout<<score;
	return 0;
}

void connect(int *n, int *con1, int *con2, int *max, int *fre){
	int a=1;
	int check=0;
	for(int i=0;i<4;i++){
		if(n[i]==n[i+1]){
			a++;
			if(a>=2){
				if(check==0){
					*con1=n[i];
					*fre=1;
				}
				else{
					*con2=n[i];
					*fre=2;
				}
			}
			if(*max<a) *max=a;
		}
		else if(*con1!=0){
			check=1;
			a=1;
		}
	}	
}

bool increase(int *n){
	for(int i=0;i<4;i++){
		if(n[i]+1!=n[i+1]) return false;
	}
	return true;
}

