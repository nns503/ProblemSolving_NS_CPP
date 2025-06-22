import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    public static void solution() throws IOException {
        StringTokenizer str1 = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(str1.nextToken());
        int d = Integer.parseInt(str1.nextToken());
        ArrayList<int[]> arr[] = new ArrayList[10001];
        for (int i = 0; i < 10001; i++) {
            arr[i] = new ArrayList<>();
        }
        for(int i=0; i<n; i++){
			StringTokenizer str2 = new StringTokenizer(br.readLine());
			int st = Integer.parseInt(str2.nextToken());
			int en = Integer.parseInt(str2.nextToken());
			int len = Integer.parseInt(str2.nextToken());
            arr[en].add(new int[] {st, len});
        }

        int dp[] = new int[d+1];
        dp[0] = 0;
        for(int i=1; i<=d; i++){
            dp[i] = dp[i-1] + 1;
            for(var nxt : arr[i]){
                dp[i] = Math.min(dp[i], dp[nxt[0]] + nxt[1]);
            }
        }

        bw.write(String.valueOf(dp[d]));
    }

    public static void main(String[] args) throws IOException {
        solution();
        bw.flush();
        bw.close();
        br.close();
    }
}