import java.io.*;
import java.util.*;

class Main {

	static String readLine (int maxLg)  // utility function to read from stdin
	{
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
        }

	static int n;
	static int[] s;
	static int soma;
	static int meio;

	public static boolean begin(int depth, int atual) {

		if(atual>meio) return false;

		if(depth==n) {
			return atual==meio;
		}

		if(begin(depth+1,atual+s[depth]) || begin(depth+1,atual)) return true;

		return false;

	}

	public static void start(int[] sz) {

		s = sz;
		n = s.length;
		soma = 0;
		for(int i=0;i!=n;i++) {
			soma += s[i];
		}
		if(soma%2==1) {
			System.out.println("NO");
			return;
		}
		meio = soma / 2;
		for(int i=0;i!=n;i++) {
			if(s[i]>meio) {
				System.out.println("NO");
				return;
			}
			if(s[i]==meio) {
				System.out.println("YES");
				return;
			}
		}
		if(begin(0,0)) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}

	}


	public static void main(String args[])  {
		int c = Integer.parseInt(readLine(10).trim());
		while(c--!=0) start(parseNewLine());
	}

	public static int[] parseNewLine() {
		String l  = readLine(10000).trim();
		StringTokenizer st = new StringTokenizer(l);
		int[] s = new int[st.countTokens()];
		int i = 0;
		while(st.hasMoreTokens()) {
			s[i++] = Integer.parseInt(st.nextToken());
		}
		return s;
	}

}



