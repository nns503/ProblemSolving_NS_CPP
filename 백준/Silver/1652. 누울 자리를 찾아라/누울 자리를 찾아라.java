import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void solution() throws IOException {
        int n = Integer.parseInt(br.readLine());
        List<String> board = new ArrayList<>();
        for(int i = 0; i < n; i++){
            board.add(br.readLine());
        }

        List<Integer> answer = new ArrayList<>(Arrays.asList(0, 0));

        for(int y=0; y<n; y++) {
            int x = 0;
            while(x < n-1) {
                if(board.get(y).charAt(x) == '.' && board.get(y).charAt(x + 1) == '.'){
                    answer.set(0, answer.get(0) + 1);
                    while(x < n && board.get(y).charAt(x) == '.'){
                        x++;
                    }
                } 
                else{
                    x++;
                }
            }
        }

        for(int x=0; x<n; x++){
            int y = 0;
            while(y < n-1){
                if(board.get(y).charAt(x) == '.' && board.get(y + 1).charAt(x) == '.'){
                    answer.set(1, answer.get(1) + 1);
                    while(y < n && board.get(y).charAt(x) == '.'){
                        y++;
                    }
                } 
                else{
                    y++;
                }
            }
        }

        bw.write(answer.get(0) + " " + answer.get(1));
    }

    public static void main(String[] args) throws IOException {
        solution();
        bw.flush();
        bw.close();
        br.close();
    }
}