#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){

	string s;
	int sum = 0;
	int temp = 0;
	bool minus = false;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='+'){
			if(!minus){
				sum+=temp;
			}
			else if(minus){
				sum+=(temp*-1);
			}
			temp = 0;
		}
		else if(s[i]=='-'){
			if(!minus){
				sum+=temp;
				minus=true;
			}
			else if(minus){
				sum+=(temp*-1);
			}
			temp = 0;
		}
		else{
			temp*=10;
			temp+=(s[i]-'0');
		}
		
	}
	if(!minus){
		sum+=temp;
	}
	else if(minus){
		sum+=(temp*-1);
	}		
	cout << sum;
	return 0;
}