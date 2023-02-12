#include <iostream>

using namespace std;

int n,m;
int number[9];

void dfs(int depth, int cnt){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout << number[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=cnt;i<=n;i++){
        number[depth] = i;
        dfs(depth+1, i);
    }
}

int main(void){
    cin >> n >> m;
    dfs(0,1);
    return 0;
}