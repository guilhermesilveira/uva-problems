
import java.io.IOException;
import java.util.StringTokenizer;

class Main {

    static int maxLg = 200;

    static BigNum tres[] = new BigNum[2000];
    static BigNum doisPot[] = new BigNum[2000];

    static int posi = 0;

    static int posb[] = new int[2000];

    public static void main(String args[]) throws Exception {
        String s;
        tres[0] = BigNum.ONE;
        tres[1] = new BigNum(3);
        doisPot[0] = BigNum.TWO;
        doisPot[1] = new BigNum(2);
        for (int i = 2; i != 1000; i++) {
            tres[i] = tres[i - 1].multiply(3);
            doisPot[i] = doisPot[i - 1].multiply(2);
        }
        while ((s = readLine()) != null) {
            s = s.trim();
            if (s.equals("1")) {
                System.out.println("{ }");
                continue;
            } else if (s.equals("2")) {
                System.out.println("{ 1 }");
                continue;
            } else if (s.equals("0")) {
                return;
            }
            BigNum b = new BigNum(s);
            System.out.print("{");
            posi = 0;
            tenta(b);
            for (int i = 0; i != posi; i++) {
                if (i != 0) {
                    System.out.print(", " + tres[posb[i]]);
                } else {
                    System.out.print(" " + tres[posb[i]]);
                }
            }
            System.out.println(" }");
        }
    }

    private static void tenta(BigNum b) {
        if (b.equals(BigNum.ONE)) {
            return;
        } else if (b.equals(BigNum.ZERO)) {
            return;
        } else if (b.equals(BigNum.TWO)) {
            posb[posi++] = 0;
            return;
        }
        int aelevar = 1;
        int antigo = -1;
        int doisElevadoAoUltimo = 0;
        BigNum val = new BigNum(2);
        while (val.compareTo(b) < 0) {
            aelevar++;
            antigo = doisElevadoAoUltimo;
            doisElevadoAoUltimo++;
            val = val.add(doisPot[doisElevadoAoUltimo]);
        }
        BigNum c =b.menos(doisPot[doisElevadoAoUltimo]);
        if(c.compareTo(b)>0) {
            System.exit(0);
        }
        tenta(c);
        posb[posi++] = aelevar-1;
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
    
    String my;

    static final int MAX = 1000;

    static final long QUOTE = 100000;

    static final int QUOTE_SIZE = 5;

    static BigNum ONE = new BigNum(1);

    static BigNum ZERO = new BigNum(0);

    static BigNum TWO = new BigNum(2);

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
        this.my = calcString();
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
                mag[max++] = Integer.parseInt(s.substring(p, i));
                break;
            }
            st = s.substring(i - QUOTE_SIZE, i);
            mag[max++] = Integer.parseInt(st);
            i -= QUOTE_SIZE;
        }
        if (mag[max - 1] == 0) {
            max--;
        }
        this.my = calcString();
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
        a.calcString();
        return a;
    }

    public BigNum(BigNum b) {
        this.max = b.max;
        mag = new long[MAX];
        for (int z = 0; z != MAX; z++) {
            mag[z] = b.mag[z];
        }
        this.my = calcString();
    }

    public BigNum add(BigNum b) {
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
        a.calcString();
        return a;
    }

    public BigNum menos(BigNum b) {
        long temp;
        BigNum th = this;
        BigNum a = new BigNum(th);
        a.max = this.max;
        for (int i = b.max - 1; i != -1; i--) {
            temp = a.mag[i] - b.mag[i];
            if (temp < 0) {
                a.mag[i + 1] -= 1;
                temp += QUOTE;
                a.mag[i] = temp;
            } else {
                a.mag[i] = temp;
            }
        }
        for (int i = a.max - 1; i != -1; i--) {
            if (a.mag[i] == 0) {
                a.max--;
            } else {
                break;
            }
        }
        a.calcString();
        return a;
    }

    public String calcString() {
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
        this.my = s.toString();
        return this.my;
    }

    public boolean equals(Object o) {
        BigNum b = (BigNum) o;
        return (this.toString().trim().equals(b.toString().trim()));
    }

    //public boolean maiorQue(BigNum b) {
    //    return this.toString().trim().compareTo(b.toString().trim()) > 0;
    //}

    public int compareTo(BigNum b) {
        String s1 = this.toString().trim();
        String s2 = b.toString().trim();
        int l1 = s1.length();
        int l2 = s2.length();
        if (l1 != l2) {
            return (l1 < l2 ? -1 : 1);
        }
        for (int i = 0; i != l1; i++) {
            if (s1.charAt(i) < s2.charAt(i)) {
                return -1;
            } else if (s1.charAt(i) > s2.charAt(i)) {
                return 1;
            }
        }
        return 0;
    }
    
    public String toString() {
        if(this.my==null) {
            calcString();
        }
        return this.my;
    }

}

