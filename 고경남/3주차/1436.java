import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 영화감독_숌 {

	public static boolean checkTripleSix(int num) {
		String num_str = String.valueOf(num);
		if(num_str.contains("666"))
			return true;
		else return false;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int num = 666;
		
		for(int i=0; i<N; i++) {
			while(!checkTripleSix(num)) {
				num++;
			}
			num++;
		}
		System.out.println(num - 1);
	}
}
