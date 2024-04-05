#include <bits/stdc++.h>

using namespace std;

vector<int> num(10001);
vector<int> arr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2; i<=10000; i++){
        if(num[i]) continue;
        arr.push_back(i);
        for(int k=i+i; k<=10000; k+=i){
            num[k] = true;
        }
    }

    int T, n;
    cin >> T;

    while(T--){
        vector<int> answer(2);
        cin >> n;
        for(auto cur : arr){
            if(cur > n/2) break;
            if(num[n - cur] == false){
                answer[0] = cur;
                answer[1] = n - cur;
            }
        }

        cout << answer[0] << ' ' << answer[1] << '\n';
    }
    return 0;
}