import java.awt.Polygon;
import java.awt.geom.AffineTransform;
import java.awt.geom.Area;
import java.awt.geom.PathIterator;
import java.io.*;
import java.util.StringTokenizer;
import java.util.Vector;

class p4 {

    public static int translate(String s) {
        return (int) (Double.parseDouble(s) * 100);
    }

    public static void main(String args[]) throws Exception {
	String s;

        while (true) {

            int max = Integer.parseInt(readLine().trim());
            if (max==0) {
                return;
            }

            Polygon pol = new Polygon();
	for(int i=0;i!=max;i++) {
		s = readLine().trim();
		String p[] = split(s);
		pol.addPoint(translate(p[0]),translate(p[1]));
	}

            Area a = new Area(pol);
            double z = calculateArea(a);
		z /= 10000;
            // ????
            z = Math.round(z * 100);

            long zz = (long) (z);
            long inteira = zz / 100;
            long corte = zz % 100;

            //System.out.println(z + "," + zz);

            System.out.print(inteira + ".");
            
            if (corte == 0) {
                System.out.print("00");
            } else if (corte < 10) {
                System.out.print("0" + corte);
            } else {
                System.out.print(corte);
            }
            
            System.out.println();

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
	return buffer.readLine();
    }
	static BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

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
