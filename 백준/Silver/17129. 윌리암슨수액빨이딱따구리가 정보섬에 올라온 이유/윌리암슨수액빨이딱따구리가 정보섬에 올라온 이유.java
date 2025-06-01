import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};

    static class Point{
        int y;
        int x;

        Point(int y, int x){
            this.y = y;
            this.x = x;
        }
    }

    static boolean OOB(int y, int x){
        return (y < 0 || x < 0 || y >= n || x >= m);
    }

    public static void solution() throws IOException {
        // 1. 초기 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        String[] board = new String[n];
        for(int i=0; i<n; i++){
            board[i] = br.readLine();
        }
        
        // 2. 출발 위치 탐색
        int stY = 0;
        int stX = 0;
        for(int y=0; y<n; y++){
            for(int x=0; x<m; x++){
                if(board[y].charAt(x) == '2'){
                    stY = y;
                    stX = x;
                }
            }
        }

        // 3. 타겟 위치 탐색 
        int[][] dist = new int[n][m];
        for(int i=0; i<n; i++){
            Arrays.fill(dist[i], 0x3f3f3f3f);
        }
        Queue<Point> q = new LinkedList<>();
        dist[stY][stX] = 0;
        q.add(new Point(stY, stX));
        
        while(!q.isEmpty()){
            Point cur = q.poll();

            for(int i=0; i<4; i++){
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if(OOB(ny, nx)) continue;
                if(board[ny].charAt(nx) == '1') continue;
                if(dist[ny][nx] != 0x3f3f3f3f) continue;
                dist[ny][nx] = dist[cur.y][cur.x] + 1;
                q.add(new Point(ny, nx));
            }
        }

        // 4. 최소 거리 선정정
        int answer = 0x3f3f3f3f;
        for(int y=0; y<n; y++){
            for(int x=0; x<m; x++){
                if(board[y].charAt(x) == '3' || board[y].charAt(x) == '4' || board[y].charAt(x) == '5'){
                    answer = Math.min(answer, dist[y][x]);
                }
            }
        }
        
        // 5. 출력
        if(answer == 0x3f3f3f3f){
            bw.write("NIE");
        }
        else{
            bw.write("TAK" + '\n' + String.valueOf(answer));
        }
    }

    public static void main(String[] args) throws IOException {
        solution();
        bw.flush();
        bw.close();
        br.close();
    }
}