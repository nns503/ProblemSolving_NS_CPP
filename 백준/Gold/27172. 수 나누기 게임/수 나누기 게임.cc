#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> card(n);
    map<int, int> score;

    for(int i=0; i<n; i++){
        cin >> card[i];
        score[card[i]] = 0;
    }

    for(auto cur : card){
        for(int i=1; i*i<=cur; i++){
            if(cur % i == 0){
                if(score.find(i) != score.end()){
                    score[i]++;
                    score[cur]--;
                }
                if((i != cur/i) && score.find(cur / i) != score.end()){
                    score[cur / i]++;
                    score[cur]--;
                }
            }
        }
    }

    for(auto cur : card){
        cout << score[cur] << ' ';
    }
    return 0;
}