#include <bits/stdc++.h>

using namespace std;

int n, m;
string board[51];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    int num = 1;
    int answer = 1;
    for(int y=0; y<n; y++){
        cin >> board[y];
    }

    while(num < min(n, m)){
        bool check = false;
        for(int y=0; y<n-num; y++){
            if(check) break;
            for(int x=0; x<m-num; x++){
                if(board[y][x] == board[y+num][x+num] 
                && board[y][x] == board[y+num][x]
                && board[y][x] == board[y][x+num])
                {
                    check = true;
                    break;
                }
            }
        }

        if(check) answer = num+1;  
        num++;
    }
    cout << pow(answer, 2);
    return 0;
}