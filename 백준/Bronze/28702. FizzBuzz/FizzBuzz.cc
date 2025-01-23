#include <bits/stdc++.h>

using namespace std;

string getWord(long num){
    if(num % 5 == 0 && num % 3 == 0){
        return "FizzBuzz";
    }
    if(num % 3 == 0){
        return "Fizz";
    }
    if(num % 5 == 0){
        return "Buzz";
    }

    return to_string(num);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    for(int i=3; i>=1; i--){
        cin >> str;
        if(str != "Fizz" && str != "Buzz" && str != "FizzBuzz"){
            cout << getWord(stoi(str) + i);
            break;
        }
    }
    
    return 0;
}