

import java.util.*;
import java.io.*;
import java.text.*;

class Main {

    static int maxLg = 15;

    public static void main(String args[]) throws Exception {

        try {

            String line;
            BigNum bigNum[] = new BigNum[6000];
            bigNum[0] = BigNum.ZERO;
            bigNum[1] = BigNum.ONE;
            for (int i = 2; i != 5011; i++) {
                bigNum[i] = bigNum[i - 1].add(bigNum[i - 2]);
            }

            while ((line = readLine()) != null) {

                int i = Integer.parseInt(line);
                System.out.println("The Fibonacci number for " + i + " is "
                        + bigNum[i]);

            }
        } catch (Exception ex) {
            ex.printStackTrace();
            //while(true);
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

class BigNum {

    static final int MAX = 200;

    static final long QUOTE = 1000000000;

    static BigNum ONE = new BigNum(1);

    static BigNum ZERO = new BigNum(0);

    int max = 0;

    long[] mag;

    BigNum(int i) {
        mag = new long[MAX];
        for (int z = 0; z != MAX; z++) {
            mag[z] = 0;
        }
        while (i != 0) {
            mag[max++] = i % QUOTE;
            i /= QUOTE;
        }
    }

    BigNum(BigNum b) {
        this.max = b.max;
        mag = new long[MAX];
        for (int z = 0; z != MAX; z++) {
            mag[z] = b.mag[z];
        }
    }

    BigNum add(BigNum b) {
        BigNum a = new BigNum(this);
        for (int i = 0; i != b.max; i++) {
            a.mag[i] += b.mag[i];
            if (a.mag[i] >= QUOTE) {
                a.mag[i + 1]++;
                a.mag[i] -= QUOTE;
                if (i + 1 == a.max) {
                    a.max++;
                }
            }
        }
        return a;
    }

    public String toString() {
        StringBuffer s = new StringBuffer();
        long z, toAdd;
        for (int i = max; i != 0; i--) {
            z = mag[i - 1];
            toAdd = 9;
            while (z != 0) {
                z /= 10;
                toAdd--;
            }
            if (i != max) {
                while (toAdd-- != 0) {
                    s.append("0");
                }
            }
            s.append("" + mag[i - 1]);
        }
        if (max == 0) {
            return "0";
        }
        return s.toString();
    }

}

