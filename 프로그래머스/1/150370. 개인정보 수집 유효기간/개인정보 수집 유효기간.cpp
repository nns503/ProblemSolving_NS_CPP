#include <bits/stdc++.h>

using namespace std;

int getLen(string term){
    int y = stoi(term.substr(2, 2));    
    int m = stoi(term.substr(5, 2));
    int d = stoi(term.substr(8, 2));
    
    return (y - 1) * (28 * 12) + (m-1) * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int cur = getLen(today);
    map<string, int> m;
    for(int i=0; i<terms.size(); i++){
        m[terms[i].substr(0, 1)] = stoi(terms[i].substr(2));
    }
    
    cout << cur << '\n';
    for(int i=0; i<privacies.size(); i++){
        int days = getLen(privacies[i]);
        string c = privacies[i].substr(11);
        if(cur >= days + (m[c] * 28)){
            answer.push_back(i+1);
        }
    }
    return answer;
}