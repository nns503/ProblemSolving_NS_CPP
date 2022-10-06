#include <iostream>
#include <algorithm>
#include <string>

typedef struct Point{
	int x; // x
	int y; // y
}P;

int compare(Point p1, Point p2){
	if(p1.x==p2.x){
		return p1.y<p2.y;
	}
	
	return p1.x < p2.x;
}

int main(void){
	using namespace std;
	
	int n;
	cin >> n;
	
	P point[n];

	
	for(int i=0;i<n;i++){
		cin >> point[i].x >> point[i].y;
	}
	
	sort(point,point+n,compare);
	
	for(int i=0;i<n;i++){
		cout << point[i].x << " " << point[i].y << "\n" ;	
	}
	
	return 0;
}
