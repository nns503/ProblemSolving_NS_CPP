#include <bits/stdc++.h>

using namespace std;

int dp[21][21][21];

int solve(int a, int b, int c){
    if(dp[a][b][c] != -1) return dp[a][b][c];

    if(a < b && b < c){
        return dp[a][b][c] = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
    }
    return dp[a][b][c] = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<=20; i++){
        for(int j=0; j<=20; j++){
            for(int k=0; k<=20; k++){
                if(i <= 0 || j <= 0 || k <= 0) dp[i][j][k] = 1;
                else dp[i][j][k] = -1;
            }
        }
    }
    while(true){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == - 1 && b == -1 && c == -1) break;

        int answer = 0;
        if(a <= 0 || b <= 0 || c <= 0) answer = 1;
        else if(a > 20 || b > 20 || c > 20) answer = solve(20, 20, 20);
        else answer = solve(a, b, c);

        cout << "w(" << a << ", " << b << ", " << c << ") = " << answer << '\n';
    }
    return 0;
}