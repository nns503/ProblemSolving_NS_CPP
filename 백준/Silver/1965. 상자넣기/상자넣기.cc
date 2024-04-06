#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    vector<int> answer;
    answer.reserve(1000);
    cin >> n;
    cin >> a;
    answer.push_back(a);
    for(int i=1; i<n; i++){
        cin >> a;
        if(answer.back() < a) answer.push_back(a);
        else{
            int id = lower_bound(answer.begin(), answer.end(), a) - answer.begin();
            answer[id] = a;
        } 
    }
    cout << answer.size();

    return 0;
}