#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101];
bool ch[101][101];
int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void flood(int water){
    int stack = 0;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            if(map[y][x]<=water){
                ch[y][x] = true;
            }
        }
    }
}

void DFS(int y, int x){
    ch[y][x] = true;
    for(int i=0;i<4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx>=1&&ty>=1&&tx<=n&&ty<=n&&ch[ty][tx]==false){
            DFS(ty,tx);
        }
    }
}


int checkingMap(int rain){
    int safety = 0;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            if(ch[y][x]==false){
                DFS(y,x);
                safety++;

            }
        }
    }
    return safety; 
}


int main(void){
    int field=1;
    int maxrain=1;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
            maxrain = max(map[i][j],maxrain);
        }
    }
    for(int i=1;i<maxrain;i++){
        fill(&ch[0][0],&ch[100][101],false);
        flood(i);
        int safety = checkingMap(i);
        field = max(safety,field);
    }

    cout << field;
}