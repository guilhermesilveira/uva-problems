package acm.sulamericana.ano2003;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

public class pawns {

	public static void main(String[] args) throws Exception {
		LineReader r = new LineReader();
		r.setFile(args[0]);
		Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
		while (instancia(r)) {
			System.out.println("counter: " + counter);
			counter = 0;
		}
		System.out.println("total: " + (System.currentTimeMillis() - initTime));
	}

	static long counter = 0;
	static long initTime = System.currentTimeMillis();

	private static boolean instancia(LineReader r) throws Exception {

		if (r.nextLine().equals("0")) {
			return false;
		}

		int peoes = r.getInt(0);
		Tabuleiro inicial = new Tabuleiro();
		for (int i = 0; i != peoes; i++) {
			int peao = r.getInt(1 + i) - 1;
			inicial.peoes.add(new Point(peao % 8, peao / 8));
		}
		int cavalo = r.getInt(peoes + 1) - 1;
		inicial.cavalo = new Point(cavalo % 8, cavalo / 8);

		//System.out.println("\n\n\nnovo tabuleiro");
		//imprimeTabuleiro(inicial);

		// cria a fila de procura
		LinkedList fila = new LinkedList();
		fila.add(inicial);

		// programacao dinamica
		HashSet visitados = new HashSet();
		visitados.add(fila);

		AStarComparator comparador = new AStarComparator();

		while (fila.size() != 0) {

			// Tabuleiro t = (Tabuleiro) fila.removeLast();
			// a star
			Tabuleiro t = (Tabuleiro) Collections.min(fila, comparador);
			fila.remove(t);
			counter++;
			if (adicionaFilhos(t, fila, visitados)) {
				return true;
			}

		}

		System.out.println("impossible");

		return true;

	}

	/**
	* Se a posicao eh valida, ele adiciona cada tabuleiro filho valido
	*/
	private static boolean adicionaFilhos(
		Tabuleiro t,
		LinkedList fila,
		HashSet visitados) {

		if (t.cavalo.x != 0
			&& t.cavalo.y > 1
			&& adicionaFilho(t, fila, -1, -2, visitados))
			return true;
		if (t.cavalo.x != 7
			&& t.cavalo.y > 1
			&& adicionaFilho(t, fila, 1, -2, visitados))
			return true;
		if (t.cavalo.x < 6
			&& t.cavalo.y != 0
			&& adicionaFilho(t, fila, 2, -1, visitados))
			return true;
		if (t.cavalo.x < 6
			&& t.cavalo.y != 7
			&& adicionaFilho(t, fila, 2, 1, visitados))
			return true;
		if (t.cavalo.x != 7
			&& t.cavalo.y < 6
			&& adicionaFilho(t, fila, 1, 2, visitados))
			return true;
		if (t.cavalo.x != 0
			&& t.cavalo.y < 6
			&& adicionaFilho(t, fila, -1, 2, visitados))
			return true;
		if (t.cavalo.x > 1
			&& t.cavalo.y != 7
			&& adicionaFilho(t, fila, -2, 1, visitados))
			return true;
		if (t.cavalo.x > 1
			&& t.cavalo.y != 0
			&& adicionaFilho(t, fila, -2, -1, visitados))
			return true;

		return false;

	}

	private static boolean adicionaFilho(
		Tabuleiro t,
		LinkedList fila,
		int dx,
		int dy,
		HashSet visitados) {

		Tabuleiro novo = copia(t, dx, dy);
		if (novo != null) {
			// tabuleiro aceito
			if (novo.peoes.size() == 0) {
				System.out.println("" + novo.movimentosPassados);
				return true;
			}
			// programacao dinamica
			if (!visitados.contains(novo)) {
				fila.add(novo);
				visitados.add(novo);
			}
		}

		return false;

	}

	/**
	 * Copia um tabuleiro e move o cavalo
	 * @return Um novo tabuleiro
	 */
	private static Tabuleiro copia(Tabuleiro t, int dx, int dy) {
		Tabuleiro n = new Tabuleiro();
		n.cavalo = new Point(t.cavalo.x + dx, t.cavalo.y + dy);
		// copia os peoes
		int miny = 0;
		for (Iterator it = t.peoes.iterator(); it.hasNext();) {
			Point p = (Point) it.next();
			// se o ponto for o mesmo do cavalo, ignora o peao
			if (!p.equals(n.cavalo)) {
				// se esta no fim, ignora, falhou
				if (p.y == 7) {
					return null;
				}
				Point np = new Point(p.x, p.y + 1);
				// se o peao come o cavalo, para agora e ignora o tabuleiro
				if (n.cavalo.equals(np)) {
					return null;
				}
				// calcula o novo miny
				if (miny > np.y) {
					miny = np.y;
				}
				n.peoes.add(np);
			}
		}
		// pruna o rapaz se existiram peoes demais
		if (n.peoes.size() > 8 - miny) {
			return null;
		}
		n.movimentosPassados = t.movimentosPassados + 1;
		return n;
	}

	private static void imprimeTabuleiro(Tabuleiro inicial) {
		System.out.println("cavalo: " + inicial.cavalo);
		System.out.println("movimentos: " + inicial.movimentosPassados);
		for (Iterator it = inicial.peoes.iterator(); it.hasNext();) {
			System.out.println(it.next());
		}
	}

}

// largura 5928, 2586 no de 6
// programacao dinamica 3936, 786 no de 6
// astar 25, 240 no de 6

class Tabuleiro {
	HashSet peoes = new HashSet();
	Point cavalo;
	int movimentosPassados = 0;
	public boolean equals(Object o) {
		Tabuleiro t = (Tabuleiro) o;
		if (peoes.equals(t.peoes) && cavalo.equals(t.cavalo)) {
			return true;
		}
		return false;
	}
	public int hashCode() {
		return peoes.hashCode() + cavalo.hashCode();
	}
}

class AStarComparator implements Comparator {

	public int compare(Object arg0, Object arg1) {
		Tabuleiro t1 = (Tabuleiro) arg0;
		Tabuleiro t2 = (Tabuleiro) arg1;
		if (t1.movimentosPassados + t1.peoes.size()
			< t2.movimentosPassados + t2.peoes.size()) {
			return -1;
		}
		if (t1.movimentosPassados + t1.peoes.size()
			> t2.movimentosPassados + t2.peoes.size()) {
			return 1;
		}
		return 0;
	}

}

class LineReader {
	String str;
	String buffer[];
	BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
	void setFile(String s) throws Exception {
		r = new BufferedReader(new FileReader(s));
	}
	public int getInt(int i) {
		return Integer.parseInt(buffer[i]);
	}
	String nextLine() throws IOException {
		str = r.readLine();
		if (str == null) {
			buffer = new String[0];
		} else {
			buffer = str.split("\\s");
		}
		return str;
	}
}