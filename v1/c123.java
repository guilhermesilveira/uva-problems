import java.io.*;
import java.util.*;

public class Main {

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		sc.useDelimiter("\\n");
		Set<String> ig = new HashSet<String>();
		while(true) {
			String l = sc.read();
			if("::".equals(l)) break;
			ig.add(l.toLowerCase());
		}
		List<V> lista = new ArrayList<V>();
		while(true) {
			String l = sc.read();
			if(l==null) break;
			pal = l.split("\\s+");
			
		}
	}

}

class V {
	V(String a,int b,int c) { s=a;p1=b;p2=c;}
	String s; int p1, p2;
}
