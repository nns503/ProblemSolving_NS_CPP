import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static class Data {
        String str;
        int cnt;

        public Data(String str, int cnt) {
            this.str = str;
            this.cnt = cnt;
        }
    }

    public static void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }
        Map<String, Integer> d = new HashMap<>();
        for (var cur : arr) {
            if (cur.length() < m)
                continue;
            d.put(cur, d.getOrDefault(cur, 0) + 1);
        }

        List<Data> dd = new ArrayList<>();
        for (var cur : d.entrySet()) {
            dd.add(new Data(cur.getKey(), cur.getValue()));
        }

        Collections.sort(dd, (a, b) -> {
            if (a.cnt == b.cnt) {
                if (a.str.length() == b.str.length()) {
                    return a.str.compareTo(b.str);
                }
                return Integer.compare(b.str.length(), a.str.length());
            }

            return Integer.compare(b.cnt, a.cnt);
        });

        for (var cur : dd) {
            bw.write(cur.str + '\n');
        }
    }

    public static void main(String[] args) throws IOException {
        solution();
        bw.flush();
        bw.close();
        br.close();
    }
}