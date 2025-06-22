import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int n, m;
    static int[] dy = {1, -1, 0, 0};
    static int[] dx = {0, 0, 1, -1};

    static class Point {
        int y, x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static boolean OOB(int y, int x) {
        return (y < 0 || x < 0 || y >= n || x >= m);
    }

    static int BFS(int stY, int stX, List<String> board){
        Queue<Point> q = new LinkedList<>();
        int[][] dist = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], -1);
        }

        q.add(new Point(stY, stX));
        dist[stY][stX] = 0;

        int maxDist = -1;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            maxDist = Math.max(maxDist, dist[cur.y][cur.x]);

            for (int i = 0; i < 4; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (OOB(ny, nx)) continue;
                if (board.get(ny).charAt(nx) == 'W') continue;
                if (dist[ny][nx] != -1) continue;

                dist[ny][nx] = dist[cur.y][cur.x] + 1;
                q.add(new Point(ny, nx));
            }
        }
        return maxDist;
    }

    public static int solve(List<String> board) {
        int answer = -1;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (board.get(y).charAt(x) == 'W') continue;
                answer = Math.max(answer, BFS(y, x, board));
            }
        }
        return answer;
    }

    public static void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        List<String> board = new ArrayList<>();
        for (int y = 0; y < n; y++) {
            board.add(br.readLine());
        }

        bw.write(String.valueOf(solve(board)));
    }

    public static void main(String[] args) throws IOException {
        solution();
        bw.flush();
        bw.close();
        br.close();
    }
}