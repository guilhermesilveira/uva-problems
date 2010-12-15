
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

class Point {

    int x, y;

    boolean p;

    boolean tel;

    boolean end;

    double dist;

    void clear(int a, int b) {
        this.x = a;
        this.y = b;
        this.p = false;
        this.tel = false;
        this.end = false;
    }
}

class Reta {

    Point p1 = new Point(), p2 = new Point();

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
        calc();
    }

    public boolean cruza(Reta reta) {
        double x = (reta.b - this.b) / (reta.a - a);
        double y = a * x + this.b;
        return contem(x, y);
    }

    private boolean contem(double x, double y) {
        if ((x >= this.p1.x && x <= this.p2.x)
                || (x <= this.p1.x && x >= this.p2.x)) {
            if ((y >= this.p1.y && y <= this.p2.y)
                    || (y <= this.p1.y && y >= this.p2.y)) {
                return true;
            }
        }
        return false;
    }

}

class Main2 {

    static int maxLg = 200;

    static int n, m, l;

    static Reta[] walls = new Reta[50];

    static Point[] tel = new Point[50];

    static int pc;

    static Point[] points = new Point[150];

    public static void main(String args[]) throws Exception {

        for (int i = 0; i != m; i++) {
            walls[i] = new Reta();
            tel[i] = new Point();
            tel[i].tel = true;
        }
        String t[];
        while (true) {
            t = split(readLine());
            n = Integer.parseInt(t[0]);
            m = Integer.parseInt(t[1]);
            l = Integer.parseInt(t[2]);
            if (n == 0 && m == 0 && l == 0)
                break;
            pc = 0;
            for (int i = 0; i != m; i++) {
                t = split(readLine());
                walls[i].clear(Integer.parseInt(t[0]), Integer.parseInt(t[1]),
                        Integer.parseInt(t[2]), Integer.parseInt(t[3]));
                points[pc++] = walls[i].p1;
                points[pc++] = walls[i].p2;
            }
            for (int i = 0; i != l; i++) {
                t = split(readLine());
                tel[i].clear(Integer.parseInt(t[0]), Integer.parseInt(t[1]));
                points[pc++] = tel[i];
            }
            Point s = new Point();
            t = split(readLine());
            s.clear(Integer.parseInt(t[0]), Integer.parseInt(t[1]));
            Point e = new Point();
            t = split(readLine());
            e.x = Integer.parseInt(t[0]);
            e.y = Integer.parseInt(t[1]);
            e.end = true;
            points[pc++] = e;
            start(s);
        }

    }

    private static void start(Point s) {
        // tento ir para cada local possivel
        Vector v = new Vector();
        v.addElement(s);
        Reta menor = null;
        Reta temp = new Reta();
        Reta r;
        s.dist = 0;
        while (v.size() != 0) {
            double minDist = 0;
            menor = null;
            Point p = (Point) v.elementAt(0);
            v.removeElement(p);
            // para todos os caminhos possiveis
            for (int i = 0; i != pc; i++) {
                if (points[i].p) {
                    temp.clear(s, points[i]);
                    if (!possivel(temp))
                        continue;
                    if (minDist < temp.dist
                            || (minDist == temp.dist && points[i].end == true)
                            || menor == null) {
                        if (menor == null) {
                            temp = new Reta();
                            menor = temp;
                        } else {
                            r = menor;
                            menor = temp;
                            temp = r;
                        }
                    }
                }
            }
            if (menor == null) {
                // nao achou nada!!???
                while (true)
                    ;
            }
            if (menor.p2.end) {
                System.out.println(Math.round(p.dist + menor.dist));
                return;
            }
            // se for um TELEPORTE???
            menor.p2.dist = p.dist + menor.dist;
            v.addElement(menor.p2);
        }
        // nao achou nada!!! impossivel!!!
        while (true)
            ;
    }

    private static boolean possivel(Reta temp) {
        for (int i = 0; i != m; i++) {
            if (temp.cruza(walls[i]))
                return false;
        }
        return true;
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