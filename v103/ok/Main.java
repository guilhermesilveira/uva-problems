
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

class Carta {

    char valor;

    char naipe;

    void le(String s) {
        this.valor = s.charAt(0);
        this.naipe = s.charAt(1);
    }

    public int compareTo(Carta p2) {
        if (this.val() != p2.val()) {
            return this.val() - p2.val();
        }
        return this.naipe - p2.naipe;
    }

    public String toString() {
        return "" + this.valor + this.naipe;
    }

    public int minus(Carta o) {
        return this.val() - o.val();
    }

    int val() {
        if (this.valor == 'A')
            return 14;
        if (this.valor == 'K')
            return 13;
        if (this.valor == 'Q')
            return 12;
        if (this.valor == 'J')
            return 11;
        if (this.valor == 'T')
            return 10;
        return this.valor - '1';
    }

}

class Mao {

    Carta c1;

    Carta c2;

    Carta c3;

    Carta c4;

    Carta c5;

    void le(Vector v) {
        c1 = (Carta) v.elementAt(0);
        c2 = (Carta) v.elementAt(1);
        c3 = (Carta) v.elementAt(2);
        c4 = (Carta) v.elementAt(3);
        c5 = (Carta) v.elementAt(4);
    }

    String compareTo(Mao m) {
        if (isStraightFlush()) {
            if (m.isStraightFlush())
                return compareHigh(m);
            return "Black wins.";
        }
        if (m.isStraightFlush())
            return "White wins.";
        if (isFour()) {
            if (m.isFour())
                return compareHigh(m);
            return "Black wins.";
        }
        if (m.isFour())
            return "White wins.";
        // full house
        if (isFullHouse()) {
            if (m.isFullHouse())
                return compareHigh(m);
            return "Black wins.";
        }
        if (m.isFullHouse())
            return "White wins.";
        // flush
        if (isFlush()) {
            if (m.isFlush())
                return compareHigh(m);
            return "Black wins.";
        }
        if (m.isFlush()) {
            return "White wins.";
        }
        if (isStraight()) {
            if (m.isStraight())
                return compareHigh(m);
            return "Black wins.";
        }
        if (m.isStraight()) {
            return "White wins.";
        }
        // three of a kind
        if (isThree()) {
            if (m.isThree())
                return compareHigh(m);
            return "Black wins.";
        }
        if (m.isThree())
            return "White wins.";
        // two pairs
        if (isTwoPairs()) {
            if (m.isTwoPairs())
                return compareHigh(m);
            return "Black wins.";
        }
        if (m.isTwoPairs()) {
            return "White wins.";
        }
        // pair
        if (isPair()) {
            if (m.isPair())
                return compareHigh(m);
            return "Black wins.";
        }
        if (m.isPair()) {
            return "White wins.";
        }
        // high card
        return compareHigh(m);
    }

    private boolean isFullHouse() {
        return (mesmos(c1, c2, c3) && mesmos(c4, c5))
                || (mesmos(c5, c4, c3) && mesmos(c1, c2));
    }

    private boolean isTwoPairs() {
        if (mesmos(c1, c2)) {
            return mesmos(c3, c4) || mesmos(c4, c5);
        }
        return mesmos(c2, c3) && mesmos(c4, c5);
    }

    private boolean isThree() {
        return mesmos(c1, c2, c3) || mesmos(c2, c3, c4) || mesmos(c3, c4, c5);
    }

    private boolean mesmos(Carta c12, Carta c22, Carta c32) {
        return c12.val() == c22.val() && c22.val() == c32.val();
    }

    private boolean mesmos(Carta c12, Carta c22) {
        return c12.val() == c22.val();
    }

    private boolean isFour() {
        return (c1.val() == c2.val() && c2.val() == c3.val() && c3.val() == c4
                .val())
                || (c2.val() == c3.val() && c3.val() == c4.val() && c4.val() == c5
                        .val());
    }

    private String compareHigh(Mao m) {
        String s;
        s=comp(c5,m.c5);
        if(s!=null) return s;
        s=comp(c4,m.c4);
        if(s!=null) return s;
        s=comp(c3,m.c3);
        if(s!=null) return s;
        s=comp(c2,m.c2);
        if(s!=null) return s;
        s=comp(c1,m.c1);
        if(s!=null) return s;
        return "Tie.";
    }

    private String comp(Carta c1, Carta c2) {
        if (c1.val() != c2.val()) {
            if (c1.val() > c2.val())
                return "Black wins.";
            return "White wins.";
        }
        return null;
    }

    private boolean isPair() {
        return c1.val() == c2.val() || c2.val() == c3.val()
                || c3.val() == c4.val() || c4.val() == c5.val();
    }

    public String toString() {
        return (c1 + "," + c2 + "," + c3 + "," + c4 + "," + c5);
    }

    private boolean isStraightFlush() {
        return this.isFlush() && this.isStraight();
    }

    private boolean isStraight() {
        return c5.minus(c4) == 1 && c4.minus(c3) == 1 && c3.minus(c2) == 1
                && c2.minus(c1) == 1;
    }

    private boolean isFlush() {
        return c1.naipe == c2.naipe && c2.naipe == c3.naipe
                && c3.naipe == c4.naipe && c4.naipe == c5.naipe;
    }

}

class Main {

    static int maxLg = 200;

    static Vector h1 = new Vector();

    static Vector h2 = new Vector();

    static Carta[] c = new Carta[10];

    public static void main(String args[]) throws Exception {

        String s = "";
        Mao m1 = new Mao();
        Mao m2 = new Mao();
        for (int i = 0; i != 10; i++) {
            c[i] = new Carta();
        }
        while (true) {

            s = readLine();
            if (s == null) {
                break;
            }

            s = s.trim();
            //            System.out.println(s);

            h1.removeAllElements();
            h2.removeAllElements();

            le(s, h1, 0);
            sort(h1);
            le(s, h2, 5);
            sort(h2);
            m1.le(h1);
            m2.le(h2);

            //System.out.println(m1);
            //System.out.println(m2);

            System.out.println(m1.compareTo(m2));

        }

    }

    public static void sort(Vector v) {
        int n = v.size();
        Vector v2 = new Vector();
        char us[] = new char[n];
        int j, t, i;
        Carta p1, p2;
        for (i = 0; i < n; i++) {
            p1 = null;
            t = -1;
            for (j = 0; j < n; j++) {
                if (us[j] == 1)
                    continue;
                p2 = (Carta) v.elementAt(j);
                if (p1 == null || p1.compareTo(p2) > 0) {
                    t = j;
                    p1 = p2;
                }
            }
            us[t] = 1;
            v2.addElement(p1);
        }
        v.removeAllElements();
        for (i = 0; i != n; i++) {
            v.addElement(v2.elementAt(i));
        }
    }

    private static void le(String s, Vector h12, int b) {
        String[] z = split(s.trim());
        for (int i = 0; i != 5; i++) {
            c[b + i].le(z[b + i]);
            h12.addElement(c[b + i]);
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