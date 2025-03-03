#include <bits/stdc++.h>

using namespace std;

int num;

bool matchCard(set<int> &cards){
    for(auto &cur : cards){
        if(cards.find(num - cur) == cards.end()) continue;
        cards.erase(cur);
        cards.erase(num - cur);
        return true;
    }
    return false;
}

bool matchMyCardAndBuyCard(set<int> &myCards, set<int> &buyCards){
    for(auto &cur : myCards){
        if(buyCards.find(num - cur) == buyCards.end()) continue;
        myCards.erase(cur);
        buyCards.erase(num - cur);
        return true;
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    
    set<int> myCards;
    set<int> buyCards;
    int index = cards.size()/3;
    num = cards.size() + 1;
    
    for(int i=0; i<cards.size()/3; i++){
        myCards.insert(cards[i]);
    }
    
    while(true){
        answer++;
        if(index >= cards.size()) break;
        buyCards.insert(cards[index]);
        buyCards.insert(cards[index+1]);
        index += 2;
        if(matchCard(myCards)){
            continue;
        }
        if(coin >= 1 && matchMyCardAndBuyCard(myCards, buyCards)){
            coin--;
            continue;
        }
        if(coin >= 2 && matchCard(buyCards)){
            coin -= 2;
            continue;
        }
        break;
    }
    
    return answer;
}