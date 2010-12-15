import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

class Peca {
	int cima;
	int baixo;
	int abs;
	int level;
	
	public String toString() {
		return "[" +this.cima +"/"+this.baixo+","+this.abs+"]"; 
	}
}

class Main {

	static int pecaCount;
	static ArrayList set = new ArrayList();
	static Peca ignoravel;
	static int maiorSoma;
	static boolean encontrado;
	static Peca menorPecaIgnoravel;

	public static void main(String args[])
		throws NumberFormatException, IOException {

		int temp;

		while (true) {

			pecaCount = Integer.parseInt(readLine(10).trim());
			if (pecaCount == 0) {
				break;
			}

			set.clear();
			menorPecaIgnoravel=null;
			maiorSoma=-1;
			ignoravel=null;

//System.out.println("\n\nNovo sistema com " + pecaCount);

			for (int i = 0; i != pecaCount; i++) {
				String[] linha = split(readLine(30));
				Peca p = new Peca();
				p.cima = Integer.parseInt(linha[0]);
				p.baixo = Integer.parseInt(linha[1]);
				if (p.cima < p.baixo) {
					temp = p.cima;
					p.cima = p.baixo;
					p.baixo = temp;
				}
				p.abs = Math.abs(p.cima - p.baixo);
				set.add(p);
			}

			Collections.sort(set, new CompareThem());

			//imprime();

			encontrado = false;

			// se possue uma so peca
			if (pecaCount == 1) {
				if (getPeca(0).abs == 0) {
					System.out.println("impossible");
					continue;
				} else {
					System.out.println(getPeca(0).cima + " discard none");
					continue;
				}
			}

			if (pecaCount == 2) {
				if (getPeca(0).abs == 0) {
					printDiscard(getPeca(0).cima, getPeca(1));
					continue;
				}
				if (getPeca(1).abs == 0) {
					printDiscard(getPeca(1).cima, getPeca(0));
					continue;
				}
				System.out.println("impossible");
				continue;
			}

			// tenta para todos assim
			tentativa();

			// se encontrou, para
			if (encontrado) {
				continue;
			}

			//System.out.println("normal nao deu");

			menorPecaIgnoravel = null;
			maiorSoma = -1;

			for (int i = 0; i != pecaCount; i++) {

				if (getPeca(i).abs == 0) {
					continue;
				}

				ignoravel = getPeca(i);

//				System.out.println("ignorando: " + getPeca(i));
				//imprime();

				tentativa();

			}

			if (!encontrado) {

				System.out.println("impossible");

			} else {

				printDiscard(maiorSoma, menorPecaIgnoravel);

			}

		}

	}

	/**
	 * @param i
	 * @param peca
	 */
	private static void printDiscard(int i, Peca peca) {
		System.out.println(i + " discard " + peca.baixo + " " + peca.cima);
	}

	/**
	 * Imprime os que vao entrar na conta 
	 */
	private static void imprime() {
		for (int i = 0; i != pecaCount; i++) {
			if (ignoravel != null && getPeca(i) == ignoravel)
				continue;
			Peca temp = getPeca(i);
			System.out.print(
				"[" + temp.cima + "/" + temp.baixo + "/" + temp.abs + "],");
		}
		System.out.println();
	}

	private static Peca getPeca(int i) {
		return (Peca) set.get(i);
	}

	private static void tentativa() {

		// soma o primeiro
		int somaAtual = 0;
		int diferenca = 0;
		int usados = 1;
		int primeiroUsado = 0;
		int ultimoUsado = pecaCount;

		if (ignoravel != null && ignoravel == getPeca(0)) {

			usados++;
			primeiroUsado++;
			somaAtual = getPeca(1).cima;
			diferenca = getPeca(1).abs;
//			System.out.println("+cima=" + getPeca(1) + "/" +diferenca);

		} else {

			somaAtual = getPeca(0).cima;
			diferenca = getPeca(0).abs;
//			System.out.println("+cima=" + getPeca(0));

		}

		//System.out.println("comecando com: " + diferenca + " em " + getPeca(0));

		while (usados != pecaCount) {

			// se a diferenca for maior que 0
			if (diferenca > 0) {
				ultimoUsado--;
				Peca p = getPeca(ultimoUsado);
				if (p != ignoravel) {
					diferenca -= p.abs;
					somaAtual += p.baixo;
//					System.out.println("+baixo=" + p);
				}
				usados++;
			} else {
				primeiroUsado++;
				Peca p = getPeca(primeiroUsado);
				if (p != ignoravel) {
					diferenca += p.abs;
					somaAtual += p.cima;
//					System.out.println("+cima=" + p);
				}
				usados++;
			}

		}

		if (diferenca == 0) {
			
//			System.out.println("diferenca==0");

			if (ignoravel == null) {

				encontrado = true;
				System.out.println(somaAtual + " discard none");

			} else {

				// comparacoes
				System.out.println("encontrado ignorando " + ignoravel);
				if (!encontrado || somaAtual > maiorSoma) {

					maiorSoma = somaAtual;
					menorPecaIgnoravel = ignoravel;
					System.out.println(somaAtual + " :menor: " + ignoravel);

				} else if (somaAtual == maiorSoma) {

					if (ignoravel.baixo < menorPecaIgnoravel.baixo) {
						maiorSoma = somaAtual;
						menorPecaIgnoravel = ignoravel;
						System.out.println(somaAtual + " :menor: " + ignoravel);
					}

				}
				encontrado = true;
			}
		}

	}

	private static void mais(int i, boolean mais) {
		if (mais) {
			//System.out.println("+ " + pecas[i][0] + "/" + pecas[i][1]);
		} else {
			//System.out.println("+ " + pecas[i][0] + "/" + pecas[i][1]);
		}
	}

	static String[] split(String s) {

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
			if ((car < 0) || (car == '\n')) {
				break;
			}
			lin[lg++] += car;
		}

		if ((car < 0) && (lg == 0)) {
			return (null); // eof
		}

		return (new String(lin, 0, lg));

	}

}

class CompareThem implements Comparator {

	public int compare(Object o1, Object o2) {
		Peca i1 = ((Peca) o1);
		Peca i2 = ((Peca) o2);
		if (i1.abs > i2.abs) {
			return -1;
		} else if (i1.abs == i2.abs) {
			return 0;
		} else {
			return 1;
		}
	}

}
