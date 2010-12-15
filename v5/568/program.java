

import java.io.IOException;

class Main {

    static int maxLg = 50;

    public static void main(String args[]) throws Exception {

        String line;

        while ((line = readLine()) != null) {

            line = line.trim();
            if (line.equals("")) {
                continue;
            }

            int i = Integer.parseInt(line);

            if (i == 0) {
                System.out.println("    0 -> 1");
                continue;
            }

            int temp = i;
            int novoValor = 1;

            while (temp != 1) {

                //System.out.println("multiplicando " + novoValor + " por "
                //      + temp);

                novoValor *= temp--;

                //System.out.println("deu sem trim " + novoValor);

                while (novoValor % 10 == 0) {
                    novoValor /= 10;
                }

                //System.out.println("deu trim " + novoValor);

                novoValor %= 10000;

            }

            if (i >= 100) {
                if(i==10000) {
                } else if(i>=1000) {
                    System.out.print(" ");
                } else {
                    System.out.print("  ");
                }
            } else {
                if(i>=10) {
                    System.out.print("   ");
                } else {
                    System.out.print("    ");
                }
            }
            System.out.println(i + " -> " + (novoValor % 10));

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