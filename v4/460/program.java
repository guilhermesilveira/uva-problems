import java.awt.geom.Rectangle2D;
import java.io.IOException;
import java.util.StringTokenizer;

class Main {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {

        String line;
        while ((line = readLine()) != null) {

            int[] parsed = splitIntLine(line);
            int[] parsed2 = splitIntLine();

            Rectangle2D r1 = new Rectangle2D.Float(parsed[0], parsed[1],
                    parsed[2], parsed[3]);
            Rectangle2D r2 = new Rectangle2D.Float(parsed2[0], parsed2[1],
                    parsed2[2], parsed2[3]);
            Rectangle2D r3 = r1.createIntersection(r2);
            System.out.println(r3.getMinX() + " " + r3.getMinY() + " "
                    + r3.getMaxX() + " " + r3.getMaxY());

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

    static int[] splitIntLine() throws IOException {
        String[] l = split(readLine());
        int v[] = new int[l.length];
        for (int i = 0; i != l.length; i++) {
            v[i] = Integer.parseInt(l[i]);
        }
        return v;
    }

    static int[] splitIntLine(String s) throws IOException {
        String[] l = split(s);
        int v[] = new int[l.length];
        for (int i = 0; i != l.length; i++) {
            v[i] = Integer.parseInt(l[i]);
        }
        return v;
    }

}
