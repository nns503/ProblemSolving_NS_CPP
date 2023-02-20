#include <bits/stdc++.h>

using namespace std;

int L,C;
char pw[15];
char word[15];
bool chk[15];
char vowel[5] = {'a','e','i','o','u'};

void func(int len, int v, int c, int order){
	if(len==L){
		if(c<2||v<1) return;
		for(int i=0;i<L;i++) cout << pw[i];
		cout << '\n';
		return ;
	}
	int init_v = v;
	int init_c = c;
	for(int i=order;i<C;i++){
		if(chk[i]==true) continue;
		bool vc = false;
		if(find(vowel,vowel+5,word[i])!=vowel+5) v=true;
		chk[i] = true;
		pw[len] = word[i];
		if(v==true) func(len+1,v+1,c,i);
		else func(len+1,v,c+1,i);
		chk[i] = false;
		v = init_v;
		c = init_c;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> L >> C;
	
	for(int i=0;i<C;i++) cin >> word[i];
	sort(word, word+C);
	
	func(0,0,0,0);
	
	return 0;
}