#include <bits/stdc++.h>

using namespace std;

int n;

int solve(vector<vector<int>> &board, int n){
    if(n == 1) return board[0][0];

    vector<vector<int>> mat(n/2, vector<int>(n/2));

    for(int y=0; y<n; y+=2){
        for(int x=0; x<n; x+=2){
            vector<int> arr(4);
            arr[0] = board[y][x];
            arr[1] = board[y+1][x];
            arr[2] = board[y][x+1];
            arr[3] = board[y+1][x+1];
            sort(arr.begin(), arr.end());
            mat[y/2][x/2] = arr[2];
        }
    }

    return solve(mat, n/2);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++) cin >> board[y][x];
    }

    cout << solve(board, n);
    return 0;
}