#include <bits/stdc++.h>

using namespace std;

int n1[5] = {1, 2, 3, 4, 5};
int n2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int n3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int h[3];
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == n1[i%5]) h[0]++;
        if(answers[i] == n2[i%8]) h[1]++;
        if(answers[i] == n3[i%10]) h[2]++;
    }
    int mx = *max_element(h, h+3);
    if(mx == h[0]) answer.push_back(1);
    if(mx == h[1]) answer.push_back(2);
    if(mx == h[2]) answer.push_back(3);
    return answer;
}