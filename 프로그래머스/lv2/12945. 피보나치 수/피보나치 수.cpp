#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[100001];

ll fibo(ll n){
    if(dp[n] != 0) return dp[n];
    dp[n] = fibo(n-1) + fibo(n-2); 
    return dp[n] % 1234567;
}

int solution(int n) {
    dp[1] = 1;
    dp[2] = 1;
    return fibo(n);
}