import java.io.IOException;

class Main {

	public static void main(String[] args) throws IOException {

		while (true) {

			long L = readLong(36);

			if (L == 0) {
				break;
			}

			long u = readLong(36);
			long v = readLong(36);
			long t = readLong(36);
			long voltas = 0;
			
			// o primeiro L eh para se encontrarem, apos isso, eh necessario dois Ls para cada encontro

			// velocidade total
			long uv = u + v;
			
			// distancia total percorrida
			double vuv = uv * t;

			// se tem no minimo uma volta
			if (vuv > L) {
				vuv -= L;
				voltas++;
				// se ainda percorre mais voltas
				if (vuv > 2 * L) {
					voltas += (long) vuv / (2 * L);
				}
			}

			System.out.println(voltas);

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
