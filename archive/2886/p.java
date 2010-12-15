
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

class Main {

    static int maxLg = 200;

    static int n, m, l;

    static int pc;

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