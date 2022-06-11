import java.util.*;
import java.io.*;
public class Homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt();
		boolean[] prime = new boolean[m-n+1];
		Arrays.fill(prime, true);
		if (n == 1) {
			for (int i = 2; i <= Math.sqrt(m); i++) {
				for (int j = Math.max((i * i), (n + i - 1) / i * i); j <= m; j+=i) {
					prime[j-n] = false;
				}
			}
		} else {
			for (int i = 2; i <= Math.sqrt(m); i++) {
				for (int j = Math.max((i * i), (n + i - 1) / i * i); j <= m; j+=i) {
					prime[j-n] = false;
				}
			}
		}
		for (int i = 0; i <= m-n; i++) {
			if (i+n == 1) {
				continue;
			}
			if (prime[i]) {
				System.out.println(i+n);
			}
		}
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}