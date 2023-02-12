#include <iostream>

using namespace std;

int n,m;
int number[9];

void DFS(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout << number[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        number[depth] = i;
        DFS(depth+1);
    }
}

int main(void){
    cin >> n >> m;
    DFS(0);
    return 0;
}