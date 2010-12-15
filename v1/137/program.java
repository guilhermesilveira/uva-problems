

import java.awt.Polygon;
import java.awt.geom.AffineTransform;
import java.awt.geom.Area;
import java.awt.geom.PathIterator;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

class MainK {

    static int maxLg = 200;

    public static int translate(String s) {
        return Integer.parseInt(s);
    }

    public static void main(String args[]) throws Exception {

        while (true) {

            String s = readLine().trim();
            if (s.equals("0")) {
                return;
            }

            String p[] = split(s);
            int max = Integer.parseInt(p[0]);
            Polygon pol = new Polygon();
            for (int i = 0; i != max; i++) {
                pol.addPoint(translate(p[i * 2 + 1]), translate(p[i * 2 + 2]));
            }

            p = split(readLine().trim());
            max = Integer.parseInt(p[0]);
            Polygon pol2 = new Polygon();
            for (int i = 0; i != max; i++) {
                pol2.addPoint(translate(p[i * 2 + 1]), translate(p[i * 2 + 2]));
            }

            Area a = new Area(pol);
            a.exclusiveOr(new Area(pol2));
            double z = calculateArea(a);
            // ????
            z = Math.round(z * 100);

            long zz = (long) (z);
            long inteira = zz / 100;
            long corte = zz % 100;

            //System.out.println(z + "," + zz);

            if (inteira < 10) {
                System.out.print("    ");
            } else if (inteira < 100) {
                System.out.print("   ");
            } else if (inteira < 1000) {
                System.out.print("  ");
            } else if (inteira < 10000) {
                System.out.print(" ");
            }
            
            System.out.print(inteira + ".");
            
            if (corte == 0) {
                System.out.print("00");
            } else if (corte < 10) {
                System.out.print("0" + corte);
            } else {
                System.out.print(corte);
            }
            
            //System.out.println();

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

    static double calculateArea(Area validArea) {

        double a = 0.0;

        // System.out.println("checking " + name);

        if (validArea.isEmpty()) {
            return 0;
        }

        PathIterator pi = validArea.getPathIterator(new AffineTransform());

        Vector points = new Vector();

        //System.out.println("iteracao: " + cor);
        while (!pi.isDone()) {

            double[] point = new double[6];

            int mode = pi.currentSegment(point);

            if (mode == PathIterator.SEG_MOVETO) {

                //System.out.println("MOVE_TO");

                if (points.size() != 0) {
                    // FINALIZAR ESSA SHAPE E ADICIONAR A AREA A A
                    //   System.out.println("WEIRD MOVE_TO");
                    a += calculaArea(points);
                }

                double[] p = new double[2];
                p[0] = point[0];
                p[1] = point[1];
                // System.out.println("Comecando em " + p[0] + "," + p[1]);
                points.addElement(p);

            } else if (mode == PathIterator.SEG_LINETO) {

                double[] p = new double[2];
                p[0] = point[0];
                p[1] = point[1];
                //  System.out.println("passando em " + p[0] + "," + p[1]);
                points.addElement(p);

            } else if (mode == PathIterator.SEG_CLOSE) {

                // System.out.println("fechando com " + points.size() + "
                // pontos");
                a += calculaArea(points);

            } else {

                throw new SecurityException();

            }

            pi.next();

        }

        return (Math.abs(a));

    }

    static private double calculaArea(Vector points) {

        // devo sortear os pontos, mas como?

        double[] p = (double[]) points.elementAt(0);
        double area = 0.0;
        double p2[], p3[], cima;

        for (int i = 1; i != points.size() - 1; i++) {

            p2 = (double[]) points.elementAt(i);
            p3 = (double[]) points.elementAt(i + 1);

            cima = p[0] * p2[1] + p[1] * p3[0] + p2[0] * p3[1] - p2[1] * p3[0]
                    - p[0] * p3[1] - p[1] * p2[0];
            area += (cima / 2);

        }

        points.removeAllElements();

        return area;

    }

}