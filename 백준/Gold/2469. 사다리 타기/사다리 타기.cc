#include <bits/stdc++.h>

using namespace std;

int k, n;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    vector<string> board(n+2);
    vector<vector<char>> arr(n+2, vector<char>(k));

    for(int i=0; i<k; i++){
        arr[0][i] = 'A' + i;
        cin >> arr[n+1][i];
    }

    for(int i=1; i<=n; i++) cin >> board[i];

    int p = 0;

    for(int i=1; i<=n; i++){
        string str = board[i];
        if(str[0] == '?'){
            p = i;
            break;
        }
        
        if(str[0] == '*') arr[i][0] = arr[i-1][0];
        else arr[i][1] = arr[i-1][0];

        for(int j=1; j<k-1; j++){
            if(str[j-1] == '-'){
                arr[i][j-1] = arr[i-1][j];
            }
            else if(str[j] == '-'){
                arr[i][j+1] = arr[i-1][j];
            }
            else{
                arr[i][j] = arr[i-1][j];
            }
        }

        if(str[k-2] == '*') arr[i][k-1] = arr[i-1][k-1];
        else arr[i][k-2] = arr[i-1][k-1];
    }


    for(int i=n; i>=p+1; i--){
        string str = board[i];
        
        if(str[0] == '*') arr[i][0] = arr[i+1][0];
        else arr[i][1] = arr[i+1][0];

        for(int j=1; j<k-1; j++){
            if(str[j-1] == '-'){
                arr[i][j-1] = arr[i+1][j];
            }
            else if(str[j] == '-'){
                arr[i][j+1] = arr[i+1][j];
            }
            else{
                arr[i][j] = arr[i+1][j];
            }
        }

        if(str[k-2] == '*') arr[i][k-1] = arr[i+1][k-1];
        else arr[i][k-2] = arr[i+1][k-1];
    }

    string answer;
    string temp;
    for(int i=0; i<k-1; i++){
        temp += 'x';
    }
    if(arr[p-1][0] == arr[p+1][0]) answer += '*';
    else if(arr[p-1][1] == arr[p+1][0]) answer += '-';
    else{
        cout << temp;
        return 0;
    }

    for(int i=1; i<k-1; i++){
        if(arr[p-1][i] == arr[p+1][i]) answer += '*';
        else if(arr[p-1][i-1] == arr[p+1][i]){
            answer += '*';
            
        }
        else if(arr[p-1][i+1] == arr[p+1][i]){
            answer += '-';
        }
        else{
            cout << temp;
            return 0;
        }
    }


    cout << answer;
    return 0;
}