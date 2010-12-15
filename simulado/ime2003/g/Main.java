

import java.awt.Polygon;
import java.awt.geom.AffineTransform;
import java.awt.geom.Area;
import java.awt.geom.PathIterator;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

class MainG {

    static int maxLg = 2000;

    static int cores[] = new int[3];

    static double totalArea[] = new double[16];

    public static void main(String args[]) throws Exception {
        
        int caso = 0;

        while (true) {

            MyPolygon p1 = lePoligono(0);
            if (p1 == null) {
                return;
            }
            
            System.out.println("Instancia " + ++caso);

            for (int i = 0; i != 16; i++) {
                totalArea[i] = 0;
            }

            MyPolygon p2 = lePoligono(1);
            MyPolygon p3 = lePoligono(2);

            Set s = new TreeSet();

            Area a1 = new Area((p1));

            Area a2 = new Area((p2));

            Area a3 = new Area((p3));

            // uniao a1, a2 e a3
            Area a123 = new Area(a1);
            a123.intersect(a2);
            a123.intersect(a3);
            MyArea ma123 = new MyArea(a123, cores[0] + cores[1] + cores[2]);
            ma123.calculateArea("a123");

            // uniao a1 e a2
            Area a12 = new Area(a1);
            a12.intersect(a2);
            a12.subtract(a3);
            MyArea ma12 = new MyArea(a12, cores[0] + cores[1]);
            ma12.calculateArea("a12");

            // uniao a1 e a3
            Area a13 = new Area(a1);
            a13.intersect(a3);
            a13.subtract(a2);
            MyArea ma13 = new MyArea(a13, cores[2] + cores[0]);
            ma13.calculateArea("a13");

            // uniao a1 e a3
            Area a23 = new Area(a2);
            a23.intersect(a3);
            a23.subtract(a1);
            MyArea ma23 = new MyArea(a23, cores[1] + cores[2]);
            ma23.calculateArea("a23");

            // fix its area
            Area aa1 = (Area) a1.clone();
            aa1.subtract(a2);
            aa1.subtract(a3);
            MyArea ma1 = new MyArea(aa1, cores[0]);
            ma1.calculateArea("aa1");
            
            Area aa2 = (Area) a2.clone();
            aa2.subtract(a1);
            aa2.subtract(a3);
            MyArea ma2 = new MyArea(aa2, cores[1]);
            ma2.calculateArea("aa2");

            Area aa3 = new Area(a3);
            aa3.subtract(a1);
            aa3.subtract(a2);
            MyArea ma3 = new MyArea(aa3, cores[2]);
            ma3.calculateArea("aa3");

            // adding the color area
            for (int i = 0; i != 16; i++) {
                if (totalArea[i] != 0) {
                    s.add(new Cor(i, totalArea[i]));
                }
            }

            Iterator i = s.iterator();
            while (i.hasNext()) {
                Cor c = (Cor) i.next();
                System.out.println(c.id + " " + c.area);
            }
            
            System.out.println();

        }

    }

    static MyPolygon lePoligono(int cor) throws IOException {

        StringTokenizer st = new StringTokenizer(readLine());

        int vertices = Integer.parseInt(st.nextToken());

        if (vertices == 0) {
            return null;
        }

        cores[cor] = Integer.parseInt(st.nextToken());

        int[] x = new int[vertices];
        int[] y = new int[vertices];

        for (int i = 0; i != vertices; i++) {

            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());

        }

        if (x[0] == 0 && x[1] == 0 && x[2] == 0 && y[1] == 0 && y[2] == 0
                && y[0] == 0) {
            return null;
        }

     //   System.out.println(vertices + " vertices");

        return new MyPolygon(x, y, vertices);

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

class MyPolygon extends Polygon {

    /**
     * @param x
     * @param y
     * @param i
     */
    public MyPolygon(int[] x, int[] y, int i) {
        super(x, y, i);
    }

    int color;

}

class MyArea {

    Double area;

    Area validArea;

    int cor;

    /**
     * @param p2
     */
    public MyArea(Area a, int cor) {
        this.validArea = a;
        this.cor = cor;
    }

    void calculateArea(String name) {

        double a = 0.0;
        
       // System.out.println("checking " + name);

        if (this.validArea.isEmpty()) {
            area = new Double(0);
            return;
        }

        PathIterator pi = this.validArea.getPathIterator(new AffineTransform());

        ArrayList points = new ArrayList();
        
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
                points.add(p);

            } else if (mode == PathIterator.SEG_LINETO) {

                double[] p = new double[2];
                p[0] = point[0];
                p[1] = point[1];
                //  System.out.println("passando em " + p[0] + "," + p[1]);
                points.add(p);

            } else if (mode == PathIterator.SEG_CLOSE) {

                // System.out.println("fechando com " + points.size() + "
                // pontos");
                a += calculaArea(points);

            } else {

                throw new AssertionError();

            }

            pi.next();

        }

        this.area = new Double(Math.abs(a));
        
        //System.out.println(name + " :: " + this.area);

        MainG.totalArea[cor % 16] += this.area.doubleValue();

    }

    public double dist(double[] a, double[] b) {
        return Math.sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1])
                * (a[1] - b[1]));
    }

    private double calculaArea(ArrayList points) {
        
        // devo sortear os pontos, mas como?

        double[] p = (double[]) points.get(0);
        double area = 0.0;
        double p2[], p3[], cima;

        for (int i = 1; i != points.size() - 1; i++) {

            p2 = (double[]) points.get(i);
            p3 = (double[]) points.get(i + 1);

           /* a = dist(p, p2);
            b = dist(p2, p3);
            c = dist(p3, p);*/

            /*System.out.println("calculando area (" + p[0] + "," + p[1] + ")" );
            System.out.println("calculando area (" + p2[0] + "," + p2[1] + ")" );
            System.out.println("calculando area (" + p3[0] + "," + p3[1] + ")" );
            System.out.println("-------------------------------------------" );*/
/*            System.out.println("calculando area do triangulo (" + a + "," + b
                    + "," + c + ")");*/

            /*cima = a * a + b * b - c * c;
            cima /= (2 * a);
            cima = b * b - cima * cima;
            cima = a * Math.sqrt(cima);
            cima = cima / 2;*/
            cima = p[0] * p2[1] + p[1] * p3[0] + p2[0] * p3[1] - p2[1] * p3[0]
                    - p[0] * p3[1] - p[1] * p2[0];
            
            //System.out.println(cima);

            area += (cima / 2);

        }

        points.clear();

        return area;

    }

}

class Cor implements Comparable {

    Cor(int id, double area) {
        this.id = new Integer(id);
        this.area = new Double(area);
    }

    Integer id;

    Double area;

    public int compareTo(Object o) {

        Cor o2 = (Cor) o;

        if (this.area.equals(o2.area)) {
            return id.compareTo(o2.id);
        }

        return o2.area.compareTo(this.area);
    }
}