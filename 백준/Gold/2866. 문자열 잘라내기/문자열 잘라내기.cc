#include <bits/stdc++.h>

using namespace std;

int r, c;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    vector<string> arr(r);
    for(int i=0; i<r; i++){
        cin >> arr[i];
    }

    int answer = 0;
    vector<string> str;
    for(int x=0; x<c; x++){
        string temp;
        for(int y=0; y<r; y++){
            temp += arr[y][x];
        }
        str.push_back(temp);
    }
    
    for(int i=1; i<c; i++){
        set<string> s;
        for(int j=0; j<str.size(); j++){
            s.insert(str[j].substr(i));
        }
        if(s.size() == c) answer++;
        else break;
    }

    cout << answer;
    return 0;
}