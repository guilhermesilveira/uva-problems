// 39315

import java.io.IOException;
import java.text.ParseException;
import java.util.StringTokenizer;

class Main {

	static String buffer[];
	static int m;
	static int n;
	static String word;
	static int wordSize;

	public static void main(String[] args) throws IOException, ParseException {

		int cases = Integer.parseInt(readLine(10));

		while (cases-- > 0) {

			// le a linha em branco
			readLine(10);

			int[] base = breakLineInt(readLine(40));
			 m = base[0];
			n = base[1];

			buffer = new String[m];

			for (int i = 0; i != m; i++) {
				// le uma linha inteira
				buffer[i] = readLine(n + 10).toLowerCase();
				//System.out.println(buffer[i]);
			}

			int size = Integer.parseInt(readLine(5));

			for (int i = 0; i != size; i++) {
				word = readLine(500).toLowerCase();
				// procura uma palavra
				procuraWord();
			}
			
			if(cases!=0) {
				System.out.println();
			}

		}

	}

	private static void procuraWord() {
		
		//System.out.println("procurando: " + word);

		wordSize = word.length();

		// para cada caracter da linha
		for (int l = 0; l != m; l++) {

			horizonte: for (int i = 0; i != n; i++) {

				// de frente pra tras
				if (n - wordSize > i-1 && verifica(l,i,0,1)) return;
				
				// de tras pra frente
				if((i >= wordSize-1) && verifica(l,i,0,-1)) return;
				
				// de cima pra baixo
				if(m - wordSize > l-1) {
					if(verifica(l,i,1,0)) return;
					if(n - wordSize > i-1 && verifica(l,i,1,1)) return;
					if(i >= wordSize-1 && verifica(l,i,1,-1)) return;
				}

				// testar de ponta cabeca
				if(l >= wordSize-1) {
					if(verifica(l,i,-1,0)) return;
					if (n - wordSize > i-1 && verifica(l,i,-1,1)) return;
					if (i >= wordSize-1 && verifica(l,i,-1,-1)) return;
				}
				
			}

		}

	}

	static boolean verifica(int l,int i,int a,int b) {
		for(int kn=0;kn!=wordSize;kn++) {
			if(buffer[l+kn*a].charAt(i+kn*b)!=word.charAt(kn)) {
				return false;
			}
			//System.out.print(buffer[l+kn*a].charAt(i+kn*b));
		}
		//System.out.println();
		System.out.println((l + 1) + " " + (i + 1));
		return true;
	}
					
	static int[] breakLineInt(String s) {
		StringTokenizer st = new StringTokenizer(s, " ");
		int[] tokens = new int[st.countTokens()];
		for (int i = 0; i != tokens.length; i++) {
			tokens[i] = Integer.parseInt(st.nextToken());
		}
		return tokens;
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
