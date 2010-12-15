
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

class Point {

    double x, y;

    void clear(double a, double b) {
        this.x = a;
        this.y = b;
    }

    Point() {
    }

    Point(double a, double b) {
        this.x = a;
        this.y = b;
    }

    public String toString() {
        return "(" + x + "," + y + ")";
    }

    public double distTo(Point p) {
        return Math.sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
}

class Reta {

    int id = ++tot;

    static int tot = 0;

    Point p1 = new Point(), p2 = new Point();

    boolean isHorizontal() {
        return p1.y == p2.y;
    }

    boolean isVertical() {
        return p1.x == p2.x;
    }

    double a, b;

    double dist;

    void clear(int x1, int y1, int x2, int y2) {
        this.p1.x = x1;
        this.p1.y = y1;
        this.p2.x = x2;
        this.p2.y = y2;
        this.a = (y2 - y1) / (x2 - x1);
        this.b = y1 - this.a * x1;
        calc();
    }

    public void clear(Point p, Point e) {
        this.p1 = p;
        this.p2 = e;
        this.dist = Math.sqrt((this.p1.x - this.p2.x) * (this.p1.x - this.p2.x)
                + (this.p1.y - this.p2.y) * (this.p1.y - this.p2.y));
        calc();
    }

    private void calc() {
        this.a = (this.p2.y - p1.y) / (p2.x - p1.x);
        this.b = this.p1.y - this.a * this.p1.x;
    }

    public boolean cruza(Reta reta) {
        double x = (reta.b - this.b) / (reta.a - a);
        double y = a * x + this.b;
        return contem(x, y);
    }

    public boolean contem(double x, double y) {
        if ((x >= this.p1.x && x <= this.p2.x)
                || (x <= this.p1.x && x >= this.p2.x)) {
            if ((y >= this.p1.y && y <= this.p2.y)
                    || (y <= this.p1.y && y >= this.p2.y)) {
                return true;
            }
        }
        return false;
    }

    public double distTo(Reta r) {
        double a, b, c, d, dx, dy;
        if (isHorizontal()) {
            if (r.isHorizontal()) {
                if ((p1.x >= r.p1.x && p1.x <= r.p2.x)
                        || (r.p1.x >= p1.x && r.p1.x <= p2.x)) {
                    return Math.abs(p1.y - r.p1.y);
                }
                if (p1.x >= r.p2.x) {
                    return r.p2.distTo(p1);
                }
                return p2.distTo(r.p1);
            } else {
                if (p1.y >= r.p1.y && p1.y <= r.p2.y) {
                    dy = 0;
                } else {
                    if (p1.y >= r.p2.y) {
                        dy = p1.y - r.p2.y;
                    } else {
                        dy = r.p1.y - p1.y;
                    }
                }
                if (r.p1.x >= p1.x && r.p1.x <= p2.x) {
                    dx = 0;
                } else {
                    if (r.p1.x >= p2.x) {
                        dx = r.p1.x - p2.x;
                    } else {
                        dx = p1.x - r.p1.x;
                    }
                }
                return Math.sqrt(dx * dx + dy * dy);
            }
        } else if (isVertical()) {
            if (r.isVertical()) {
                if ((p1.y >= r.p1.y && p1.y <= r.p2.y)
                        || (r.p1.y >= p1.y && r.p1.y <= p2.y)) {
                    return Math.abs(p1.x - r.p1.x);
                }
                if (p1.y >= r.p2.y) {
                    return r.p2.distTo(p1);
                }
                return p2.distTo(r.p1);
            }
            return r.distTo(this);
        }
        a = distTo(r.p1);
        b = distTo(r.p2);
        return a < b ? a : b;
    }

    public double distTo(Point p) {
        return Math.abs(a * p.x - 1 * p.y + b) / Math.sqrt(a * a + 1);
    }

    public boolean equals(Object o) {
        return this.id == ((Reta) o).id;
    }

}

class Aresta {

    Reta r1, r2;

    Aresta(Reta y1, Reta t2) {
        clear(y1, t2);
    }

    void clear(Reta y1, Reta t2) {
        r1 = y1;
        r2 = t2;
        this.d = y1.distTo(t2);
    }

    double d;

    int compareTo(Aresta r) {
        return d == r.d ? 0 : (d > r.d ? 1 : -1);
    }

}

class Main {

    static int maxLg = 20000;

    static Vector walls = new Vector();

    static void comeca(Reta r1, Reta r2) {
        double board = 0;
        double val[] = new double[walls.size() + 5];
        for (int i = 0; i != val.length; i++) {
            val[i] = -1;
        }
        Vector v = new Vector();
        v.addElement(new Aresta(r1, r1));
        val[1] = 0;
        while (v.size() != 0) {
            Aresta r = (Aresta) removeMin(v);
            if (!walls.removeElement(r.r2))
                continue;
            if (board < r.d)
                board = r.d;
            if (r.r2.id == 2) {
                board *= 100;
                board = Math.round(board);
                board = (long) board;
                System.out.print((long) (board / 100) + ".");
                board = (long) (board % 100);
                if (board < 10)
                    System.out.print("0");
                System.out.println((long) board);
                return;
            }
            Aresta a = null;
            for (int i = 0; i != walls.size(); i++) {
                Reta t = (Reta) walls.elementAt(i);
                if (a == null)
                    a = new Aresta(r.r2, t);
                else
                    a.clear(r.r2, t);
                if (val[t.id] == -1 || val[t.id] > a.d) {
                    if (val[t.id] != -1)
                        for (int zi = 0; zi != v.size(); zi++) {
                            if (((Aresta) v.elementAt(zi)).r2.id == t.id) {
                                v.removeElementAt(zi);
                                break;
                            }
                        }
                    v.addElement(a);
                    val[t.id] = a.d;
                    a = null;
                }
            }
        }
        System.out.println(board);
    }

    public static void main(String args[]) {

        try {
            while (true) {
                int w = Integer.parseInt(readLine().trim());
                if (w == 0)
                    break;
                Reta wall;
                Reta.tot = 0;
                double x2, y2, l[];
                walls.removeAllElements();
                for (int i = 0; i != w; i++) {
                    l = splitDoubleLine(readLine().trim());
                    if (l[2] < 0) {
                        x2 = l[0];
                        y2 = l[1] - l[2];
                    } else {
                        x2 = l[0] + l[2];
                        y2 = l[1];
                    }
                    wall = new Reta();
                    wall.clear(new Point(l[0], l[1]), new Point(x2, y2));
                    walls.addElement(wall);
                }
                comeca((Reta) walls.elementAt(0), (Reta) walls.elementAt(1));
            }
        } catch (Exception e) {
            while (true)
                ;
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

    static double[] splitDoubleLine(String s) {
        String[] l = split(s);
        double v[] = new double[l.length];
        for (int i = 0; i != l.length; i++) {
            v[i] = Double.valueOf(l[i]).doubleValue();
        }
        return v;
    }

    static long[] splitLongLine(String s) {
        String[] l = split(s);
        long v[] = new long[l.length];
        for (int i = 0; i != l.length; i++) {
            v[i] = Long.valueOf(l[i]).longValue();
        }
        return v;
    }

    public static Aresta removeMin(Vector v) {
        Aresta r = (Aresta) v.elementAt(0), r2;
        int z = 0, n = v.size();
        for (int j = 0; j < n; j++) {
            r2 = (Aresta) v.elementAt(j);
            if (r.compareTo(r2) > 0) {
                z = j;
                r = r2;
            }
        }
        v.removeElementAt(z);
        return r;
    }

}