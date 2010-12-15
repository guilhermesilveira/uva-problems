import java.io.IOException;

class TEMPORARIO {

	static boolean found = false;
	static long target;

	public static void main(String[] args) throws IOException {

		int i = 0;
		while ((target = readLong(50)) != -1) {

			found = false;

			int m = 0;
			int n = 0;
			int p = 0;
			int areas = 1;

			System.out.println("Case " + ++i + ":");
			// para cada valor valido
			tentaAreas(m, n, p, areas);
			if (!found) {
				System.out.println("Impossible.");
			}

		}

	}

	private static void tentaAreas(int m, int n, int p, int areas) {

		// se acertou
		if (areas == target) {
			System.out.println(m + " " + n + " " + p);
			found = true;
			return;
		} else if (areas > target) {
			// estourou
			return;
		}

		// tenta adicionar mais uma area
		if (m != 99) {
			tentaAreas(m + 1, n, p, areas == 1 ? 2 : areas + (2 * m));
		}
		if (n != 19999) {
			tentaAreas(m, n + 1, p, areas == 1 ? 2 : areas + (3 * n));
		}
		if (p != 99) {
			tentaAreas(m, n, p + 1, areas == 1 ? 2 : areas + (4 * p));
		}

	}

	// le o proximo int, ate o \n ou ' ' 
	static long readLong(int maxLg) throws IOException {
		byte lin[] = new byte[maxLg];
		int lg = 0, car = -1;
		while ((car < 0) && (lg == 0)) {
			while (lg < maxLg) {
				car = System.in.read();
				if ((car < 0) || (car == '\n') || (car == ' '))
					break;
				lin[lg++] += car;
			}
		}
		if (lin[lg - 1] == 13 || lin[lg - 1] == 10 || lin[lg - 1] == ' ') {
			lin[lg - 1] = 0;
		}
		return Long.valueOf(new String(lin, 0, lg).trim()).longValue();
	}

	// le uma linha inteira
	static String readLine(int maxLg) throws IOException {
		byte lin[] = new byte[maxLg];
		int lg = 0, car = -1;
		while (lg < maxLg) {
			car = System.in.read();
			if ((car < 0) || (car == '\n'))
				break;
			lin[lg++] += car;
		}
		if ((car < 0) && (lg == 0))
			return (null); // eof
		return (new String(lin, 0, lg));
	}
}
