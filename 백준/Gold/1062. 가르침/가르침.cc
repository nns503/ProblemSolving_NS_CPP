#include <bits/stdc++.h>

using namespace std;

int n, k;
int answer;
bool num[27];
vector<string> str;
vector<int> arr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    if(k < 5){
        cout << 0;
        return 0;
    }

    for(int i=0; i<n; i++){
        string s; cin >> s;
        str.push_back(s);
    }

    for(int i=0; i<21; i++){
        if(i < k - 5){
            arr.push_back(0);
        }
        else arr.push_back(1);
    }

    do{
        int count = 0;
        int p = 0;
        fill(num, num+27, false);
        for(int i=0; i<26; i++){
            if(i == ('a' - 'a') || i == ('n' - 'a') || i == ('t' - 'a') || i == ('i' - 'a') || i == ('c' - 'a')){
                num[i] = true;  
                continue;
            }            
            if(!arr[p]) num[i] = true;
            p++;
        }
        for(int i=0; i<n; i++){
            string cur = str[i];
            bool chk = true;
            for(int j=4; j<str[i].size()-4; j++){
                if(!num[str[i][j] - 'a']){
                    chk = false;
                    break;
                }
            }
            if(chk) count++;
        }
        answer = max(count, answer);
    }while(next_permutation(arr.begin(), arr.end()));
    cout << answer;
}