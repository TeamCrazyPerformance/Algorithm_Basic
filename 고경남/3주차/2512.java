import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 예산 {

	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int N = Integer.parseInt(br.readLine());
		
		st = new StringTokenizer(br.readLine());
		int regions[] = new int[N];
		for(int i=0; i<N; i++)
			regions[i] = Integer.parseInt(st.nextToken());
		
		int M = Integer.parseInt(br.readLine());
		
		int sum = 0;
		int max = 0;
		for(int i=0; i<N; i++) {
			sum += regions[i];
			if(regions[i] > max) {
				max = regions[i];
			}
		}
		
		if(sum <= M) {
			System.out.println(max);
			System.exit(0);
		}
		else {
			int front = 0;
			int back = M;
			int middle = (front + back)/2;
			while(front <= back) {
				sum = 0;
				for(int i=0; i<N; i++) {
					if(regions[i] <= middle) {
						sum += regions[i];
					}
					else {
						sum += middle;
					}
				}
				
				if(sum == M) { //이진 탐색
					System.out.println(middle);
					System.exit(0);
				}
				else if(sum < M) {
					front = middle + 1;
				}
				else {
					back = middle - 1;
				}
				middle = (front + back) / 2;
			}
			
			System.out.println(middle);
		}
	}
}
