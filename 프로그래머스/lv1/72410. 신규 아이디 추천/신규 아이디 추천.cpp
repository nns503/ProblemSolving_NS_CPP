#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0; i<new_id.size(); i++){
        new_id[i] = tolower(new_id[i]);
    }
    
    for(int i=0; i<new_id.size(); i++){
        if(!((new_id[i] >= 'a' && new_id[i] <= 'z')||
           (new_id[i] >= '0' && new_id[i] <= '9')||
           new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')){
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
    
    for(int i=1; i<new_id.size(); i++){
        if(new_id[i] == '.' && new_id[i-1] == '.'){
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
    
    if(new_id[0] == '.') new_id.erase(new_id.begin());
    if(new_id.back() == '.') new_id.erase(new_id.end()-1);
    
    if(new_id.size() == 0) new_id += "a";
    
    if(new_id.size() >= 16){
        new_id.erase(new_id.begin()+15, new_id.end());
    }
    if(new_id.back() == '.') new_id.erase(new_id.end()-1);
    
    while(new_id.size()<3){
        new_id += new_id.back();
    }
    return new_id;
}