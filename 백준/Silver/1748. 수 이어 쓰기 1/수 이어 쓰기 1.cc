#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long answer = 0;

    long long d = 1;
    long long st = 1;
    long long en = 9;

    while(n >= st){
        if(n > en){
            answer = answer + (en - st + 1) * d;
        }
        else{
            answer = answer + (n - st + 1) * d;
        }

        st *= 10;
        en = en * 10 + 9;
        d++;
    }

    cout << answer;
}