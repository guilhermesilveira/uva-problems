import java.io.IOException;
import java.util.StringTokenizer;

class Main2102d {

	public static void main(String[] args) throws IOException {

		int cases = Integer.parseInt(readLine(255));
		for (int i = 0; i != cases; i++) {

			// mudar para LERUM AUM
			String[] line = breakLine(readLine(255));
			int garrafas = Integer.parseInt(line[0]);
			int deUm = Integer.parseInt(line[1]);
			int deCinco = Integer.parseInt(line[2]);
			int deDez = Integer.parseInt(line[3]);

			int moves = 0;

			System.out.println("--------------" + garrafas);

			while (garrafas > 0) {

				System.out.println(deDez + "," + deCinco + "," + deUm);

				if (deDez > 0) {
					// se possuo uma de dez ela me retorna duas de um
					deDez--;
					deUm += 2;
					moves++;
					System.out.println("a");
				} else if (deCinco == 1) {
					// se existe uma soh de cinco
					deCinco--;
					deUm -= 3;
					moves += 4;
					System.out.println("b");
				} else if (deCinco >= 1) {
					// existem duas ou mais de cinco
					if (deCinco == garrafas * 2) {
						// se eu consigo resolver com as de cinco
						deCinco -= 2 * garrafas;
						deUm += 3 * garrafas;
						moves += 2 * garrafas;
						garrafas = 1;
						System.out.println("n");
					} else if (deCinco >= 3 && deUm < 6) {
						// pode tirar duas de cindo
						deCinco -= 2;
						deUm += 2;
						moves += 2;
						System.out.println("k");
					} else {
						if (garrafas == 1) {
							deCinco -= 2;
							deUm += 3;
							moves += 2;
							System.out.println("c");
						} else if (deUm >= 6) {
							deCinco -= 2;
							deUm -= 6;
							moves += 8;
							garrafas--;
							System.out.println("d");
						} else {
							deCinco -= 1;
							deUm -= 3;
							moves += 4;
							System.out.println("e");
						}
					}
				} else {
					// soh tenho de um
					deUm -= 8;
					moves += 8;
					System.out.println("8x1");
				}
				garrafas--;
				//System.out.println("faltam " + garrafas + " (" + moves + ")");

			}

			//System.out.println(deDez  + "," +deCinco + "," + deUm);

			System.out.println(moves);

		}

	}

	static String[] breakLine(String s) {
		StringTokenizer st = new StringTokenizer(s, " ");
		String[] tokens = new String[st.countTokens()];
		for (int i = 0; i != tokens.length; i++) {
			tokens[i] = st.nextToken();
		}
		return tokens;
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