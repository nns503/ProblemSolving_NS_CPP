#include <bits/stdc++.h>

using namespace std;
multiset<string> ms1;
multiset<string> ms2;
int sum, same;
int solution(string str1, string str2) {
    int answer = 0;
    for(int i=0; i<str1.size(); i++){
        str1[i] = toupper(str1[i]);
    }
    for(int i=0; i<str2.size(); i++){
        str2[i] = toupper(str2[i]);
    }
    
    for(int i=0; i<str1.size()-1; i++){
        string temp;
        if(str1[i] < 'A' || str1[i] > 'Z') continue;
        if(str1[i+1] < 'A' || str1[i+1] > 'Z') continue;
        temp.push_back(str1[i]);
        temp.push_back(str1[i+1]);
        ms1.insert(temp);
    }
    
    for(int i=0; i<str2.size()-1; i++){
        string temp;
        if(str2[i] < 'A' || str2[i] > 'Z') continue;
        if(str2[i+1] < 'A' || str2[i+1] > 'Z') continue;
        temp.push_back(str2[i]);
        temp.push_back(str2[i+1]);
        ms2.insert(temp);
    }
    
    for(auto it : ms1){
        auto a = ms2.find(it);
        sum++;
        if(a != ms2.end()){
            same++;
            ms2.erase(a);
        }
    }
    sum += ms2.size();
    cout << same << ' ' << sum << '\n';
    if(sum == 0) return 65536;
    double z = same * 65536 / sum;

    return (int)z;
}