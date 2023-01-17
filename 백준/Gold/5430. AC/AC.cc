#include <iostream>
#include <string>
#include <deque>

using namespace std;


int main(void){
	int n;
	cin >> n;
	for(int t=0;t<n;t++){
		deque<int> dq;
		string AC; // AC 함수 입력 받기 
		cin >> AC;
		bool reverse = false;  	
		bool breaking = false;
		int n; // 수 
		string arr; // 배열 
		cin >> n;
		cin >> arr; 
		
		int temp = 0;
		int k = 1;
		for(int i=1;i<arr.size();i++){
			if((arr[i]==','||arr[i]==']')&&temp!=0) {
				dq.push_back(temp);
				temp = 0;
			}
			else {
				temp*=10;
				temp+=(arr[i]-'0');
			}
		}
		
		
		for(int i=0;i<AC.size();i++){
			if(AC[i]=='R'){
				if(!reverse) reverse = true;
				else if(reverse) reverse = false;
			}
			else if(AC[i]=='D'){
				if(dq.empty()){
					cout << "error\n";
					breaking = true;
					break;
				}
				if(!reverse){
					dq.pop_front();
				}
				else if(reverse){
					dq.pop_back();
				}
			}
		}
		if(breaking==true) continue;
		
		cout << "[";
		while(dq.size()>1){
			if(!reverse) { 
				cout << dq.front() << ',';
				dq.pop_front();
			}
			else if(reverse){
				cout << dq.back() << ',';
				dq.pop_back();
			}
		}
		
		if(!reverse&&!dq.empty()) { 
			cout << dq.front();
			dq.pop_front();
		}
		else if(reverse&&!dq.empty()){
			cout << dq.back();
			dq.pop_back();
		}		
		cout << "]\n" ;
		
	}
}