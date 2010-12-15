import java.util.StringTokenizer;
import java.io.IOException;

class Main {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {
    try{
    	int c = Integer.parseInt(readLine().trim());
    	while(c--!=0) start();}catch(Exception ex) {while(true);}
    }
    
    static long holes[] = new long[30];
    static long val[] = new long[30];
    static long vz[] = new long[30];
	static boolean usado[] = new boolean[30];
    static int pos[] = new int[30];
    static int fim[] = new int[30];
    static int h;
    static int a = (int) 'A';
    static int z = (int) 'Z';
    
    static char car(int i) {
    	return (char) (i + a);
    }
    
    static int caca(long v) {
    	int u;
		// vou cacar o primeiro cara com esse valor disponivel
		for(int j=0;j!=h;j++) {
			if(val[j]==v && !usado[j]) {
				return j;
			}
		}
		while(true);
		//return -1;
    }

    static int cacaTras(long v) {
    	int u;
		// vou cacar o primeiro cara com esse valor disponivel
		for(int j=h-1;j!=-1;j--) {
			if(val[j]==v && !usado[j]) {
				return j;
			}
		}
		while(true);
		//return -1;
    }

    public static void start() throws Exception {
    	h = Integer.parseInt(readLine().trim());
    	for(int i=0;i!=h;i++) {
    		holes[i]=0;
    		usado[i] = false;
    	}
    	String s = readLine().trim();
    	int c;
    	for(int i=s.length()-1;i!=-1;i--) {
    		c = ((int)s.charAt(i));
    		if(c>=a && c<=z) holes[c-a]++;
    	}
    	long ultimoMaior;
    	int u = 0;
    	for(int im=0;im!=h;im++) {
    		ultimoMaior = -1;
    		for(int i=0;i!=h;i++) {
    			if(ultimoMaior==-1 || holes[i]>=ultimoMaior) {
    				ultimoMaior = holes[i];
    				u = i;
    			}
    		}
    		pos[im] = u;
    		val[u] = holes[u];
    		holes[u] = -1;
    	}
    	
    	int st = 0;
    	int e = h-1;
    	long a1,a2;
    	for(int i=0;i!=h;) {
    		if(i==h-1) {
    			//System.out.println("adicionando: " + (char)(caca(val[pos[i]])+a));
    			fim[st++] = caca(val[pos[i]]);
	    		i++;
	    		break;
    		}
    		//System.out.println(car(pos[i]) + " e " +car(pos[i+1]));
    		int cacaI1 = caca(val[pos[i]]);
    		int cacaI2 = caca(val[pos[i+1]]);
    		if(cacaI1<cacaI2) {
    			cacaI2 = cacaTras(val[pos[i+1]]);
    			fim[st++] = cacaI1;
    			fim[e--] = cacaI2;
    		} else {
    			cacaI1 = cacaTras(val[pos[i]]);
    			fim[st++] = cacaI2;
    			fim[e--] = cacaI1;
    		}
   			usado[cacaI1] = true;
   			usado[cacaI2] = true;
    		i+=2;
    	}
    	
    	for(int i=0;i!=h;i++) {
    		System.out.print((char)(fim[i] + a));
    		if(i!=h-1) System.out.print(" ");
    	}
    	System.out.println();
    	for(int i=0;i!=h;i++) {
    		System.out.print(val[fim[i]]);
    		if(i!=h-1) System.out.print(" ");
    	}
    	System.out.println();
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

    static long[] splitLongLine(String s) {
        String[] l = split(s);
        long v[] = new long[l.length];
        for (int i = 0; i != l.length; i++) {
            v[i] = Long.valueOf(l[i]).longValue();
        }
        return v;
    }

}
