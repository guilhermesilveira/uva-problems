
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

class Main {

    static int maxLg = 20000;

    static double precos[][] = new double[100010][2];

    static void start(int l, int tot) throws IOException {
        int lista[] = parseIntLine();
        String s[];
        for (int i = 0; i != tot; i++) {
            s = split(readLine().trim());
            if(s.length!=2) return;
            precos[i][0] = Double.valueOf(s[0]).doubleValue();
            precos[i][1] = Double.valueOf(s[1]).doubleValue();
        }
        if(true) return;
        tenta(l, tot, lista);
    }

    static void tenta(int l, int tot, int[] lista) throws IOException {
        double como[] = new double[l];
        for (int i = 0; i != l; i++)
            como[i] = -1;
        for (int i = 0; i != tot; i++) {
            for (int j = l - 1; j > 0; j--) {
                if (lista[j] == precos[i][0] && como[j - 1] != -1) {
                    // se eh possivel chegar no anterior
                    if (como[j] == -1 || como[j] > como[j - 1] + precos[i][1]) {
                        // se eh mais barato entao marca
                        como[j] = como[j - 1] + precos[i][1];
                    }
                }
            }
            if (lista[0] == precos[i][0]) {
                if (como[0] == -1 || como[0] < precos[i][1])
                    como[0] = precos[i][1];
            }
        }
        if (como[l - 1] == -1) {
            System.out.println("Impossible");
        } else {
            /*double t = como[l - 1];
            t *= 100;
            //System.out.println(t);
            t = Math.round(t);
            //System.out.println(t);
            long z = (long) t;
            z = z % 100;
            System.out.println((long)(t / 100) + "." + z);*/
        }
    }

    public static void main(String args[]) {

        try {
            while (true) {
                int[] l = parseIntLine();
                if(l.length!=2) return;
                if (l[0] == 0 && l[1] == 0)
                    return;
                start(l[0], l[1]);
            }
        } catch (RuntimeException e) {
        } catch (IOException e) {
        } catch (Exception e) {
            while(true);
        }
    }

    static int[] parseIntLine() throws IOException {
        String s[] = split(readLine().trim());
        int[] z = new int[s.length];
        for (int i = 0; i != z.length; i++) {
            z[i] = Integer.parseInt(s[i]);
        }
        return z;
    }

    static String[] split(String s) {
        StringTokenizer st = new StringTokenizer(s.trim(), " ");
        String[] tokens = new String[st.countTokens()];
        for (int i = 0; i != tokens.length; i++) {
            tokens[i] = st.nextToken();
        }
        return tokens;
    }

    //     le uma linha inteira
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