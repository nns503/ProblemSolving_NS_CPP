import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());

        Queue<String> q = new LinkedList<>();
        Map<String, Integer> map = new HashMap<>();

        for (int i=0; i<l; i++) {
            String id = br.readLine();
            map.put(id, map.getOrDefault(id, 0) + 1);
            q.add(id);
        }

        StringBuilder result = new StringBuilder();
        int count = 0;

        while(!q.isEmpty()) {
            String id = q.poll();

            if(map.get(id) == 1) {
                result.append(id).append("\n");
                count++;
                if (count == k) {
                    break;
                }
            }
            else {
                map.put(id, map.get(id) - 1);
            }
        }
        System.out.print(result);
    }

    public static void main(String[] args) throws IOException {
        solution();
        bw.flush();
        bw.close();
        br.close();
    }
}