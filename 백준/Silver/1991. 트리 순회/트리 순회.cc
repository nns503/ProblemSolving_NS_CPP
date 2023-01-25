	#include <iostream>
	#include <algorithm>
	using namespace std;
	
	char node[27][2];

	void Preorder(char a){
		cout << a;
		for(int i=0;i<=1;i++){
			if(node[a-'A'][i]!='.'){
				Preorder(node[a-'A'][i]);
			}
		}
	}
	
	void Inorder(char a){
		if(node[a-'A'][0]!='.'){
			Inorder(node[a-'A'][0]);
		}
		cout << a;
		if(node[a-'A'][1]!='.'){
			Inorder(node[a-'A'][1]);
		}
	}
	
	
	void Postorder(char a){
		if(node[a-'A'][0]!='.'){
			Postorder(node[a-'A'][0]);
		}
		if(node[a-'A'][1]!='.'){
			Postorder(node[a-'A'][1]);
		}
		cout << a;	
	}
	

	
	int main(void){
		int n;
		cin >> n;
		
		node[0][0] = 'A';
		for(int i=1;i<=n;i++){
			char c;
			cin >> c;
			for(int j=0;j<=1;j++){
				cin >> node[c-'A'][j];
			}
		
		}
		
		Preorder('A');
		cout << "\n";
		Inorder('A');
		cout << "\n";
		Postorder('A');
		return 0;
}
	
