#include <iostream>
#include <vector>

using namespace std;
//vector<vector<int>> v(64,vector<int>(64,0));
int v[64][64];
void makeTree(int y, int x, int size){
    int start = v[y-size][x-size]; 
    int check = true;
    for(int i=y-size;i<y;i++){
        for(int j=x-size;j<x;j++){
            if(start!=v[i][j]){
                cout << '(';
                makeTree(y-size/2,x-size/2,size/2);
                makeTree(y-size/2,x,size/2);
                makeTree(y,x-size/2,size/2);
                makeTree(y,x,size/2);
                check = false;
                cout << ')';
                break;
            }
        }
        if(check==false) break;
    }
    if(check==true) cout << start;
}

int main(void) {
    int n;
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            v[i][j] = s[j]-'0';
        }
    }
    makeTree(n,n,n);
	return 0;
}
