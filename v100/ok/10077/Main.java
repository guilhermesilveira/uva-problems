
import java.io.IOException;
import java.util.StringTokenizer;

class Main {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {

        String s = "";
        long[] k = new long[2];
        while (true) {
            s = readLine();
            if (s == null) {
                break;
            }
            k = splitLongLine(s.trim());
            if (k[0] == 1 && k[1] == 1)
                return; 
            tenta(k[0], k[1], 0, 1, 1, 0);
            System.out.println();
        }

    }

    private static void tenta(long l, long r, long a, long b, long c, long d) {
        if (l == a + c && r == b + d)
            return;
        if (l * (b + d) < r * (a + c)) {
            System.out.print("L");
            tenta(l, r, a, b, c + a, d + b);
        } else {
            System.out.print("R");
            tenta(l, r, a + c, b + d, c, d);
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

    static long[] splitLongLine(String s) {
        String[] l = split(s);
        long v[] = new long[l.length];
        for (int i = 0; i != l.length; i++) {
            v[i] = Long.valueOf(l[i]).longValue();
        }
        return v;
    }

}