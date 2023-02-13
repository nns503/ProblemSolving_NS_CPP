#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int m=0;
    int num[10] ={};

    cin >> n;

    while(n>0){
        num[n%10]++;
        n/=10;
    }

    num[6] += num[9];
    num[6] = num[6]/2 + num[6]%2;

    for(int i=0;i<9;i++){
        m=max(m,num[i]);
    }

    cout << m;
}