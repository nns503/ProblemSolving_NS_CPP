#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int maxHealth = health;
    auto end = attacks.back()[0];
    int cnt = 0;
    int k = 0;
    for(int i=1; i<=end; i++){
        auto atk = attacks[k];
        if(atk[0] == i){
            cnt = 0;
            health -= atk[1];
            k++;
        }
        else{
            cnt++;
            health += bandage[1];
            if(cnt == bandage[0]){
                health += bandage[2];
                cnt = 0;
            }
        }
        if(maxHealth < health) health = maxHealth;
        if(health <= 0) return -1;
    }
    
    answer = health;
    return answer;
}