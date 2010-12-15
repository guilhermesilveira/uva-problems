
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

class No {

    Vector n = new Vector();

    int compareTo(No outro) {
        if (this.n.size() == outro.n.size()) {
            int k;
            for (int i = 0; i != n.size(); i++) {
                k = ((No) n.elementAt(i)).compareTo((No) outro.n.elementAt(i));
                if (k != 0)
                    return k;
            }
            return 0;
        }
        return this.n.size() - outro.n.size();
    }

    public boolean equals(Object o) {
        No no = (No) o;
        if (no.n.size() != this.n.size())
            return false;
        for (int i = 0; i != n.size(); i++) {
            if (!no.n.elementAt(i).equals(n.elementAt(i)))
                return false;
        }
        return true;
    }

}

class Arvore {

    Vector nos = new Vector();

    String code;

    long tot;

    No root;

    Arvore(long l[]) {
        int i;
        this.tot = l[0];
        for (i = 0; i != tot; i++) {
            No n = new No();
            nos.addElement(n);
        }
        for (i = 0; i != tot; i++) {
            int p = (int) l[i + 1];
            if (p == -1) {
                root = (No) nos.elementAt(i);
                continue;
            }

            No n = ((No) nos.elementAt(p));
            n.n.addElement((No) nos.elementAt(i));

        }
    }

    public boolean equals(Object o) {
        Arvore a = (Arvore) o;
        if (this.tot != a.tot)
            return false;
        return this.root.equals(a.root);
    }

    public void sort() {
        this.code = "";
        for (int i = 0; i != tot; i++) {
            No n = (No) nos.elementAt(i);
            if (n.n.size() != 1) {
                sort(n.n);
            }
        }
    }

    public void sort(Vector nos) {
        int n = nos.size();
        Vector v2 = new Vector();
        char us[] = new char[n];
        int j, t, i;
        No p1, p2;
        for (i = 0; i < n; i++) {
            p1 = null;
            t = -1;
            for (j = 0; j < n; j++) {
                if (us[j] == 1)
                    continue;
                p2 = (No) nos.elementAt(j);
                if (p1 == null || p1.compareTo(p2) > 0) {
                    t = j;
                    p1 = p2;
                }
            }
            us[t] = 1;
            v2.addElement(p1);
        }
        nos.removeAllElements();
        for (i = 0; i != n; i++) {
            nos.addElement(v2.elementAt(i));
        }
    }

}

class Main {

    static int maxLg = 10000;

    int tot;

    static long min;

    static boolean debug = false;

    public static void main(String args[]) throws Exception {

        try {
            int i = 0;
            while (true) {
                String s = readLine().trim();
                if (s.equals("0"))
                    return;
                int tot = Integer.parseInt(s);
                System.out.print(++i + ":");
                new Main(tot);
                System.out.println();
            }
        } catch (Exception e) {
            while (true)
                ;
        }

    }

    Arvore arvores[];

    Main(int t) throws IOException {
        this.tot = t;
        int i;
        int maxi = 0, j;
        arvores = new Arvore[tot];
        fora: for (i = 0; i != tot; i++) {
            arvores[maxi] = new Arvore(splitLongLine(readLine().trim()));
            arvores[maxi].sort();

            /*for (j = 0; j != maxi; j++) {
                if (arvores[maxi].equals(arvores[j])) {
                    System.out.print(" " + j);
                    continue fora;
                }
            }*/

            System.out.print(" " + maxi);
            maxi++;
        }
    }

    static void debug(String s) {
        if (debug)
            System.out.println(s);
    }

    static String[] split(String s) {
        StringTokenizer st = new StringTokenizer(s.trim(), " ");
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