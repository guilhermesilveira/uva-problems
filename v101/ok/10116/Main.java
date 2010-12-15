import java.io.IOException;
import java.util.Hashtable;
import java.util.StringTokenizer;

class MainOk {

	public static void main(String[] args) throws IOException {

		Hashtable jaPassouPor = new Hashtable();
		
		while (true) {

			String[] line = breakLine(readLine(255));
			int rows = Integer.parseInt(line[0]);
			int cols = Integer.parseInt(line[1]);
			int x = Integer.parseInt(line[2])-1;
			int y = 0;

			// se terminou
			if (rows == 0 && cols == 0 && x == -1) {
				break;
			}

			String lines[] = new String[10];

			for (int i = 0; i != rows; i++) {
				lines[i] = readLine(255);
			}

			int steps = 0;
			
			jaPassouPor.clear();

			while (true) {

				String key = y + "," + x;
				// se ja passou nesse ponto, percebe o loop
				if (jaPassouPor.containsKey(key)) {
					System.out.println(
						jaPassouPor.get(key)
							+ " step(s) before a loop of "
							+ (steps
								- ((Integer) jaPassouPor.get(key)).intValue())
							+ " step(s)");
					break;
				}

				jaPassouPor.put(key, new Integer(steps));

				// executa a posicao atual
				if (lines[y].charAt(x) == 'N') {
					y--;
				} else if (lines[y].charAt(x) == 'S') {
					y++;
				} else if (lines[y].charAt(x) == 'E') {
					x++;
				} else if (lines[y].charAt(x) == 'W') {
					x--;
				}

				steps++;
				
				//System.out.println(x + "," + y);

				// se passou do ok
				if (y >= rows || y<0 || x<0 || x>=cols) {
					System.out.println(steps + " step(s) to exit");
					break;
				}

			}
			
		}

	}

	static String[] breakLine(String s) {
		StringTokenizer st = new StringTokenizer(s, " ");
		String[] tokens = new String[st.countTokens()];
		for (int i = 0; i != tokens.length; i++) {
			tokens[i] = st.nextToken();
		}
		return tokens;
	}

	// le uma linha inteira
	static String readLine(int maxLg) throws IOException {
		byte lin[] = new byte[maxLg];
		int lg = 0, car = -1;
		while (lg < maxLg) {
			car = System.in.read();
			if ((car < 0) || (car == '\n'))
				break;
			lin[lg++] += car;
		}
		if ((car < 0) && (lg == 0))
			return (null); // eof
		return (new String(lin, 0, lg));
	}
}
