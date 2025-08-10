#include <bits/stdc++.h>

using namespace std;

int n, d, k, c;

int solve(vector<int> &arr){
    int answer = -1; // 현재 최대로 먹을 수 있는 개수
    vector<int> chobob(d+1, 0); // 현재 먹을 수 있는 초밥 개수를 인덱스 기준으로 기록, 여기서 d가 쓰이네~
    chobob[c] = 0x3f3f3f3f; // 쿠폰은 무조건 먹으니까 그냥 무한개 넣어버림
    int cnt = 1; // 현재 먹을 수 있는 종류 
    int st = 0; // 현재 먹는 초밥의 시작 번호

    // 이제 초밥을 먹어보자 n+k 개를 먹는 이유는 회전초밥이므로 맨 마지막 초밥과 처음 초밥이 이어져야하기 때문
    // st % n 하면 마지막 초밥 + 1 하면 0번으로 갑니다. 음수가 없어서 (st + n) % n 안해도 됨
    for(int i=0; i<n+k; i++){
        if(i - st + 1 > k){ // 이제 k개 초과해서 먹는다면 처음 초밥부터 한개씩 빼야함. -> 슬라이싱 윈도우
            int prv = arr[st % n];
            chobob[prv]--; 
            if(chobob[prv] == 0){ // 0개면 이제 집계한 종류에서 -1 
                cnt--;
            }
            st++; // st 인덱스는 마지막에 올려주세요. 처음에 올리는 실수를 자주하는데!
        }

        // 이제 다음 초밥을 먹어봅시다.
        int number = arr[i % n];
        chobob[number]++; // 

        // 1이라면 지금 먹는 초밥 중 새로운 종류이기 때문에 cnt 추가.
        if(chobob[number] == 1){
            cnt++;
        }

        // 갱신
        answer = max(answer, cnt);
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    vector<int> arr(n);
    for(auto &cur : arr) cin >> cur;

    cout << solve(arr);

    return 0;
}