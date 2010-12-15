import java.util.*;
import java.text.*;
import java.io.*;

class Main {

   void start(int k,String str) {

       //      System.out.println(str);
       StringTokenizer st = new StringTokenizer(str.trim());
       int[] tok = new int[st.countTokens()];
       int i = 0, len = st.countTokens();
       while(st.hasMoreElements()) {
           tok[i++] = Integer.parseInt(((String) st.nextElement()).trim());
       }
       System.out.print("q(x):");
       if(len==1) System.out.print(" 0");
       else {
       for(i=0;i<len-1;i++) {
           System.out.print(" " + tok[i]);
           int v = tok[i] * k;
           tok[i+1] += v;
       }
       }
       System.out.println("\nr = " + tok[len-1]);
   }

public static void main(String args[]) throws Exception {

   String str;

       while((str = readLine())!=null) {
           //    System.out.println("st");

               new Main().start(Integer.parseInt(str.trim()),readLine());
               System.out.println();

       }

}

	static   int maxLg = 100000;
    static byte lin[] = new byte[100000];
	static String readLine() throws IOException {
	    int lg = 0, car = -1;
	    while (lg < maxLg) {
	        car = System.in.read();
	        if ((car < 0) || (car == '\n')) {
	            break;
	        }
	        lin[lg++] = (byte) (0 + car);
	    }
	    if ((car < 0) && (lg == 0)) {
	        return null; // eof
	    }
	    return (new String(lin, 0, lg));
	}
}


