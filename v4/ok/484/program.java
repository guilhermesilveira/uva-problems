import java.util.*;
import java.io.*;
import java.text.*;

class Main {

	static int maxLg = 200;

	public static void main(String args[]) throws Exception {
	
		/*String line;
		while((line = readLine())!=null) {
			String[] parsed = split(line);
		}*/

		/*int casos = readIntLine();
		
		for(int i=0;i!=casos;i++) {
		
			if(i!=0) System.out.println();
			System.out.println("Case #" + i);
			
			
		}*/
	
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
	static String readLine() throws IOException {

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
	
	static int readIntLine() throws IOException {
		return Integer.parseInt(readLine());
	}

	static int[] splitIntLine() throws IOException {
		String[] l = split(readLine());
		int v[] = new int[l.length];
		for(int i=0;i!=l.length;i++) {
			v[i] = Integer.parseInt(l[i]);
		}
		return v;
	}

}

class IntegerVector extends SortedVector {

	public IntegerVector(int max) {
		super(max);
	}

	public int compare(Object o1,Object o2) {
		return ((Integer)o2).compareTo((Integer) o1);
	}
	
	public int getInt(int i) {
		return ((Integer) get(i)).intValue();
	}

}

abstract class SortedVector {

	private int count = 0;
	private int maxSize = 0;
	private Object[] v;

	public SortedVector(int maxSize) {
		this.v = new Object[maxSize];
		this.maxSize = maxSize;
	}

	public void add(Object o) {
		for(int i=0;i!=count;i++) {
			if(compare(this.v[i],o)<=0) {
				int z = count;
				while(z > i) {
					v[z] = v[z - 1];
					z--;
				}
				v[i] = o;
				count++;
				return;
			}
		}
		this.v[count++] = o;
	}
	
	public void remove(int pos) {
		for(int p=pos; p != (count-1) ; p++) {
			v[p] = v[p+1];
		}
		count--;
	}

	public int size() {
		return this.count;
	}

	public Object get(int i) {
		return v[i];
	}
	
	public abstract int compare(Object o1,Object o2);

}
