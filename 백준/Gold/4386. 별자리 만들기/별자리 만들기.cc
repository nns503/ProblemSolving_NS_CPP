    #include <bits/stdc++.h>
    #define X first
    #define Y second

    using namespace std;

    int n;
    double a, b;
    vector<int> p(101, -1);
    vector<pair<double, double>> point;
    vector<tuple<double, int, int>> e;

    double getDistance(pair<int, int> p1, pair<int, int> p2){
        return sqrt(pow(p1.Y - p2.Y, 2) + pow(p1.X - p2.X, 2));
    }

    int find(int x){
        if(p[x] < 0) return x;
        else return p[x] = find(p[x]);
    }

    bool isSameUnion(int u, int v){
        u = find(u); 
        v = find(v);
        if(u == v) return true;
        if(p[u] == p[v]) p[u]--;
        if(p[u] < p[v])  p[v] = u;
        else p[u] = v;
        return false;  
    }

    int main(void){
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            point.push_back({a, b});
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                e.push_back(make_tuple(getDistance(point[i], point[j]), i, j));
            }
        }

        sort(e.begin(), e.end());

        double answer = 0;
        int cnt = 0;
        for(auto cur : e){
            int u, v;
            double cost;
            tie(cost, u, v) = cur;
            if(isSameUnion(u, v)) continue;
            answer += cost;
            cnt++;
            if(cnt == n-1) break;
        }

        cout << round(answer * 100) / 100; 

        return 0;

    }



