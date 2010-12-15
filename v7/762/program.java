

import java.io.IOException;
import java.util.Hashtable;
import java.util.StringTokenizer;
import java.util.Vector;

class Main {

    static int maxLg = 200;

    static Hashtable connections = new Hashtable();

    static Vector v;

    static Hashtable parents = new Hashtable();

    static String l[];

    static Vector queue = new Vector();

    Main() throws NumberFormatException, IOException {

        connections.clear();

        int cs = Integer.parseInt(readLine().trim());

        for (int i = 0; i != cs; i++) {
            String l[] = split(readLine().trim());
            if (!connections.containsKey(l[0])) {
                connections.put(l[0], new Vector());
            }
            if (!connections.containsKey(l[1])) {
                connections.put(l[1], new Vector());
            }
            ((Vector) connections.get(l[0])).addElement(l[1]);
            ((Vector) connections.get(l[1])).addElement(l[0]);
        }

        l = split(readLine().trim());

        parents.clear();
        String from = l[0], to = l[1];
        parents.put(from, from);
        if (!connections.containsKey(from) || !connections.containsKey(to)) {
            System.out.println("No route");
            return;
        }

        queue.removeAllElements();
        queue.addElement(from);

        while (queue.size() != 0) {

            String next = (String) queue.elementAt(0);
            queue.removeElementAt(0);

            v = ((Vector) connections.get(next));
            for (int i = 0; i != v.size(); i++) {
                String overNext = (String) v.elementAt(i);
                if (overNext.equals(to)) {
                    String t = next, s = "";
                    while (t != from) {
                        s = parents.get(t) + " " + t + "\n" + s;
                        t = (String) parents.get(t);
                    }
                    s += (next + " " + to);
                    System.out.println(s);
                    return;
                }
                if (!parents.containsKey(overNext)) {
                    queue.addElement(overNext);
                    parents.put(overNext, next);
                }
            }

        }

        System.out.println("No route");

    }

    public static void main(String args[]) throws Exception {

        int caso = 0;

        do {
            if (caso++ != 0) {
                System.out.println();
            }
            new Main();
        } while (readLine() != null);

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

}