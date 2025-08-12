import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line = br.readLine();

        StringTokenizer st = new StringTokenizer(line, " ");

        int n = Integer.parseInt(st.nextToken());

        int m = Integer.parseInt(st.nextToken());
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if(n % i == 0) count++;
            if(count == m){bw.write(String.valueOf(i)); break;} 
        }
        if(count < m) bw.write(String.valueOf(0));

        bw.flush();

        br.close();
        bw.close();
    }
    
}