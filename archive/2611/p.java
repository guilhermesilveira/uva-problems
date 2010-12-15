
import java.io.IOException;
import java.util.StringTokenizer;

class Face {

    char d[][] = new char[3][3];

    public void read(String[] s, int c, int l) {
        this.d[l][0] = s[c + 0].charAt(0);
        this.d[l][1] = s[c + 1].charAt(1);
        this.d[l][2] = s[c + 2].charAt(2);
    }

    public boolean ok() {
        for (int i = 0; i != 3; i++)
            for (int j = 0; j != 3; j++)
                if (this.d[i][j] != this.d[0][0])
                    return false;
        return true;
    }

    public void rotaciona(int i) {
        if (i == 1) {
            rotDireita();
        } else if (i == -1) {
            rotEsquerda();
        }
    }

    private void rotEsquerda() {

    }

    private void rotDireita() {
    }
}

class Main {

    static int maxLg = 200;

    static int n, m, l;

    static Face[] faces = new Face[7];

public static void main(String args[]) throws Exception {

        String t[];
        for(int i=0;i!=7;i++) {
            faces[i] = new Face();
        }
        faces[1].f(faces[5],faces[4],faces[2],faces[6]);
        faces[2].f(faces[5],faces[1],faces[3],faces[6]);
        //faces[3].f(faces[],faces[],faces[],faces[]);
        //faces[4].f(faces[],faces[],faces[],faces[]);
        //faces[5].f(faces[],faces[],faces[],faces[]);
        //faces[6].f(faces[],faces[],faces[],faces[]);
        int tz = Integer.parseInt(readLine().trim());
        ooo: while (tz-- != 0) {
            faces[5].read(split(readLine()), 0, 0);
            faces[5].read(split(readLine()), 0, 1);
            faces[5].read(split(readLine()), 0, 2);
            String[] s1 = split(readLine());
            String[] s2 = split(readLine());
            String[] s3 = split(readLine());
            for (int i = 1; i != 5; i++) {
                faces[i].read(s1, i * 3, 0);
                faces[i].read(s2, i * 3, 1);
                faces[i].read(s3, i * 3, 2);
            }
            faces[6].read(split(readLine()), 0, 0);
            faces[6].read(split(readLine()), 0, 1);
            faces[6].read(split(readLine()), 0, 2);
            t = split(readLine());
            for (int i = 0; i != t.length; i++) {
                int z = Integer.parseInt(t[i]);
                if (z == 0)
                    break;
                faces[Math.abs(z)].rotaciona(z > 0 ? 1 : -1);
            }
            for (int i = 1; i != 7; i++) {
                if (!faces[i].ok()) {
                    System.out.println("No, you are wrong!");
                    continue ooo;
                }
            }
            System.out.println("Yes, grandpa!");
        }

    }    static String[] split(String s) {
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