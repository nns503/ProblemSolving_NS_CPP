#include <bits/stdc++.h>

using namespace std;

int n, cur;
vector<int> answer;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n;

    cin >> cur;
    answer.push_back(cur);

    for(int i=1; i<n; i++){
        cin >> cur;
        if(answer.back() < cur) answer.push_back(cur);
        else{
            int index = lower_bound(answer.begin(), answer.end(), cur) - answer.begin();
            answer[index] = cur;
        }
    }

    cout << answer.size();

    return 0;
}