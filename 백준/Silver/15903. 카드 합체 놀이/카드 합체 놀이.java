import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        //그냥 가장 작은수 두개씩 n번 합치면 끝 아닌가?

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());

        PriorityQueue<Long> pq = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            pq.add(Long.parseLong(st.nextToken()));
        }

        for (int i = 0; i < m; i++) {
            long x = pq.peek();
            pq.remove(x);

            long y = pq.peek();
            pq.remove(y);
            long sum = x + y;

            pq.add(sum);
            pq.add(sum);
        }

        long total = 0;
        for (long card : pq) {
            total += card;
        }

        System.out.println(total);
    }
}