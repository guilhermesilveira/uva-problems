

import java.util.*;
import java.io.*;

class Main {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {
        int v[] = new int[1000];
        int vc, lv;
        while (true) {
            long l = Long.valueOf(readLine().trim()).longValue();
            if (l == 0)
                return;
            //System.out.println(l + "numeros");
            vc = 0;
            lv = 0;
            for (int i = 0; i != l; i++) {
                v[vc] = Integer.parseInt(readLine().trim());
                if (v[vc] != 0) {
                    vc++;
                    lv = vc;
                }
            }
            if(vc==0) {
                System.out.println("0");
                continue;
            }
            String s = "";
            for (int i = 0; i < vc; i++) {
                s += v[i] + " ";
            }
            System.out.println(s);
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