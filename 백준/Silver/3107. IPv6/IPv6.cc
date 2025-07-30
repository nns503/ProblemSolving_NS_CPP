#include <bits/stdc++.h>

using namespace std;

string solve(string str){
    vector<string> words;
    int pos = 0;

    string temp;
    bool flag = false;
    for(int i=0; i<=str.size(); i++){
        if(i == str.size() || str[i] == ':'){
            if(temp.length() == 0){
                if(flag) continue;
                words.push_back("temp");
                flag = true;
            }
            else{
                string word;
                for(int k=0; k<4-temp.length(); k++){
                    word += "0";
                }
                word += temp;
                words.push_back(word);
            }
            temp = "";
        }
        else{
            temp += str[i];
        }
    }

    string answer;
    for(int i=0; i<words.size(); i++){
        if(words[i] == "temp"){
            for(int k=0; k<=8-words.size(); k++){
                answer += "0000";
                if(k != 8 - words.size()) answer += ":";
            }
        }
        else answer += words[i];
        if(i != words.size() - 1) answer += ":";
    }
    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    cout << solve(str);

    return 0;
}