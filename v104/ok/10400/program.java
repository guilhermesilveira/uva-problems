

import java.io.IOException;
import java.util.StringTokenizer;

class Main {

    static int maxLg = 200;

    static int max;

    static int result;

    static int linha[];

    static char signals[];

    static boolean backtrack(long currentVal, int level) {
        if (level == max) {
            return currentVal == result;
        }
        if (currentVal + linha[level] < 32000
                && backtrack(currentVal + linha[level], level + 1)) {
            signals[level - 2] = '+';
            return true;
        }
        if (currentVal - linha[level] > -32000
                && backtrack(currentVal - linha[level], level + 1)) {
            signals[level - 2] = '-';
            return true;
        }
        if (Math.abs(currentVal * linha[level]) < 32000 && Math.abs(currentVal * linha[level]) > -32000
                && backtrack(currentVal * linha[level], level + 1)) {
            signals[level - 2] = '*';
            return true;
        }
        if (currentVal % linha[level] == 0
                && backtrack(currentVal / linha[level], level + 1)) {
            signals[level - 2] = '/';
            return true;
        }
        return false;
    }

    public static void main(String args[]) throws Exception {

        int cases = Integer.parseInt(readLine().trim());

        signals = new char[101];

        while (cases-- != 0) {

            linha = splitIntLine(readLine());

            max = linha[0] + 1;
            result = linha[max];

            if (backtrack(linha[1], 2)) {
                for (int i = 0; i != max - 2; i++) {
                    System.out.print(linha[i + 1] + "" + signals[i]);
                }
                System.out.println(linha[max - 1] + "=" + result);
            } else {
                System.out.println("NO EXPRESSION");
            }
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

    static int[] splitIntLine(String s) {
        String[] l = split(s.trim());
        int v[] = new int[l.length];
        for (int i = 0; i != l.length; i++) {
            v[i] = Integer.parseInt(l[i]);
        }
        return v;
    }

}