import java.io.*;
import java.util.*;
import java.math.*;

public class meisterT {

	public static final int MAX_PRIME = 10000000;

	public static boolean notPrime[] = new boolean[MAX_PRIME];
	public static String buffer;
	public static int digits[] = new int[1024];

	public static int numDigits;
	public static SortedSet<Integer> foundPrimes;

	public static void sieve() {
		notPrime[0] = notPrime[1] = true;
		for (int i = 4; i < MAX_PRIME; i += 2) {
			notPrime[i] = true;
		}
		for (int i = 3; i * i <= MAX_PRIME; i += 2) {
			for (int j = i * i; j < MAX_PRIME; j += i) {
				notPrime[j] = true;
			}
		}
	}

	public static void generate(int curDigits[], int curNumDigits, int curNum) {
		boolean longer = false;
		for (int i = 0; i < curNumDigits; i++) {
			if (curDigits[i] >= 0) {
				longer = true;
				int newNum = curNum * 10 + curDigits[i];
				int oldDigit = curDigits[i];
				curDigits[i] = -1;
				generate(curDigits, curNumDigits, newNum);
				curDigits[i] = oldDigit;
			}
		}

		if (!longer) {
			if (!notPrime[curNum]) {
				foundPrimes.add(curNum);
			}
		}
	}

	public static void compute(int mask) {
		int curNumDigits = 0;
		int curDigits[] = new int[1024];
		for (int i = 0; i < numDigits; i++) {
			if ((mask & (1 << i)) != 0) {
				curDigits[curNumDigits] = digits[i];
				++curNumDigits;
			}
		}

		generate(curDigits, curNumDigits, 0);
	}

	public static void main(String args[]) {
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);		

		sieve();

		int numCases = sc.nextInt();

		while (numCases > 0) {
			--numCases;

			buffer = sc.next();
			numDigits = 0;
			for (int i = 0; i < buffer.length(); i++) {
				digits[numDigits] = buffer.charAt(numDigits) - '0';
				numDigits++;
			}

			foundPrimes = new TreeSet<Integer>();
			for (int i = 1; i < (1 << numDigits); i++) {
				compute(i);
			}
			System.out.printf("%d\n", foundPrimes.size());

		}
	}
}
