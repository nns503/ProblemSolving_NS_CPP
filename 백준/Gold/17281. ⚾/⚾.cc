#include <bits/stdc++.h>

using namespace std;

int nextTurn(int turn){
    return (turn + 1) % 9;
}

int getScore(vector<bool> &base, int move){
    int score = 0;
    for(int i=0; i<move; i++){
        if(base[3 - i]){
            score++;
        }
    }

    return score;
}

void moveBase(vector<bool> &base, int move){
    for(int i=3; i>=0; i--){
        if(i - move < 0){
            base[i] = false;
        }
        else{
            base[i] = base[i - move];
        }
    }
}

int playBaseball(int n, vector<vector<int>> &results, vector<int> &arr){
    int score = 0;
    int turn = 0;

    for(int i=0; i<n; i++){
        vector<bool> base(4, false);
        int out = 0;
        while(out < 3){
            int result = results[i][arr[turn]];
            turn = nextTurn(turn);
            
            if(result == 0){
                out++;
            }
            else{
                base[0] = true;
                score += getScore(base, result);
                moveBase(base, result);
            }
        }
    }

    return score;
}

int solve(int n, vector<vector<int>> &results){
    int answer = 0;
    vector<int> arr(9, 0);
    for(int i=0; i<9; i++){
        arr[i] = i;
    }

    do{
        if(arr[3] != 0) continue;
        int score = playBaseball(n, results, arr);
        answer = max(score, answer);
    }while(next_permutation(arr.begin(), arr.end()));

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> results(n, vector<int>(9));
    for(auto &result : results){
        for(auto &cur : result){
            cin >> cur;
        }
    }

    cout << solve(n, results);
    return 0;
}