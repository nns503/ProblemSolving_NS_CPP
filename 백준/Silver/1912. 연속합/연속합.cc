#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,sum;
int number[100001];
int dp[100001];

int main(void){
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> number[i];
    }

    dp[0] = number[0];
    sum = dp[0];

    for(int i=1;i<n;i++){
        if(number[i]>dp[i-1]+number[i]){
            dp[i] = number[i];
        }
        else{
            dp[i] = dp[i-1]+number[i];
        }
        sum = max(dp[i],sum);
    }

    cout << sum;
    return 0;
}
