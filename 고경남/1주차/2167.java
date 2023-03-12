import java.util.Scanner;

public class 이차원_배열의_합 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		int NM_arr[][] = new int[N][M];
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				NM_arr[i][j] = sc.nextInt();
			}
		}
		
		int K = sc.nextInt();
		int K_arr[][] = new int[K][4];
		
		for(int i = 0; i < K; i++) {
			for(int j = 0; j < 4; j++) {
				K_arr[i][j] = sc.nextInt();
			}
		}
		
		for(int l = 0; l < K; l++) {
			int i = K_arr[l][0];
			int j = K_arr[l][1];
			int x = K_arr[l][2];
			int y = K_arr[l][3];
			int sum = 0;
			int tmp = j;
			
			for(; i <= x; i++) {
				for(; j <= y; j++)
					sum += NM_arr[i-1][j-1];
				j = tmp;
			}
			System.out.println(sum);
		}
	}
}
