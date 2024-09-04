#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;

    cin >> str;

    string mx, mn;

    int mncnt = 0;
    int temp = 0;

    for(auto cur : str){
        if(cur == 'M') {
            mncnt++;
            temp++;
        }
        else if(cur == 'K'){
            string t = "5";
            while(temp--){
                t.push_back('0');
            }
            mx.append(t);
            temp = 0;


            if(mncnt >= 1){
                string mint = "1";
                mncnt--;
                while(mncnt--){
                    mint.push_back('0');
                }
                mn.append(mint);
                mncnt = 0;
            }
            mn.push_back('5');
        }
    }

    while(temp > 0){
        string t;
        while(temp--){
            t.push_back('1');
        }
        mx.append(t);
    }

    if(mncnt >= 1){
    string mint = "1";
    mncnt--;
    while(mncnt--){
        mint.push_back('0');
    }
    mn.append(mint);
    mncnt = 0;
}   

    cout << mx << '\n' << mn;
    return 0;
}