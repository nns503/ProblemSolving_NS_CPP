#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
#define MAX 10050

using namespace std;


class Queue{
	private:
		int head;
		int tail;
		int data[MAX];
	public:
		Queue();
		void push(int x);
		void pop();
		int size();
		int empty();
		int front();
		int back();
};

Queue::Queue(){
	head = 0;
	tail = 0;
}

void Queue::push(int x){
	data[head] = x;
	head++;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
void Queue::pop(){
	if(head!=tail){
		cout << data[tail] << "\n";
		tail++;
	}
	else{
		cout << "-1\n";
	}
}

int Queue::size(){
	return head-tail;
}

int Queue::empty(){
	return head==tail?1:0;
}

int Queue::front(){
	if(head!=tail){
		return data[tail];
	}
	else{
		return -1;
	}
}

int Queue::back(){
	if(head!=tail){
		return data[head-1];
	}
	else{
		return -1;
	}
}


int main(){
	Queue qe;
	int num;
	int x;
	string str;
	cin >> num;
	
	for(int i=0;i<num;i++){
		cin >> str;
		if(str=="push"){
			cin >> x;
			qe.push(x);
		}
		else if(str=="pop"){
			qe.pop();
		}
		else if(str=="size"){
			cout << qe.size() << "\n" ;
		}					
		else if(str=="empty"){
			cout << qe.empty() << "\n" ;
		}
		else if(str=="front"){
			cout << qe.front() << "\n" ;
		}
		else if(str=="back"){
			cout << qe.back() << "\n" ;
		}	
	}
	
	return 0;
}