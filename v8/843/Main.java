import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;

class Main {

	static Set list = new HashSet();
	static String[] codes;
	static HashMap mapaDePalavras = new HashMap();

	public static void main(String args[]) throws Exception {

		BufferedReader reader =
			new BufferedReader(new InputStreamReader(System.in));
		int words = Integer.parseInt(reader.readLine());
		for (int i = 0; i != words; i++) {
			list.add(reader.readLine());
		}
		/*for(int i=0;i!=words;i++) {
			System.out.println(list.get(i));
		}*/

		String line;
		while ((line = reader.readLine()) != null) {
			for(int i=0;i!=260;i++) {
				map[i] = 0;
			}
			mapaDePalavras.clear();
			codes = split(line);
			if (!executaPara(0)) {
				for(int q =0;q!=codes.length;q++) {
					for(int w=0;w!=codes[q].length();w++) {
						System.out.print("*");
					}
					if(q!=codes.length-1) {
						System.out.print(" ");
					}
				}
				System.out.println();
			}
		}

	}

	/**
	 * @param codes
	 * @param i	palavra que ele deve comecar
	 */
	private static boolean executaPara(int i) {

		if (i == codes.length) {
			// achou o caso, imprime
			for(int q =0;q!=codes.length;q++) {
				System.out.print(mapaDePalavras.get(codes[q]));
				if(q!=codes.length-1) {
					System.out.print(" ");
				}
			}
			System.out.println();
			return true;
		}

		String p = codes[i];
		int pLength = p.length();
		
		if(mapaDePalavras.containsKey(p)) {
			if(executaPara(i + 1)) return true;
			return false;
		}


		// para cada palavra que match o tamanho
		for (Iterator z = list.iterator(); z.hasNext(); ) {
			String c = (String) z.next();

			if (c.length() == pLength) {

				ArrayList lista = new ArrayList();
				boolean valid = true;
				// verifica se essa palavra eh valida
				for (int charCount = 0; charCount != pLength; charCount++) {

					if (map[p.charAt(charCount)] == 0) {
						// adiciona
						lista.add(p.charAt(charCount) + "");
						map[p.charAt(charCount)] = c.charAt(charCount);
					} else if (
						map[p.charAt(charCount)] != c.charAt(charCount)) {
						// invalido, para
						valid = false;
						break;
					}

				}

				if (valid) {
					mapaDePalavras.put(p,c);
					if(executaPara(i + 1)) return true;
					mapaDePalavras.remove(p);
				}

				// limpo
				for (int x = 0; x != lista.size(); x++) {
					map[((String)lista.get(x)).charAt(0)] = 0;
				}

			}
		}
		return false;

	}

	static char[] map = new char[300];

	public static String[] split(String s) {
		StringTokenizer tokens = new StringTokenizer(s, " ");
		String[] list = new String[tokens.countTokens()];
		for (int i = 0; i != list.length; i++) {
			list[i] = tokens.nextToken();
		}
		return list;
	}

}
