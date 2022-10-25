#include <iostream>
#include <algorithm>
#define MAX_STACK_SIZE 10000

using namespace std;


class Stack{
	int last;
	int data[MAX_STACK_SIZE];
	
	public:
		Stack(){
			last=-1;
		}
	~Stack(){}	
		
	void push(){
		last++;
		cin >> data[last];
	}	
	
	int pop(){
		if(last==-1){
			return -1;
		}
		else{
			last--;
			return data[last+1];
		}
	}	
	
	int size(){
		return last+1;
	}
	
	int empty(){
		if(last==-1) return 1;
		else return 0;
	}
	
	int top(){
		if(last==-1) return -1;
		else{
			return data[last];
		}
	}	
	
};


int main(){
	
	string s;
	Stack a;
	int n;
	int i=0;
	cin >> n;
	while(i<n){
		cin >> s;
		if(s=="push"){
			a.push();
		}
		else if(s=="pop"){
			cout << a.pop() << "\n";
		}
		else if(s=="size"){
			cout << a.size() << "\n";
		}
		else if(s=="empty"){
			cout << a.empty() << "\n";
		}
		else if(s=="top"){
			cout << a.top() << "\n";
		}
		else{
		}
		i++;
	}
}