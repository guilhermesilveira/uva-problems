import java.util.*;
import java.io.*;
import java.text.*;

class Main {

	public static void main(String args[]) throws IOException {
	
		int casos = Integer.parseInt(readLine(100));
		while(casos--!=0) {
		
			String l = readLine(2000);
			if(l.trim().equals("")) continue;
			String[] line = split(l);
			double vizinhos = Integer.parseInt(line[0]);
			//double vizinhosOficiais = 0;
			long soma = 0;

			Vector relativos = new Vector();
			for(int i=0;i!=vizinhos;i++) {
				int temp = Integer.parseInt(line[i+1]);
				//if(!relativos.contains(new Integer(temp))) {
					relativos.addElement(new Integer(temp));
				//}
				soma += temp;
			}

			// divide soma por vizinhos
			double media = (soma *1.0) / vizinhos;
			long mediana = 0;
			double menorDist = 9999999;
			for(int i=0;i!=vizinhos;i++) {
				if(Math.abs(((Integer)relativos.elementAt(i)).intValue() - media)<menorDist) {
					menorDist = Math.abs(((Integer)relativos.elementAt(i)).intValue() - media);
					mediana = ((Integer)relativos.elementAt(i)).intValue();
				}
			}

			soma = 0;
			for(int i=0;i!=vizinhos;i++) {
				soma += Math.abs(((Integer)relativos.elementAt(i)).intValue() - mediana);
			}

			System.out.println(soma);

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
