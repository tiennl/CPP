import java.io.*;
import java.util.*;
import java.math.*;

public class meisterT {
	public static void main(String args[]) {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);		

		int numCases = sc.nextInt();
		for (int i = 0; i < numCases; i++) {
			int divisor = sc.nextInt();
			int numNumbers = sc.nextInt();

			ArrayList<Integer> countRemainders = new ArrayList<Integer>(Collections.nCopies(divisor, 0));

			int akku = 0;
			int sum = 0;
			countRemainders.set(0, 1);
			for (int j = 0; j < numNumbers; j++) {
				int tmp = sc.nextInt();
				akku = (tmp + akku) % divisor;
				sum += countRemainders.get(akku);
				countRemainders.set(akku, countRemainders.get(akku) + 1);
			}

			System.out.printf("%d\n", sum);
		}
	}
}
