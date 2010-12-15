

import java.awt.Polygon;
import java.awt.geom.AffineTransform;
import java.awt.geom.Area;
import java.awt.geom.Point2D;
import java.io.IOException;
import java.util.StringTokenizer;

class Maina {

    static int maxLg = 200;

    static int minX, maxX, minY, maxY;

    public static void main(String args[]) throws Exception {

        while (true) {

            minX = 9999999;
            minY = 9999999;
            maxX = 0;
            maxY = 0;
            Polygon p1 = split(readLine());

            if (p1 == null) {
                return;
            }

            AffineTransform at = new AffineTransform();
            at.setToScale(0.01, 0.01);
            Area a = new Area(p1);
//            a = a.createTransformedArea(at);

            int contem = 0;
            for (int x = (((int) (minX / 200.0)) - 1) * 100; x <= maxX + 200; x += 100) {

                for (int y = (((int) (minY / 200.0)) - 1) * 100; y <= maxY + 200; y += 100) {

                    System.out.println("testando: " + x + "," + y + ": "
                            + p1.contains(x, y));

                    if (a.contains(new Point2D.Double(x, y))) {
                        contem++;
                    }

                }

            }

            if (contem < 10) {
                System.out.println("   " + contem);
            } else if (contem < 100) {
                System.out.println("  " + contem);
            } else if (contem < 1000) {
                System.out.println(" " + contem);
            } else {
                System.out.println(contem);
            }

        }

    }

    static Polygon split(String s) {

        int[] x = new int[6];
        int[] y = new int[6];
        StringTokenizer st = new StringTokenizer(s);

        for (int i = 0; i != 3; i++) {

            x[i] = (int) (new Double(st.nextToken()).doubleValue() * 100);
            y[i] = (int) (new Double(st.nextToken()).doubleValue() * 100);

            System.out.println(x[i] + "," + y[i]);

            if (x[i] > maxX)
                maxX = x[i];

            if (y[i] > maxY)
                maxY = y[i];

            if (x[i] < minX)
                minX = x[i];

            if (y[i] < minY)
                minY = y[i];

        }

        if (x[0] == 0 && x[1] == 0 && x[2] == 0 && y[1] == 0 && y[2] == 0
                && y[0] == 0) {
            return null;
        }

        return new Polygon(x, y, 3);

    }

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