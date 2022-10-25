#include <iostream>
#include <stack>

using namespace std;

int main(){
	
	stack<int> st;
	int k;
	int n;
	int sum=0;
	cin >> k;
	
	for(int i=0;i<k;i++){
		cin >> n;
		if(n==0){
			st.pop();	
		}
		else{
			st.push(n);
		}
	}
	
	while(st.empty()==0){
		sum+=st.top();
		st.pop();
	}
	cout << sum;
}