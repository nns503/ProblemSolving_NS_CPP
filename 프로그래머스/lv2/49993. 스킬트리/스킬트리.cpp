#include <bits/stdc++.h>

using namespace std;

bool alp[26];
queue<char> q;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(char c : skill){
        alp[c-'A'] = true;    
    }
    for(string st : skill_trees){
        bool chk = true;
        string s;
        for(char c : st){
            if(!alp[c-'A']) continue;
            s.push_back(c);
        }
        int index = 0;
        for(char c : s){
            if(skill[index] != c){
                chk = false;
                break;
            }
            index++;
        }
        if(chk) answer++;
    }
    return answer;
}