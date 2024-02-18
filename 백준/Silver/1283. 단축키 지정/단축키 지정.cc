#include <bits/stdc++.h>

using namespace std;

int n;
string str;
bool chk[31];


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "abcde";
    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++){
        getline(cin, str);
        vector<string> arr;
        int st = 0;
        for(int en=0; en<str.size(); en++){
            if(str[en] == ' '){
                arr.push_back(str.substr(st, en - st));
                st = en + 1;
            }
        }
        arr.push_back(str.substr(st));
        
        bool t = false;

        for(int k=0; k<arr.size(); k++){
            char low = tolower(arr[k][0]);
            if(chk[low - 'a']) continue;
            chk[low - 'a'] = true;
            string temp;
            temp += '['; temp += arr[k][0]; temp += ']';
            arr[k].replace(0, 1, temp);
            t = true;
            break;
        }

        int k = 0;
        while(!t && k < arr.size()){
            for(int p=1; p<arr[k].size(); p++){
                char low = tolower(arr[k][p]);
                if(chk[low - 'a']) continue;
                chk[low - 'a'] = true;
                string temp;
                temp += '['; temp += arr[k][p]; temp += ']';
                arr[k].replace(p, 1, temp); 
                t = true;
                break;
            }
            k++;
        }
        for(auto a : arr){
            cout << a << ' ';
        }
        cout << '\n';
    }

    return 0;
}