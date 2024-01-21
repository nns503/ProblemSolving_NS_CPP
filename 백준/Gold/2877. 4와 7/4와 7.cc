#include <bits/stdc++.h>

using namespace std;

int k;
string answer;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    while(k>0){
        k--;
        if(k%2){
            answer.push_back('7');
        }
        else answer.push_back('4');
        k /= 2;
    }

    reverse(answer.begin(), answer.end());
    
    cout << answer;

    return 0;
}
