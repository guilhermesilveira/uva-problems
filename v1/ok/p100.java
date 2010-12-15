// @JUDGE_ID: 39315ZN 100 Java "Cache"

import java.io.IOException;
import java.io.InputStream;
import java.util.StringTokenizer;

class Main {

	static InputStream in = System.in;
	static int instanceCount = 0;

	public static void main(String[] args) throws Exception {
		while (instancia()) {
		}
	}

	static String readLine() throws IOException {
		return readLine(500);
	}

	static String readLine(int max) throws IOException {

		int i = 0, character = -1;
		String line = "";
		byte lin[] = new byte[max];

		while (i < max) {
			character = in.read();
			if ((character < 0) || (character == '\n'))
				break;
			lin[i++] += character;
		}

		// eof
		if ((character < 0) && (i == 0)) {
			return (null);
		}
		return (new String(lin, 0, i));

	}

	static Tokens parseLineTrim() throws IOException {
		String str = readLine();
		if (str == null) {
			return null;
		}
		return new Tokens(str.trim(), " ");
	}

	static Tokens parseLine() throws IOException {
		String str = readLine();
		if (str == null) {
			return null;
		}
		return new Tokens(str, " ");
	}

	/* O PROGRAMA COMECA AQUI */

	private static boolean instancia() throws Exception {

		Tokens line = parseLineTrim();
		if (line == null || line.str == null) {
			return false;
		} else if (line.str.equals("") || line.count == 0) {
			// linha vazia: fim
			return true;
		}

		int a = line.nextInt();
		int b = line.nextInt();
		int ninicial = a;
		int nfinal = b;
		
		if (b < a) {
			ninicial = b;
			nfinal = a;
		}

		int cyclemax = -1;
		for (int num = ninicial; num <= nfinal; num++) {
			int n = num;
			int cycle = 1;
			for (; n != 1; cycle++) {
				if ((n % 2) != 0)
					n = 3 * n + 1;
				else
					n >>= 1;
			}
			if (cycle > cyclemax) {
				cyclemax = cycle;
			}
		}

		System.out.println(a + " " + b + " " + cyclemax);

		return true;

	}

}

class Tokens extends StringTokenizer {
	int count;
	String str;
	Tokens(String str, String delim) {
		super(str, delim);
		this.str = str;
		count = countTokens();
	}
	int nextInt() {
		return Integer.parseInt(nextToken());
	}
	double nextDouble() {
		return Double.valueOf(nextToken()).doubleValue();
	}
	long nextLong() {
		return Long.valueOf(nextToken()).longValue();
	}
}

class BigNumber {

	final static int MAXSIZE = 500;
	char[] data = new char[MAXSIZE];
	char actualSize = 1;
	boolean positive = true;
	
	final static BigNumber ZERO = new BigNumber();
	
	BigNumber() {
		this.data[0] = 0;
	}
	
	BigNumber(int value) {
		this(value + "");
	}
	
	BigNumber(String value) {

		int atual = 0;
	
		if(value==null || value.equals("") || value.equals("0") || value.equals("+0") || value.equals("-0")) {
			this.data[0] = 0;
			return;
		}

		if(value.charAt(0)=='+') {
			atual=1;
		} else if(value.charAt(0)=='-') {
			atual=1;
			positive=false;
		}

		// passa por cada valor
		int size = value.length();

	}
	
	void add(BigNumber b) {
	}
	
	void add(int b) {
	}
	
	void subtract(BigNumber b) {
	}
	
	void subtract(int b) {
	}
	
	void multiply(BigNumber b) {
	}
	
	void multiply(int b) {
	}
	
	void divide(BigNumber b) {
	}
	
	void divide(int b) {
	}
	
	int rest(BigNumber b) {
		return 0;
	}
	
	int rest(int b) {
		return 0;
	}

}
