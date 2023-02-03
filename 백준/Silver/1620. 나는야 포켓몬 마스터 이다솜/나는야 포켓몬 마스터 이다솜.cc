#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

map<string, int> poket;
string mon[100002];
	
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);		
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		string s;
		cin >> s;
		poket[s] = i;
		mon[i] = s;
	}  
	
	for(int i=1;i<=m;i++){
		string s;
		cin >> s;
		if(isdigit(s[0])==false) cout << poket[s] << "\n";
		else cout << mon[stoi(s)] << "\n";
	}
	
}