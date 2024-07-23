#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        vector<int> goal(201, 0);
        vector<int> score[201];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            goal[arr[i]]++;
        }

        int num = 1;
        for(int i=0; i<n; i++){
            int cur = arr[i];
            if(goal[cur] < 6) continue;
            score[cur].push_back(num++);
        }

        int answer = 0;
        int sum = 0x3f3f3f3f;
        for(int i=1; i<=200; i++){
            if(score[i].size() < 6) continue;
            int temp = 0;
            for(int j=0; j<4; j++) temp += score[i][j];
            if(sum > temp){
                sum = temp;
                answer = i;
            } 
            else if(sum == temp){
                if(score[answer][4] > score[i][4]){
                    sum = temp;
                    answer = i;
                }
            }
        }

        cout << answer << '\n';
    }
    return 0;
}