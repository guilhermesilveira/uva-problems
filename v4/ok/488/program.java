

import java.util.*;
import java.io.*;
import java.text.*;

class Main {

    static int maxLg = 200;

    public static void main(String args[]) throws Exception {
        
        String line;
        
        char a = 'a', z = 'z';
        char A = 'A', Z = 'Z';
        char c;
        int i, max;

        while ((line = readLine()) != null) {
            
            int map[] = new int[258];
            max = 0;
            
            for (i = 0; i != line.length(); i++) {
                
                c = line.charAt(i);
                if(c >= a && c<=z) {
                    map[c]++;
                    if(map[c]>max) {
                       max = map[c];
                    }
                } else if(c >= A && c<=Z) {
                    map[c]++;
                    if(map[c]>max) {
                       max = map[c];
                    }
                }
                
            }
            
            line = "";
            
            for (c = A; c <= Z; c++) {
                if(map[c]==max) {
                    line += "" + c;
                }
            }

            for (c = a; c <= z; c++) {
                if(map[c]==max) {
                    line += "" + c;
                }
            }
            
            System.out.println(line + " " + max);

        }
        
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