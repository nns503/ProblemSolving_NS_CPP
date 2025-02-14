#include <bits/stdc++.h>

using namespace std;

vector<string> days = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}; 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;

    int a = 1, b = 1;

    int i = 0;

    while(a != x || b != y){
        i++;
        b++;
        if(a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12){
            if(b > 31){
                b = 1;
                a++;
            }
        }
        else if(a == 2){
            if(b > 28){
                b = 1;
                a++;
            }
        }
        else{
            if(b > 30){
                b = 1;
                a++;
            }
        }
    }
    cout << days[i % 7];
    return 0;
}
