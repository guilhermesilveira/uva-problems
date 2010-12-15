
import java.io.IOException;
import java.util.StringTokenizer;

class Main {

    static int maxW, maxH;

    static Linha l[];

    static int lines;

    static int maxP;

    public static boolean verifica(int points) {
        if (points == 8) {
            return false;
        } else {
            return tenta(points - 1);
        }
    }

    public static boolean tenta(int points) {

        int curH = lines * points;

        if (curH > maxH) {
            return verifica(points);
        }

        int mh = maxH / points, mmw = maxW / points;
        mh -= lines;

        for (int i = 0; i != lines; i++) {
            // nao coube, tenta quebrar
            int mw = mmw;
            for (int k = 0; k < l[i].n; k++) {
                // tiro de mw o tamanho da palavra
                if (l[i].len[k] > mmw) {
                    return verifica(points);
                } else if (mw == mmw) {
                    // primeira palavra, pode tirar ela
                    mw -= l[i].len[k];
                } else if (mw < (l[i].len[k] + 1)) {
                    // espaco + palavra.... nova linha
                    mw = (mmw) - (l[i].len[k]);
                    mh--;
                    if (mh < 0) {
                        return verifica(points);
                    }
                } else {
                    // espaco + palavra, retirando
                    mw -= (l[i].len[k] + 1);
                }
            }
            if (mh < 0)
                return verifica(points);
            // foi possivel.... :)
        }

        if (maxP < points) {
            maxP = points;
        }

        return true;

    }

    public static void novo() {

        lines = Integer.parseInt(readLine(100).trim());
        l = new Linha[lines];
        for (int i = 0; i != lines; i++) {
            l[i] = new Linha(readLine(10000).trim());
        }
        int z[] = parseIntLine();
        maxW = z[0];
        maxH = z[1];

        // vamos tentar com a menor fonte possivel, se nao couber sabemos que eh
        // impossivel
        if (lines * 8 > maxH || !tenta(8)) {
            System.out.println("No solution");
        } else {
            maxP = 8;
            if (!tenta(28)) {
                System.out.println("No solution");
            } else {
                System.out.println(maxP);
            }
        }

    }

    public static void main(String args[]) {
        try {
            int c = Integer.parseInt(readLine(10).trim());
            while (c-- != 0) {
                novo();
            }
        } catch (Exception e) {
            while (true)
                ;
        }
    }

    public static String[] parseNewLine() {
        String l = readLine(10000).trim();
        StringTokenizer st = new StringTokenizer(l);
        String[] s = new String[st.countTokens()];
        int i = 0;
        while (st.hasMoreTokens()) {
            s[i++] = st.nextToken();
        }
        return s;
    }

    public static String[] parseLine(String l) {
        StringTokenizer st = new StringTokenizer(l);
        String[] s = new String[st.countTokens()];
        int i = 0;
        while (st.hasMoreTokens()) {
            s[i++] = st.nextToken();
        }
        return s;
    }

    public static int[] parseIntLine() {
        String l = readLine(10000).trim();
        StringTokenizer st = new StringTokenizer(l);
        int[] s = new int[st.countTokens()];
        int i = 0;
        while (st.hasMoreTokens()) {
            s[i++] = Integer.parseInt(st.nextToken().trim());
        }
        return s;
    }

    static String readLine(int maxLg) // utility function to read from stdin
    {
        byte lin[] = new byte[maxLg];
        int lg = 0, car = -1;
        String line = "";

        try {
            while (lg < maxLg) {
                car = System.in.read();
                if ((car < 0) || (car == '\n'))
                    break;
                lin[lg++] += car;
            }
        } catch (IOException e) {
            return (null);
        }

        if ((car < 0) && (lg == 0))
            return (null); // eof
        return (new String(lin, 0, lg));
    }

}

class Linha {

    String val;

    String s[];

    int len[];

    int n;

    int l;

    int ml = 0;

    Linha(String v) {
        val = v.trim();
        l = val.length();
        s = Main.parseLine(val);
        n = s.length;
        len = new int[n];
        for (int i = 0; i != n; i++) {
            s[i] = s[i].trim();
            if (ml < s[i].length()) {
                ml = s[i].length();
            }
            len[i] = s[i].length();
        }
    }
}

