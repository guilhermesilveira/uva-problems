import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

class Rectangle {

    double x1, y1, x2, y2;

    Rectangle(double a, double b, double c, double d) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }

}

class Main {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {

        Vector v = new Vector();

        while (true) {

            String l = readLine();
            if (l.charAt(0) == '*') break;

            double[] parsed = splitDoubleLineR(l);
            Rectangle r1 = new Rectangle(parsed[0], parsed[3], parsed[2], parsed[1]);
            v.addElement(r1);

        }

        //System.out.println(v.size());

        int p = 0;
        while (true) {

            double[] parsed = splitDoubleLine();
            p++;
            if (parsed[0] == 9999.9 && parsed[1] == 9999.9) break;
            boolean contained = false;
            for (int i = 0; i != v.size(); i++) {
                Rectangle r = (Rectangle) v.elementAt(i);
                if ((parsed[0] > r.x1 && parsed[0] < r.x2 && parsed[1] > r.y1 && parsed[1] < r.y2)) {
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

        if ((car < 0) && (lg == 0)) { return (null); // eof
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
