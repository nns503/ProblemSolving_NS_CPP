#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>

using namespace std;

struct Profile{
	char name[120];
	int age;
	int order;
};


struct compare{
	bool operator()(const Profile& p1, const Profile& p2){
		if(p1.age==p2.age){
			return p1.order < p2.order;
		}
		else return p1.age < p2.age;
	}
};

int main(void){
	using namespace std;
	
	int n;
	cin >> n;
	
	Profile p[n];
	
	for(int i=0;i<n;i++){
		cin >> p[i].age >> p[i].name;
		p[i].order = i;
	}
	
	sort(p,p+n,compare());
	
	for(int i=0;i<n;i++){
		cout << p[i].age << " " << p[i].name << "\n" ;
	}	

	
	return 0;
}

