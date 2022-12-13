#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
#define MAX 40000

using namespace std;


class Deque{
	private:
		int head;
		int tail;
		int data[MAX];
	public:
		Deque();
		void push_front(int x);
		void push_back(int x);
		void pop_front();
		void pop_back();
		int size();
		int empty();
		void front();
		void back();
};

Deque::Deque(){
	head = 20000;
	tail = 20001;
}

void Deque::push_front(int x){
	data[head] = x;
	head--;
}

void Deque::push_back(int x){
	data[tail] = x;
	tail++;
	
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
void Deque::pop_front(){
	if(tail-head!=1){
		cout << data[head+1] << "\n";
		head++;
	}
	else{
		cout << "-1\n";
	}
}

void Deque::pop_back(){
	if(tail-head!=1){
		cout << data[tail-1] << "\n";
		tail--;
	}
	else{
		cout << "-1\n";
	}
}

int Deque::size(){
	return tail-head-1;
}

int Deque::empty(){
	return head+1==tail?1:0;
}

void Deque::front(){
	if(tail-head!=1){
		cout << data[head+1] << "\n";
	}
	else{
		cout << "-1\n";
	}
}
void Deque::back(){
	if(tail-head!=1){
		cout << data[tail-1] << "\n";
	}
	else{
		cout << "-1\n";
	}
}

int main(){
	Deque dq;
	int num;
	int x;
	string str;
	cin >> num;
	
	for(int i=0;i<num;i++){
		cin >> str;
		if(str=="push_front"){
			cin >> x;
			dq.push_front(x);
		}
		else if(str=="push_back"){
			cin >> x;
			dq.push_back(x);
		}
		else if(str=="pop_front"){
			dq.pop_front();
		}
		else if(str=="pop_back"){
			dq.pop_back();
		}
		else if(str=="size"){
			cout << dq.size() << "\n" ;
		}					
		else if(str=="empty"){
			cout << dq.empty() << "\n" ;
		}
		else if(str=="front"){
			dq.front();
		}
		else if(str=="back"){
			dq.back();
		}	
	}
	
	return 0;
}