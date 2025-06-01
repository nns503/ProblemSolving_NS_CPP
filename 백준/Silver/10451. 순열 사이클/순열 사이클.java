import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static void dfs(int cur, int[] adj, boolean[] vis){
        int nxt = adj[cur];
        if(vis[nxt]) return;
        vis[nxt] = true;
        dfs(nxt, adj, vis);
    }

    public static void solution(int n, int[] arr) throws IOException {
        int count = 0;
        int[] adj = new int[n+1];

        for(int i=0; i<n; i++){
            adj[i+1] = arr[i];
        }
        boolean[] vis = new boolean[n+1];
        for(int i=1; i<=n; i++){
            if(vis[i]) continue;
            vis[i] = true;
            count++;
            dfs(i, adj, vis);
        }
        bw.write(String.valueOf(count) + '\n');
    }

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(br.readLine());
        
        while(T-- > 0){
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            solution(n, arr);
        }
        bw.flush();
        bw.close();
        br.close();
    }
}