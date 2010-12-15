

import java.io.*;
import java.math.*;
import java.util.*;
import java.awt.*;
import java.awt.geom.*;

class H {

    public static void main(String[] args) throws Exception {

        BufferedReader read = new BufferedReader(new InputStreamReader(
                System.in));
       
        while (true) {
            int mn[] = readInt(read);
            if (mn[0] == 0 && mn[1] == 0)
                break;
            Rectangle2D r[] = new Rectangle2D[mn[1]];
            //System.out.println(mn[0] + "," + mn[1]);
            int vertices[][] = new int[mn[0]][2];
            for (int i = 0; i != mn[0]; i++) {
                vertices[i] = readInt(read);
                //System.out.println("vertice[" + i + "] :: " + vertices[i]);
            }
            for (int i = 0; i != mn[1]; i++) {
                int p[] = readInt(read);
                int t;
                if (p[2] < p[0]) {
                    t = p[2];
                    p[2] = p[0];
                    p[0] = t;
                }
                p[2] -= p[0];
                if (p[3] < p[1]) {
                    t = p[3];
                    p[3] = p[1];
                    p[1] = t;
                }
                p[3] -= p[1];
                r[i] = new Rectangle(p[0], p[1], p[2], p[3]);
                //System.out.println();
            }
            read.readLine();
            Polygon p = new Polygon();
            for (int i = 0; i != mn[0]; i++) {
                p.addPoint(vertices[i][0], vertices[i][1]);
            }
            Area a = new Area(p);
            for (int k = 0; k != mn[1]; k++) {
                if (p.contains(r[k])) {
                    //System.out.println("subtracting " + k);
                    a.subtract(new Area(r[k]));
                }
            }
            if (a.isEmpty()) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

    }

    public static int[] readInt(BufferedReader read) throws Exception {
        String s[] = read.readLine().split("\\s+");
        int k[] = new int[s.length];
        for (int i = 0; i != s.length; i++) {
            k[i] = Integer.parseInt(s[i]);
        }
        return k;
    }
}