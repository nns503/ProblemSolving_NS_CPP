import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int r, c;

    static class Point{
        int y;
        int x;
        Point(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    
    static boolean OOB(int y, int x){
        return (y < 0 || x < 0 || y >= r || x >= c);
    }
    
    public static void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        c = Integer.parseInt(st.nextToken()); // C
        r = Integer.parseInt(st.nextToken()); // R
        int[][] board = new int[r][c];
        
        int k = Integer.parseInt(br.readLine());

        int d = 0;
        int num = 1;
        board[r-1][0] = 1;
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(r-1, 0));

        while(!q.isEmpty()){
            Point cur = q.poll();
            if(board[cur.y][cur.x] == k){
                bw.write((cur.x + 1) + " " + (r - cur.y));
                return;
            }
            for(int i=0; i<4; i++){
                int nd = (d + i) % 4;
                int ny = cur.y + dy[nd];
                int nx = cur.x + dx[nd];
                if(OOB(ny, nx)) continue;
                if(board[ny][nx] != 0) continue;
                board[ny][nx] = ++num;
                q.add(new Point(ny, nx));
                d = nd;
                break;
            }
        }
        
        bw.write(String.valueOf(0));
    }

    public static void main(String[] args) throws IOException {
        solution();
        bw.flush();
        bw.close();
        br.close();
    }
}