

import java.util.StringTokenizer;
import java.io.IOException;

class Main1 {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {
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