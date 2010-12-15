import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

class Main {

	HashMap mapa = new HashMap();

	public BigInteger makeSolution(int parenteses,int depthToGo,int maxDepth, int depth) {

		for(int i=0;i!=depth;i++) { System.out.print(" "); }
		System.out.println(parenteses + "," + depthToGo);
		
		if(parenteses==0) return BigInteger.ZERO;
		
		if(depth==maxDepth) {
			return BigInteger.ONE;
		}

		/*if(depthToGo==1) {
			for(int i=0;i!=depth;i++) { System.out.print(" "); }
			System.out.println("[1]");
			return BigInteger.ONE;
		}

		if(parenteses==1) {
			for(int i=0;i!=depth;i++) { System.out.print(" "); }
			System.out.println("[0]");
			return BigInteger.ZERO;
		}

		if(depthToGo==parenteses) {
			for(int i=0;i!=depth;i++) { System.out.print(" "); }
			System.out.println("[1]");
			return BigInteger.ONE;
		}*/

		BigInteger temp = BigInteger.ZERO;
		for(int i=0; i<=parenteses; i++) {
		
			if(mapa.containsKey(i + "," + parenteses + "," + depth)) {
				temp = temp.add((BigInteger) mapa.get(i + "," + parenteses + "," + depth));
			}

			// tento colocar i dentro e parenteses - i a direita
			//System.out.println("tenta com + "+i+"/"+ (depthToGo-1) + " e " + (parenteses-1) + "/" + depthToGo);
			BigInteger t1 = (i==0) ? BigInteger.ONE : makeSolution(i, depthToGo-1, maxDepth, depth+1);
			BigInteger t2 = (i==parenteses) ? BigInteger.ONE : makeSolution(parenteses-i, depthToGo, maxDepth, depth+1);

			t1 = t1.multiply(t2);
			mapa.put(i + "," + parenteses + "," + depth,t1);

			/*if(t1!=BigInteger.ZERO) {
				System.out.println(t1 + " com " + i +"/" + (parenteses-i));
			}*/

			temp = temp.add(t1);

		}

		return temp;

	}

	public void start(String args[]) {

		int parenteses = Integer.parseInt(args[0]);
		int maxDepth = Integer.parseInt(args[1]);
		System.out.println(parenteses + "] [" + maxDepth);
		
		if((parenteses & 1)==1) {
			System.out.println("0");
			return;
		}

		BigInteger max = makeSolution((parenteses/2)-1,maxDepth-1,maxDepth, 1);
		System.out.println("Max: " + max + "\n\n");
	
	}

	public static void main(String args[]) throws IOException {
		String l;
		while((l=readLine(100))!=null) {
			if(!l.trim().equals("")) {
				new Main().start(split(l));
			}
			break;
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
