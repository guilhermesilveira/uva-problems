// shellsort

import java.io.*;
import java.text.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
        
	String linha;
        int casos = Integer.parseInt(readLine().trim());
        
            for(int i = 0; i <casos; i++) {

                int tartarugas = Integer.parseInt(readLine().trim());

                Vector fromList = new Vector();
                for(int t = 0; t <tartarugas; t++) {
                    fromList.addElement(readLine().trim());
                }
                
                Vector to = new Vector();
                for(int t = 0; t <tartarugas; t++) {
                    to.addElement(readLine().trim());
                }
                
                Vector miniPilha = new Vector(); 

                int posFrom = tartarugas - 1;
                int posTo = tartarugas - 1;
                while(posFrom != -1) {
                    
                    if(miniPilha.contains(to.elementAt(posTo))) {
                        break;
                    }
                    
                    if(fromList.elementAt(posFrom).equals(to.elementAt(posTo))) {
                        posFrom--;
                        posTo--;
                    } else {
                        // adiciona ele na pilha
                        miniPilha.addElement(fromList.elementAt(posFrom));
                        posFrom--;
                    }
                    
                }
                
                if(i!=0) System.out.println();
                
                while(posTo!=-1) {
                    System.out.println(to.elementAt(posTo--));
                }
                
            }
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
