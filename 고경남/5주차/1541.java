import java.util.Scanner;

public class 잃어버린_괄호 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String sub[] = sc.nextLine().split("-");
		
		int answer = 0;
		boolean check_first = true;
		for(int i=0; i<sub.length; i++) {
			int sum = 0;
			
			String add[] = sub[i].split("\\+");
			
			for(int j=0; j<add.length; j++)
				sum += Integer.parseInt(add[j]);
			
			if(check_first) { 
				answer = sum; //처음에는 무조건 양수값만 올 수 있음
				check_first = false;
			}
			else 
				answer -= sum;
		}
		System.out.println(answer);
	}
}
