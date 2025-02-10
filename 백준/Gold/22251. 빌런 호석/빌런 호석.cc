#include <bits/stdc++.h>

using namespace std;

string n, x;
int k, p;
int answer = 0;

vector<vector<bool>> numbers = {
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1}, //6
    {1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}
};

int getChangedNumber(int a, int b){
    int sum = 0;
    for(int i=0; i<numbers[a].size(); i++){
        if(numbers[a][i] != numbers[b][i]) sum++;
    }

    return sum;

}

void solve(int index, int count, string number){
    if(count > p) return ;
    if(index == k){
        if(count == 0) return;
        if(stoi(number) < 1 || stoi(number) > stoi(n)) return ;
        answer++;
        return ;
    }
    int temp = number[index];
    for(int i=0; i<=9; i++){
        number[index] = '0' + i;
        solve(index+1, count + getChangedNumber(temp - '0', i), number);
        number[index] = temp;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> p >> x;
    while(x.size() != k){
        x = "0" + x;
    }
    solve(0, 0, x);

    cout << answer;
}