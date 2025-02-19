#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101][3];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> arr(n+1, vector<int>(3, 0));

    for(int i=0; i<n; i++){
        int num; string str;
        cin >> num >> str;
        int minute = stoi(str.substr(0, 2));
        int second = stoi(str.substr(3, 2));
        arr[i][0] = minute;
        arr[i][1] = second; 
        arr[i][2] = num;
    }
    arr[n][0] = 48;
    arr[n][1] = 0;
    arr[n][2] = 0;

    sort(arr.begin(), arr.end());

    vector<int> m(3, 0);
    vector<int> s(3, 0);
    vector<int> score(3, 0);

    score[arr[0][2]]++;

    for(int i=1; i<=n; i++){
        int minute = arr[i][0] - arr[i-1][0];
        int second = arr[i][1] - arr[i-1][1];
        int num = arr[i][2];
        
        if(second < 0){
            minute--;
            second += 60;
        }

        if(score[1] > score[2]){
            m[1] += minute;
            s[1] += second;    
        }
        else if(score[1] < score[2]){
            m[2] += minute;
            s[2] += second;
        }
        score[num]++;
    }


    for(int i=1; i<=2; i++){
        m[i] += (s[i] / 60);
        s[i] %= 60;
        string a = to_string(m[i]);
        string b = to_string(s[i]);
        if(a.size() < 2){
            a = "0" + a;
        }
        if(b.size() < 2){
            b = "0" + b;
        }
        cout << a << ':' << b << '\n';
    }
    return 0;
}