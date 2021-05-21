// Author: Adrian Kuegel
// Algorithm: Dynamic Programming
// Complexity: O(n^3)

import java.io.*;

public class mountain_road {
	public static void main(String [] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		int [][] arriving_time = new int[2][200];
		int [][] travel_time = new int[2][200]; 
		int [][][] dp = new int[201][201][2];
		while(tc-- > 0) {
			int N = Integer.parseInt(br.readLine());
			int [] n = new int[2];
			n[0] = n[1] = 0;
			int t, d, type;
			while(N-- > 0) {
				String [] tokens = br.readLine().split(" ");
				type = (int)(tokens[0].charAt(0) - 'A');
				arriving_time[type][n[type]] = Integer.parseInt(tokens[1]);
				travel_time[type][n[type]] = Integer.parseInt(tokens[2]);
				++n[type];
			}
			for (int i=0; i <= n[0]; ++i)
				for (int j=0; j <= n[1]; ++j)
					dp[i][j][0] = dp[i][j][1] = Integer.MAX_VALUE / 10;
			dp[0][0][0] = dp[0][0][1] = 0;
			for (int i=0; i <= n[0]; ++i)
				for (int j=0; j <= n[1]; ++j)
					for (int k=0; k<2; ++k) {
						int last_end = dp[i][j][k] - 10;
						int last_start = last_end;
						for (int l= (k > 0)? j : i; l<n[k]; ++l) {
							int next_start = Math.max(last_start + 10, arriving_time[k][l]);
							int next_end = Math.max(next_start + travel_time[k][l], last_end + 10);
							if (k > 0)
								dp[i][l+1][0] = Math.min(dp[i][l+1][0], next_end);
							else
								dp[l+1][j][1] = Math.min(dp[l+1][j][1], next_end);
							last_start = next_start;
							last_end = next_end;
						}
					}

			System.out.println(Math.min(dp[n[0]][n[1]][0], dp[n[0]][n[1]][1]));
		}
	}
}
