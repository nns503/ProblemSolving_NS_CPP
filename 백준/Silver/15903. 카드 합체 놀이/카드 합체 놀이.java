import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    public static void solution() throws IOException {
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st1.nextToken());
        int m = Integer.parseInt(st1.nextToken());
        
        PriorityQueue<Long> q = new PriorityQueue<>();
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        
        while (st2.hasMoreTokens()){
            q.add(Long.parseLong(st2.nextToken()));
        }

        while(m-- > 0){
            Long a = q.poll();
            Long b = q.poll();
            q.add(a+b);
            q.add(a+b);
        }

        Long answer = 0L;
        while(!q.isEmpty()){
            answer += q.poll();
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