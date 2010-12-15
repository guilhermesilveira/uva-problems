

import java.io.IOException;
import java.io.InputStream;
import java.util.StringTokenizer;

class Main {

    static int instanceCount = 0;

    public static void main(String[] args) throws Exception {
        while (instancia()) {
        }
    }

    static String readLine() throws IOException {
        return readLine(500);
    }

    static String readLine(int max) throws IOException {

        int i = 0, character = -1;
        String line = "";
        byte lin[] = new byte[max];

        while (i < max) {
            character = System.in.read();
            if ((character < 0) || (character == '\n'))
                break;
            lin[i++] += character;
        }

        // eof
        if ((character < 0) && (i == 0)) {
            return (null);
        }
        return (new String(lin, 0, i));

    }

    /* O PROGRAMA COMECA AQUI */

    static Rectangle rectangle[] = new Rectangle[25];

    static int icon[][] = new int[50][3];

    static double dist[] = new double[50];

    static int icons = 0;

    static int rectangles = 0;

    static boolean comecou = false;

    static double dist(int x1, int y1, int x2, int y2) {
        return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    private static boolean instancia() throws Exception {

        String line = readLine().trim();
        if (line.charAt(0) == '#') {
            return false;
        }

        Tokens tk = new Tokens(line, " ");

        String tipo = tk.nextToken();

        if (tipo.charAt(0) == 'I') {

            icon[icons][0] = tk.nextInt();
            icon[icons][1] = tk.nextInt();
            icon[icons][2] = 0;
            icons++;

        } else if (tipo.charAt(0) == 'R') {

            Rectangle r = new Rectangle(tk.nextInt(), tk.nextInt(), tk
                    .nextInt(), tk.nextInt());
            rectangle[rectangles] = r;
            rectangles++;

        } else if (tipo.charAt(0) == 'M') {

            if (!comecou) {

                for (int i = 0; i != icons; i++) {
                    for (int i2 = 0; i2 != rectangles; i2++) {
                        if (rectangle[i2].contains(icon[i][0], icon[i][1])) {
                            icon[i][2] = -1;
                            break;
                        }
                    }
                }

            }

            int x, y;
            x = tk.nextInt();
            y = tk.nextInt();
            boolean contains = false;
            for (int i2 = rectangles - 1; i2 >= 0; i2--) {
                if (rectangle[i2].contains(x, y)) {
                    System.out.println("" + ((char) (i2 + 'A')));
                    contains = true;
                    break;
                }
            }
            if (!contains) {
                // testa os icones
                //System.out.println("mouse at " + x + "," + y);
                double minDist = Double.POSITIVE_INFINITY;
                for (int i = 0; i != icons; i++) {
                    if (icon[i][2] == 0) {
                        // se o icone esta ativo, ve se eh menor que minDist
                        if ((dist[i] = dist(icon[i][0], icon[i][1], x, y)) < minDist) {
                            minDist = dist[i];
                        }
                    }
                }
                for (int i = 1; i != icons + 1; i++) {
                    if (icon[i - 1][2] == 0) {
                        if (dist[i - 1] == minDist) {
                            if (i < 10) {
                                System.out.print("  " + i);
                            } else {
                                System.out.print(" " + i);
                            }
                        }
                    }
                }
                System.out.println();
            }

        }

        return true;

    }
}

class Tokens extends StringTokenizer {

    int count;

    String str;

    Tokens(String str, String delim) {
        super(str, delim);
        this.str = str;
        count = countTokens();
    }

    int nextInt() {
        String s = "";
        while (s.equals("")) {
            s = nextToken().trim();
        }
        return Integer.parseInt(s.trim());
    }
}

class Rectangle {

    int x1, x2, y1, y2;

    Rectangle(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
    }

    boolean contains(int x, int y) {
        return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
    }

}