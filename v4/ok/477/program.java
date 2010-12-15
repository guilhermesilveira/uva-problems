

import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

interface Figure {

    public boolean contains(double x, double y);
}

class Rectangle implements Figure {

    double x1, y1, x2, y2;

    public boolean contains(double px, double py) {
        return ((px > x1 && px < x2 && py > y1 && py < y2));
    }

    Rectangle(double a, double b, double c, double d) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }

}

class Circle implements Figure {

    double x, y;

    double r;

    Circle(double x, double y, double r) {
        this.x = x;
        this.y = y;
        this.r = r;
    }

    public boolean contains(double px, double py) {
        double dist2 = (px - x) * (px - x) + (py - y) * (py - y);
        return dist2 < r * r;
    }

}

class Triangle implements Figure {
    
    double x1, y1;
    double x2, y2;
    double x3, y3;
    
    Triangle(double a, double b, double c, double d,double e,double f) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
        x3 = e;
        y3 = f;
    }

    public boolean contains(double x, double y) {
        double a = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
        double b = (x3 - x2) * (y - y2) - (y3 - y2) * (x - x2);
        double c = (x1 - x3) * (y - y3) - (y1 - y3) * (x - x3);
        return((a>0 && b>0 && c>0) || (a<0 && b<0 && c<0));
    }

}

class Main {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {

        Vector v = new Vector();

        while (true) {

            String l = readLine();
            if (l.charAt(0) == '*')
                break;

            if (l.charAt(0) == 'r') {
                double[] parsed = splitDoubleLineR(l);
                Rectangle r1 = new Rectangle(parsed[0], parsed[3], parsed[2],
                        parsed[1]);
                v.addElement(r1);
            } else if (l.charAt(0) == 'c') {
                double[] parsed = splitDoubleLineR(l);
                Circle r1 = new Circle(parsed[0], parsed[1], parsed[2]);
                v.addElement(r1);
            } else if (l.charAt(0) == 't') {
                double[] parsed = splitDoubleLineR(l);
                Triangle r1 = new Triangle(parsed[0], parsed[1], parsed[2],parsed[3], parsed[4], parsed[5]);
                v.addElement(r1);
            }

        }

        int p = 0;
        while (true) {

            double[] parsed = splitDoubleLine();
            p++;
            if (parsed[0] == 9999.9 && parsed[1] == 9999.9)
                break;
            boolean contained = false;
            for (int i = 0; i != v.size(); i++) {
                Figure r = (Figure) v.elementAt(i);
                if (r.contains(parsed[0], parsed[1])) {
                    System.out.println("Point " + p
                            + " is contained in figure " + (i + 1));
                    contained = true;
                }
            }
            if (!contained) {
                System.out.println("Point " + p
                        + " is not contained in any figure");
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

    static int readIntLine() throws IOException {
        return Integer.parseInt(readLine());
    }

    static double[] splitDoubleLine() throws IOException {
        String[] l = split(readLine());
        double v[] = new double[l.length];
        for (int i = 0; i != l.length; i++) {
            v[i] = Double.valueOf(l[i]).doubleValue();
        }
        return v;
    }

    static double[] splitDoubleLineR(String s) throws IOException {
        String[] l = split(s);
        double v[] = new double[l.length - 1];
        for (int i = 1; i != l.length; i++) {
            v[i - 1] = Double.valueOf(l[i]).doubleValue();
        }
        return v;
    }

}