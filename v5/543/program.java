

import java.io.IOException;

class Main {

    static int maxLg = 50;

    public static void main(String args[]) throws Exception {

        String line;
        boolean primos[] = new boolean[1000000];
        for (int i = 3; i <= 1000000; i++) {
            primos[i] = true;
        }

        for (int i = 3; i <= 1000000; i++) {
            if (primos[i]) {
                for (int i2 = i + i + i; i2 <= 1000000; i2 += i + i) {
                    primos[i2] = false;
                }
            }
        }

        while ((line = readLine()) != null) {

            int i = Integer.parseInt(line.trim());
            if (i == 0) {
                return;
            }

            if (i == 2) {
 //               while (true) {
                return;
   //             }
            }
            
            

        }

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