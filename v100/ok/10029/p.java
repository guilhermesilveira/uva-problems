

import java.util.*;
import java.io.*;

class Main {

    static int maxLg = 200;

    private static HashSet hs = new HashSet();

    public static void main(String args[]) throws Exception {
        
        String line;
        long b, a, parsed[];
        double d;
        
        while ((line = readLine()) != null) {
            hs.add(line.trim());
        }
        
        //Collections.sort(hs);
        
        TreeSet hs = new TreeSet(hs);
        
        if(true) return;
        
        /*
         * for (int i = 0; i != hs.size(); i++) { System.out.println(hs.get(i)); }
         */
        
        String s1, s2;

        int vet[] = new int[hs.size()];
        int tam[] = new int[hs.size()];
        byte val[][] = new byte[hs.size()][30];
        int i = 0 ;
        for(Iterator it = hs.iterator();it.hasNext();) {
            vet[i] = 1;
            s1 = (String) it.next();
            tam[i] = s1.length();
            val[i] = s1.getBytes();
            i++;
        }
        
        int max = 1;
        
        int l1, l2;
        for (i = 0; i != hs.size(); i++) {
            l1 = tam[i];
            for (int j = i + 1; j < hs.size(); j++) {
                /*if (vet[i] + 1 <= vet[j]) {
                    continue;
                }*/
                /*
                 * s2 = (String) hs.get(j); l2 = tam[j]; if (Math.abs(l1 - l2) >
                 * 1) { // nao pode ser, cancela continue; }
                 */
                //if (l1 == l2) {
                    // so pode ter uma troca
                  //  boolean mudou = false;
                    /*
                     * for (int k = 0; k != l1; k++) { if (s1.charAt(k) !=
                     * s2.charAt(k)) { if (mudou) continue; mudou = true; } } if
                     * (mudou) { vet[j] = vet[i] + 1; } continue;
                     */
                //}
            }
        }
        System.out.println(max);
    }

    static String[] split(String s) {
        StringTokenizer st = new StringTokenizer(s, " ");
        String[] tokens = new String[st.countTokens()];
        for (int i = 0; i != tokens.length; i++) {
            tokens[i] = st.nextToken();
        }
        return tokens;
    }
    
    static BufferedReader reader =new BufferedReader(new InputStreamReader(System.in));

    // le uma linha inteira
    static String readLine() throws IOException {

        return reader.readLine();

    }

}
