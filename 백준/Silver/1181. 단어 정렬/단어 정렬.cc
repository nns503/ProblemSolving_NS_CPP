#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>
#include <climits>

using namespace std;

bool compare(string s1, string s2){
	if(s1.length()==s2.length()){
		return s1 < s2;
	}
	return s1.length() < s2.length();
}

int main(void){
	int n;
	cin >> n;
	string word[n];

	for(int i=0;i<n;i++){
		cin >> word[i];
	}
	
	sort(word,word+n,compare);
	
	cout << word[0] << "\n";
	
	for(int i=1;i<n;i++){
		if(word[i-1]==word[i]) continue;
		cout << word[i] << "\n";
	}
	return 0;
}

