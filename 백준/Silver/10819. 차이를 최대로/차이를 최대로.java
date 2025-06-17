import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int answer = 0;

    public static void backTracking(int cnt, int num, int sum, List<Integer> arr, List<Boolean> vis) {
        if (cnt == arr.size() - 1) {
            answer = Math.max(sum, answer);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (vis.get(i))
                continue;
            vis.set(i, true);
            backTracking(cnt + 1, i, sum + Math.abs(arr.get(num) - arr.get(i)), arr, vis);
            vis.set(i, false);
        }

        return;
    }

    public static void solution() throws IOException {
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Integer> arr = new ArrayList<>();
        while (st.hasMoreTokens()){
            arr.add(Integer.parseInt(st.nextToken()));
        }
        List<Boolean> vis = new ArrayList<>();
        for (int i = 0; i < arr.size(); i++) {
            vis.add(false);
        }
        for(int i=0; i<arr.size(); i++){
            vis.set(i, true);
            backTracking(0, i, 0, arr, vis);
            vis.set(i, false);
        }

        bw.write(String.valueOf(answer));
    }

    public static void main(String[] args) throws IOException {
        solution();
        bw.flush();
        bw.close();
        br.close();
    }
}