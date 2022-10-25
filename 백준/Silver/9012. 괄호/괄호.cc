#include <iostream>
#include <stack>

using namespace std;

int main(){
	
	stack<char> st;
	int n;
	string a;
	int x=0,y=0;
	cin >> n;
	
	
	for(int i=0;i<n;i++){
		cin >> a;
		for(int j=0;j<a.size();j++){
			st.push(a[j]);
		}
		while(st.empty()==0){
			if(')'== st.top()) x++;
			else if('('== st.top()) x--;
			
			if(x<0){
				while(st.empty()==0){
					st.pop();
				}
			} 
			else st.pop();
		}
		
		cout << (x==0?"YES\n":"NO\n");
		
		x=0;
	}
}
