#include <bits/stdc++.h>

using namespace std;

int n;
int cnt;
string num;
string arr[1000001];

void func(int cip, int prv){
    
    if(cip == -1){
        cnt++;
        arr[cnt] = num;
        return;
    }
    for(int i=cip; i<=9; i++){
        if(prv <= i) continue;
        num.push_back((i + '0'));
        func(cip-1, i);
        num.pop_back();
    }
    if(prv == 10 && cip <= 8) func(cip + 1, 10);
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(arr, arr+1000001, "-1");

    cin >> n;

    func(0, 10);

    cout << arr[n];

    return 0;
}

