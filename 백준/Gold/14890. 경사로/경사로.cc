#include <bits/stdc++.h>

using namespace std;

int n, l, answer;
int board[101][101];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin >> board[y][x];
        }
    }

    for(int y=0; y<n; y++){
        int st = 1;
        bool es = false;
        for(int x=1; x<n; x++){
            int cur = board[y][x];
            int prv = board[y][x-1];
            if(abs(cur - prv) >= 2){
                es = true;
                break;
            }

            if(cur == prv){
                st++;
            }
            else if(cur < prv){
                for(int i=x; i<x+l; i++){
                    if(i >= n || board[y][i] != cur){
                        es = true;
                        break;
                    }
                }
                x += l-1;
                st = 0;
            }
            else if(cur > prv){
                if(st >= l) st = 1;
                else{
                    es = true;
                    break;
                }
            }

            if(es) break;
        }
        if(!es){
            answer++;
        }
    }

    for(int x=0; x<n; x++){
        int st = 1;
        bool es = false;
        for(int y=1; y<n; y++){
            int cur = board[y][x];
            int prv = board[y-1][x];
            if(abs(cur - prv) >= 2){
                es = true;
                break;
            }

            if(cur == prv){
                st++;
            }
            else if(cur < prv){
                for(int i=y; i<y+l; i++){
                    if(i >= n || board[i][x] != cur){
                        es = true;
                        break;
                    }
                }
                y += l-1;
                st = 0;
            }
            else if(cur > prv){
                if(st >= l) st = 1;
                else{
                    es = true;
                    break;
                }
            }

            if(es) break;
        }
        if(!es){
            answer++;
        }
    }

    cout << answer; 
    
    return 0;
}