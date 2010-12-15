import java.util.StringTokenizer;
import java.io.IOException;

class Main {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {
        String line;
        long b,a,parsed[];
        double d;
        while ((line = readLine()) != null) {
            parsed = splitLongLine(line.trim());
            if(parsed[0]==0 && parsed[1]==0 && parsed.length==2) return;
            if(parsed[2]>1000000) while(true);
        //    d = Math.sqrt(0.0 + parsed[0]*parsed[0]-4*parsed[1]);
            //if(d>=0) {
                //b = (long) ((parsed[0] + d) / 2);
            	//a = (long) ((parsed[0] - d) / 2);
            	//System.out.println((long) (Math.pow(a,parsed[2])+Math.pow(b,parsed[2])));
            //} else {
            	start(parsed[0],parsed[1],parsed[2]);  
            //}
        }
    }

    static long s; 
    static long m;
    static long t[] = new long[1000000];

    public static double comeca(long n) {
        return (comeca(n-1))*(s) - (m) * (comeca(n-2));
    }

    public static void start(long ss,long mm,long n) {
        s = ss;
        m = mm;
        //System.out.println(comeca(n));
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

class BigNum {

    static final int MAX = 1000;

    static final long QUOTE = 100000;

    static final int QUOTE_SIZE = 5;

    static BigNum ONE = new BigNum(1);

    static BigNum ZERO = new BigNum(0);

    int max = 0;

    long[] mag;

    BigNum(int i) {
        mag = new long[MAX];
        for (int z = 0; z != MAX; z++) {
            mag[z] = 0;
        }
        while (i != 0) {
            mag[max++] = i % QUOTE;
            i /= QUOTE;
        }
    }

    BigNum(String s) {
        this(0);
        s = s.trim();
        int size = s.length();
        int p = 0;
        for (; s.charAt(p) == 0 && p != size; p++)
            ;
        if (p == size) {
            return;
        }
        int i = size;
        String st;
        while (true) {
            if (i - p <= QUOTE_SIZE) {
                mag[max++] = Integer.parseInt(s.substring(p,i));
                break;
            }
            st = s.substring(i - QUOTE_SIZE, i);
            mag[max++] = Integer.parseInt(st);
            i -= QUOTE_SIZE;
        }
        if(mag[max-1]==0) {
        	max--;
        }
    }

    public BigNum multiply(int val) {
        BigNum a = new BigNum(this);
        long tempToAdd = 0;
        for (int i = 0; i != a.max; i++) {
            a.mag[i] *= val;
            a.mag[i] += tempToAdd;
            tempToAdd = 0;
            if (a.mag[i] >= QUOTE) {
                tempToAdd = (a.mag[i] / QUOTE);
                a.mag[i] = a.mag[i] % QUOTE;
                if (i + 1 == a.max) {
                    a.max++;
                }
            }
        }
        return a;
    }

    BigNum(BigNum b) {
        this.max = b.max;
        mag = new long[MAX];
        for (int z = 0; z != MAX; z++) {
            mag[z] = b.mag[z];
        }
    }

    BigNum add(BigNum b) {
    	long temp;
        BigNum th = this;
        if (th.max > b.max) {
            th = b;
            b = this;
        }
        BigNum a = new BigNum(th);
        a.max = b.max;
        for (int i = 0; i != b.max; i++) {
            temp = b.mag[i] + a.mag[i];
            if (temp >= QUOTE) {
                a.mag[i + 1]++;
                a.mag[i] = temp - QUOTE;
                if (i + 1 == a.max) {
                    a.max++;
                }
            } else {
	            a.mag[i] = temp;
            }
        }
        return a;
    }

    public String toString() {
        if (max == 0) {
            return "0";
        }
        StringBuffer s = new StringBuffer();
        long z, toAdd;
        for (int i = max; i > 0; i--) {
            if (i != max) {
                if (mag[i - 1] == 0) {
                    for (z = 0; z != QUOTE_SIZE; z++) {
                        s.append("0");
                    }
                    continue;
                }
                z = mag[i - 1];
                toAdd = QUOTE_SIZE;
                while (z != 0) {
                    z /= 10;
                    toAdd--;
                }
                // se nao for o primeiro objeto
                while (toAdd-- != 0) {
                    s.append("0");
                }
            }
            s.append("" + mag[i - 1]);
        }
        return s.toString();
    }

}

