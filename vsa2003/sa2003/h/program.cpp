#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>

using namespace std;

int pecaCount;
set<> meuSet;
Peca ignoravel;
int maiorSoma;
bool encontrado;
int somaAbsoluta;
int somaAbsolutaCorrente;
Peca menorPecaIgnoravel;
int maximos[] = new int[1001];

map<> mapas[];

int main() {

	int temp;

	while (true) {

		pecaCount = Integer.parseInt(readLine(10).trim());
		if (pecaCount == 0) {
			break;
		}

		set.clear();
		menorPecaIgnoravel = null;
		maiorSoma = -1;
		ignoravel = null;

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

		int somaMaxima = 0;
		somaAbsoluta = 0;
		for (int i = pecaCount - 1; i != -1; i--) {
			somaAbsoluta += getPeca(i).cima + getPeca(i).baixo;
			somaMaxima += getPeca(i).abs;
			maximos[i] = somaMaxima;
			getPeca(i).level = i;
			if (mapas[i] == null) {
				mapas[i] = new HashSet();
			} else {
				mapas[i].clear();
			}
		}

		//System.out.println("\n\nNovo sistema com " + pecaCount + " :: " + somaAbsoluta);

		encontrado = false;

		// se possue uma so peca
		if (pecaCount == 1) {
			if (getPeca(0).abs != 0) {
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

		if (somaAbsoluta % 2 == 0) {
			
			somaAbsolutaCorrente = somaAbsoluta / 2;
			// tenta para todos assim
			tenta(0, 0, 0);

			if (encontrado) {
				continue;
			}
		}

		menorPecaIgnoravel = null;
		maiorSoma = -1;

		for (int i = 0; i != pecaCount; i++) {

			if (getPeca(i).abs == 0) {
				continue;
			}

			for (int i2 = 0; i2 != pecaCount; i2++) {
				mapas[i2].clear();
			}

			ignoravel = getPeca(i);
			
			if ((somaAbsoluta-ignoravel.cima - ignoravel.baixo) % 2 == 0) {
			
				// se ja encontrou
				if (encontrado) {
					// se a metade da peca menor for maior que a base dessa aqui, pode eskipar essa
					if (menorPecaIgnoravel.cima + menorPecaIgnoravel.baixo
							< ignoravel.cima + ignoravel.baixo) {
						continue;
					}
				}
				
				somaAbsolutaCorrente = (somaAbsoluta - ignoravel.cima - ignoravel.baixo) / 2;
				//System.out.println("ignorando " + ignoravel + " :: " + somaAbsolutaCorrente);
				//imprime();
				tenta(0, 0, 0);
			}

		}

		if (!encontrado) {

			System.out.println("impossible");

		} else {

			printDiscard(maiorSoma, menorPecaIgnoravel);

		}

	}
	
}

void printDiscard(int i, Peca peca) {
	System.out.println(i + " discard " + peca.baixo + " " + peca.cima);
}

void imprime() {
	for (int i = 0; i != pecaCount; i++) {
		if (ignoravel != null && getPeca(i) == ignoravel)
			continue;
		Peca temp = getPeca(i);
		cout << 
			"[" << temp.cima << "/" << temp.baixo << "/" << temp.abs << "],";
	}
	cout << endl;
}

Peca getPeca(int i) {
	return (Peca) set.get(i);
}

static boolean tenta(int p, int diferenca, int somaDeUmLado) {
	
	if(somaDeUmLado>somaAbsolutaCorrente) {
		return false;
	}

	if (p == pecaCount) {

		// se a soma deu 0
		if (diferenca == 0) {

			if (ignoravel != null) {

				//System.out.println(somaDeUmLado + " ENCONTROU");
				if (!encontrado || somaDeUmLado > maiorSoma) {

					//System.out.println(somaDeUmLado + " REPLACE");
					maiorSoma = somaDeUmLado;
					menorPecaIgnoravel = ignoravel;

				} else if (somaDeUmLado == maiorSoma) {

					if (ignoravel.baixo < menorPecaIgnoravel.baixo) {
						//System.out.println(somaDeUmLado + " REPLACE");
						maiorSoma = somaDeUmLado;
						menorPecaIgnoravel = ignoravel;
					}

				}

			} else {

				System.out.println(somaDeUmLado + " discard none");

			}

			encontrado = true;
			return true;

		}

		return false;

	}

	// se a diferenca estourou, para e volta
	if (Math.abs(diferenca) > maximos[p]) {
		return false;
	}

	Peca posicaoAtual = getPeca(p);

	// se eu ja passei aqui
	if (mapas[p].contains(new Integer(diferenca))) {
		return false;
	}

	// estou passando, se voltar nao venha aqui
	mapas[p].add(new Integer(diferenca));
	
	if (posicaoAtual == ignoravel) {
		return tenta(p + 1, diferenca, somaDeUmLado);
	}

	if (posicaoAtual.abs == 0) {
		return tenta(p + 1, diferenca, somaDeUmLado + posicaoAtual.baixo);
	}

	if (tenta(p + 1,
		diferenca + posicaoAtual.abs,
		somaDeUmLado + posicaoAtual.cima)) {
		return true;
	}

	if (tenta(p + 1,
		diferenca - posicaoAtual.abs,
		somaDeUmLado + posicaoAtual.baixo)) {
		return true;
	}

	return false;

}

String[] split(String s) {
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

class MyCompareThem implements Comparator {

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
