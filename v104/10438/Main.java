

import java.io.IOException;
import java.util.Hashtable;
import java.util.StringTokenizer;

/**
 * @author Guilherme
 */
class Main {

    public static void main(String[] args) throws NumberFormatException,
            IOException {

        String s;
        String[] ss;
        int i;
        Hashtable sss = new Hashtable();
        while ((s = readLine()) != null) {
            ss = split(s.trim());
            s = "";
            sss.clear();
            for (i = 0; i != ss.length; i++) {
                ss[i] = ss[i].trim();
                if (!ss[i].equals("") && !sss.containsKey(ss[i])) {
                    sss.put(ss[i], ss[i]);
                    s += ss[i] + " ";
                }
            }
            System.out.println(s.substring(0, s.length() - 1));
        }

    }

    private static int maxLg = 85;

    static String[] split(String s) {
        StringTokenizer st = new StringTokenizer(s);
        String[] tokens = new String[st.countTokens()];
        for (int i = 0; i != tokens.length; i++) {
            tokens[i] = st.nextToken();
        }
        return tokens;
    }

    // le uma linha inteira
    static String readLine() throws IOException {
        byte lin[] = new byte[maxLg = 500];
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