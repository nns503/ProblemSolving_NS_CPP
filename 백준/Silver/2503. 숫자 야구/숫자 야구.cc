#include <bits/stdc++.h>

using namespace std;

bool solve(int num, vector<vector<int>> &arr){
    for(auto cur : arr){
        int s = 0;
        int b = 0;

        vector<int> number;
        vector<int> target;
        int temp = cur[0];
        int tempNum = num;
        
        while(temp > 0){
            number.push_back(tempNum % 10);
            tempNum /= 10;
            target.push_back(temp % 10);
            temp /= 10;
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(number[i] == target[j]){
                    if(i == j) s++;
                    else b++;
                    break;
                }

            }
        }

        if(s != cur[1]) return false;
        if(b != cur[2]) return false;
    }

    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(3, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(j == i) continue;
            for(int k=1; k<=9; k++){
                if(k == i || k == j) continue;
                int num = i * 100 + j * 10 + k;
                if(solve(num, arr)) answer++;
            }
        }
    }

    cout << answer;

    return 0;
}