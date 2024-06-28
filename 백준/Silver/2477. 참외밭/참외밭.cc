    #include <bits/stdc++.h>

    using namespace std;

    int main(void){
        ios::sync_with_stdio(0);
        cin.tie(0);

        int k;

        cin >> k;
        
        int N = 6;
        int ans = 0;
        int d, len;

        vector<int> y;
        vector<int> x;
        int maxX = 0, indexX;
        int maxY = 0, indexY;
        bool chk = false;
        while(N--){
            cin >> d >> len;
            if(d == 1 || d == 2){
                x.push_back(len);
                if(maxX < len){
                    maxX = len;
                    indexX = x.size() - 1;
                } 
            }
            else{
                if(N == 5) chk = true;
                y.push_back(len);
                if(maxY < len){
                    maxY = len;
                    indexY = y.size() - 1;
                }
            }
        }
        if(chk){
            swap(y[0], y[1]);
            swap(y[1], y[2]);
        }
        if(indexX == 0){
            ans += x[1] * y[0];
            ans += x[2] * y[2];
        }
        else if(indexX == 1){
            ans += x[0] * y[0];
            ans += x[2] * y[1];
        }
        else{
            ans += x[0] * y[2];
            ans += x[1] * y[1];
        }
        cout << ans * k;
        return 0;
    }