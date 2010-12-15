// shellsort

import java.io.*;
import java.text.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {

        String linha;
        int casos = Integer.parseInt(readLine().trim());

        int valores[] = new int[7483647];
        long v = 2;
        for (int i = 2; i != 32; i++) {
            
            v = v * 2;
            System.out.println(i + ":  " + v);
        }
        //for (int i = 0; i < casos; i++) {

        //}
    }

    // le uma linha inteira
    static String readLine() throws IOException {

        int maxLg = 100;
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