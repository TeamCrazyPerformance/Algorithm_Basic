import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 행렬_1080 {

	public static void main(String[] args) throws IOException {
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 StringTokenizer st = null;
		 
		 st = new StringTokenizer(br.readLine());
		 int N = Integer.parseInt(st.nextToken());
		 int M = Integer.parseInt(st.nextToken());
		 
		 int[][] matrix_before = new int[N][M];
		 int[][] matrix_after = new int[N][M];
		 
		 for(int i=0; i<N; i++) {
			 String[] line = br.readLine().split("");
			 for(int j=0; j<M; j++) {
				 matrix_before[i][j] = Integer.parseInt(line[j]);
			 }
		 }
		 
		 for(int i=0; i<N; i++) {
			 String[] line = br.readLine().split("");
			 for(int j=0; j<M; j++) {
				 matrix_after[i][j] = Integer.parseInt(line[j]);
			 }
		 }
		 
		 int answer = 0;
		 for(int row=0; row<N-2; row++) {
			 for(int col=0; col<M-2; col++) {
				 if(matrix_before[row][col] == matrix_after[row][col])
					 continue;
				 else {
					 answer++;
					 for(int i=0; i<3; i++) { //3x3 뒤집기
						 for(int j=0; j<3; j++) {
							 if(matrix_before[row+i][col+j] == 0)
								 matrix_before[row+i][col+j] = 1;
							 else
								 matrix_before[row+i][col+j] = 0;
						 }
					 }
				 }
			 }
		 }
		 
		 for(int i=0; i<N; i++) {
			 for(int j=0; j<M; j++) {
				 if(matrix_before[i][j] != matrix_after[i][j]) {
					 System.out.println(-1);
					 System.exit(0);
				 }
			 }
		 }
		 System.out.println(answer);
	}
}
