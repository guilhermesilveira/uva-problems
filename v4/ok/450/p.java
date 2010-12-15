import java.util.StringTokenizer;
import java.io.IOException;
import java.util.Vector;

class Main {

    static int maxLg = 500;
    static Vector v = new Vector();

    public static void readDep() throws Exception {
        	String dep = readLine().trim();
        	String s;
        	String l[];
        	while((s=readLine())!=null && !(s.trim()).equals("")) {
        	    l = split(s);
        	    P p = new P(l,dep);
        	    v.addElement(p);
        	}
    }
    
    public static void sort(Vector v) {
        int n = v.size();
        Vector v2 = new Vector();
        char us[] = new char[n];
        int j, t,i;
        P p1, p2;
        for(i=0;i<n;i++) {
            p1 = null;
            t = -1;
            for(j=0;j<n;j++) {
                if(us[j]==1) continue;
                p2 = (P) v.elementAt(j);
                if(p1==null || p1.compareTo(p2)>0) {
                    t = j;
                    p1 = p2;
                }
            }
            us[t] = 1;
            v2.addElement(p1);
        }
        v.removeAllElements();
        for(i=0;i!=n;i++) {
            v.addElement(v2.elementAt(i));
        }
    }

    public static void main(String args[]) throws Exception {
        int dep = Integer.parseInt(readLine().trim());
        for(int i=0;i!=dep;i++) {
            readDep();
        }
        sort(v);
        int n = v.size();
        for(int i=0;i!=n;i++) {
            P p1 = (P) v.elementAt(i);
            p1.print();
        }
    }

    static String[] split(String s) {
        StringTokenizer st = new StringTokenizer(s, ",");
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

class P {
    
    String title, first, last, address;
    String dep, home, work, campus;
    
    public P(String[] s,String dep) {
        title = s[0];
        first = s[1];
        last = s[2];
        address = s[3];
        this.dep = dep;
        home = s[4];
        work = s[5];
        campus = s[6];
    }
    
    public void print() {
        System.out.println("----------------------------------------");
        System.out.println(title + " " + first + " " + last);
        System.out.println(address);
        System.out.println("Department: " + dep);
        System.out.println("Home Phone: " + home);
        System.out.println("Work Phone: " + work);
        System.out.println("Campus Box: " + campus);
    }
    
    public int compareTo(Object o) {
        P p = (P) o;
        return this.last.compareTo(p.last);
        //return 0;
    }
    
}

