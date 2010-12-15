// @JUDGE_ID: 39315ZN 119 Java "Dando e recebendo"

// 1: tirar os system outs
// 2: tirar o DEBUG
// 3: tirar o pacote

package um.p119;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Hashtable;
import java.util.StringTokenizer;
import java.util.Vector;

class Main {

	static boolean DEBUG = true;
	static InputStream in = System.in;

	public static void main(String[] args) throws Exception {
		if (DEBUG) {
			in = new FileInputStream(args[0]);
		}
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
			character = System.in.read();
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

	static int grupos = 0;

	private static boolean instancia() throws Exception {

		Tokens line = parseLineTrim();
		if (line == null) {
			return false;
		} else if (line.count == 0) {
			// linha vazia: fim
			return false;
		}

		if (grupos++ != 0) {
			System.out.println("");
		}

		int userCount = line.nextInt();
		line = parseLineTrim();
		Hashtable users = new Hashtable();
		Vector vusers = new Vector();

		for (int i = 0; i != userCount; i++) {
			User u = new User();
			u.name = line.nextToken();
			users.put(u.name.toLowerCase(), u);
			vusers.addElement(u);
		}

		for (int i = 0; i != userCount; i++) {
			line = parseLineTrim();
			User u = (User) users.get(line.nextToken().toLowerCase());
			u.inicial = line.nextInt();
			int quantos = line.nextInt();
			if (u.inicial == 0 || quantos == 0) {
				u.sobra = u.inicial;
			} else {
				// vai dividir com uma galera
				int paraCada = u.inicial / quantos;
				u.sobra = u.inicial % quantos;
				for (int z2 = 0; z2 < quantos; z2++) {
					User u2 = (User) users.get(line.nextToken().toLowerCase());
					u2.recebe += paraCada;
					u.dado += paraCada;
				}
			}
		}

		// para cada cara
		for (int i = 0; i != vusers.size(); i++) {
			User u = (User) vusers.elementAt(i);
			// adiciona seus valores aos valores do cara
			System.out.println(u.name + " " + (u.recebe - u.dado));
		}

		return true;

	}

}

class User {
	String name;
	int inicial;
	int sobra;
	int dado;
	int recebe = 0;
}

class Tokens extends StringTokenizer {
	int count;
	Tokens(String str, String delim) {
		super(str, delim);
		count = countTokens();
	}
	int nextInt() {
		return Integer.parseInt(nextToken());
	}
	double nextDouble() {
		return Double.valueOf(nextToken()).doubleValue();
	}
}
