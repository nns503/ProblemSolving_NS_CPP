#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> answer;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int a; cin >> a; answer.push_back(a);

    for(int i=1; i<n; i++){
        int cur; cin >> cur;
        if(answer.back() < cur){
            answer.push_back(cur);
        }
        else{
            int index = lower_bound(answer.begin(), answer.end(), cur) - answer.begin();
            answer[index] = cur;
        }
    }

    cout << answer.size();

    return 0;
}