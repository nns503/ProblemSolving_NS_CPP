#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r;
    cin >> n >> r;

    map<int, int> m;
    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>> pq;
    int num;
    for (int i = 0; i < r; i++)
    {
        cin >> num;
        m[num]++;
        if(m[num] != 1) continue;

        if(pq.size() < n){
            pq.push({m[num], i, num});
            continue;
        }

        while(true){
            int count, date, number;
            tie(count, date, number) = pq.top();
            pq.pop();
            if(count == m[number]){
                pq.push({m[num], i, num});
                m[number] = 0;
                break;
            }
            else{
                pq.push({m[number], date, number});
            }
        }
    }

    vector<int> answer;
    while(!pq.empty()){
        int count, date, number;
        tie(count, date, number) = pq.top();
        pq.pop();
        answer.push_back(number);
    }
    sort(answer.begin(), answer.end());

    for(auto cur : answer){
        cout << cur << ' ';
    }

    return 0;
}