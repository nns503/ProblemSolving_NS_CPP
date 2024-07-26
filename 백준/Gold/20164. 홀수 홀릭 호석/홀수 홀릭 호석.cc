#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int getOdd(int n){
    int odd = 0;
    while(n > 0){
        if((n % 10) % 2) odd++; 
        n /= 10;
    }
    return odd;
}

pair<int, int> solve(int n){  
    int sum = getOdd(n);

    if(n >=0 && n <= 9){
        return {sum, sum};
    }
    
    if(n >= 10 && n <= 99){
        int temp = n / 10 + n % 10; 
        auto g = solve(temp);
        return {sum + g.A, sum + g.B};
    }

    int mx = -1;
    int mn = 0x3f3f3f3f;

    string str = to_string(n);
    for(int i=1; i<str.size()-1; i++){
        for(int j=i+1; j<str.size(); j++){
                auto p1 = stoi(str.substr(0, i));
                auto p2 = stoi(str.substr(i, j-i));
                auto p3 = stoi(str.substr(j, str.size() - 1));
                int num = p1 + p2 + p3;
                auto temp = solve(num);
                mx = max(mx, temp.A + sum);
                mn = min(mn, temp.B + sum);
        }
    }
    return {mx, mn};
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    auto answer = solve(n);
    cout << answer.B << ' ' << answer.A;
    return 0;
}