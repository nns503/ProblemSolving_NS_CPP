import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    public static int solution() throws IOException {
        String str = br.readLine();
        Map<Character, Integer> cnt = new HashMap<>();
        int answer = 0;
        int curCnt = 0;

        for(int i=0; i<str.length(); i++){
            char cur = str.charAt(i);
            if(cur == 'q'){
                cnt.put('q', cnt.getOrDefault('q', 0) + 1);
                curCnt++;
                answer = Math.max(answer, curCnt);
            }
            else if(cur == 'u'){
                if (cnt.getOrDefault('q', 0) == 0) return -1;
                cnt.put('q', cnt.getOrDefault('q', 0) - 1);
                cnt.put('u', cnt.getOrDefault('u', 0) + 1);
            }
            else if(cur == 'a'){
                if (cnt.getOrDefault('u', 0) == 0) return -1;
                cnt.put('u', cnt.getOrDefault('u', 0) - 1);
                cnt.put('a', cnt.getOrDefault('a', 0) + 1);
            }
            else if(cur == 'c'){
                if (cnt.getOrDefault('a', 0) == 0) return -1;
                cnt.put('a', cnt.getOrDefault('a', 0) - 1);
                cnt.put('c', cnt.getOrDefault('c', 0) + 1);
            }
            else if(cur == 'k'){
                if (cnt.getOrDefault('c', 0) == 0) return -1;
                cnt.put('c', cnt.getOrDefault('c', 0) - 1);
                curCnt--;
            }
        }

        for(var cur : cnt.entrySet()){
            if(cur.getValue() != 0) return -1;
        }
        return answer;

    }

    public static void main(String[] args) throws IOException {
        int answer = solution();
        bw.write(String.valueOf(answer));
        bw.flush();
        bw.close();
        br.close();
    }
}