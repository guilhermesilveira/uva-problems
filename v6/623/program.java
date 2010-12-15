

import java.io.IOException;
import java.util.StringTokenizer;

class Main {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {
        String line;
        BigNum fatorialDe[] = new BigNum[1010];
        BigNum total = BigNum.ONE;
        for (int i = 2; i != 1004; i++) {
            fatorialDe[i] = total = total.multiply(i);
        }
        while ((line = readLine()) != null) {
            line = line.trim();
            int i = Integer.parseInt(line);
            if (i == 0) {
                System.out.println("0!\n1");
                continue;
            } else if (i == 1) {
                System.out.println("1!\n1");
                continue;
            }
            System.out.println(i + "!");
            System.out.println(fatorialDe[i]);
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
}

class BigNum {

    static final int MAX = 1000;

    static final long QUOTE = 100000;

    static final long QUOTE_SIZE = 5;

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
        BigNum th = this;
        if (th.max > b.max) {
            th = b;
            b = this;
        }
        BigNum a = new BigNum(th);
        for (int i = 0; i != b.max; i++) {
            a.mag[i] += b.mag[i];
            if (a.mag[i] >= QUOTE) {
                a.mag[i + 1]++;
                a.mag[i] -= QUOTE;
                if (i + 1 == a.max) {
                    a.max++;
                }
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

