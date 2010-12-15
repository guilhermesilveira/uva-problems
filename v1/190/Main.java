// 39315

import java.io.IOException;
import java.text.NumberFormat;
import java.text.ParseException;
import java.util.StringTokenizer;

class Main190 {

	public static void main(String[] args) throws IOException, ParseException {

		NumberFormat n = NumberFormat.getNumberInstance();
		n.setGroupingUsed(false);
		n.setMaximumFractionDigits(3);
		n.setMinimumFractionDigits(3);
		//n.setMinimumIntegerDigits(0)
		
		String values[];
		
		while (true) {

			String line = readLine(300);
			if (line == null) {
				break;
			}

			// transforma tudo em double
			values = breakLine(line);
			double x1, y1;
			double x2, y2;
			double x3, y3;
			x1 = Double.valueOf(values[0]).doubleValue();
			y1 = Double.valueOf(values[1]).doubleValue();
			double A2 = x1 * x1;
			double B2 = y1 * y1;
			x2 = Double.valueOf(values[2]).doubleValue();
			y2 = Double.valueOf(values[3]).doubleValue();
			double C2 = x2 * x2;
			double D2 = y2 * y2;
			x3 = Double.valueOf(values[4]).doubleValue();
			y3 = Double.valueOf(values[5]).doubleValue();
			double E2 = x3 * x3;
			double F2 = y3 * y3;

			double A = x1, B = y1, C = x2, D = y2, E = x3, F = y3;

			double c =
				(
					- (C2 + D2 - E2 - F2) * (B - D)
					- (-A2 - B2 + C2 + D2) * (D - F))
					/ ((C - E) * (B - D) - (A - C) * (D - F));
			double d = - (A2 + B2 - C2 - D2 + c * (A - C)) / (B - D);
			double e = A2 + B2 + c * A + d * B;

			double k = -d / 2;
			double h = -c / 2;
			double r = Math.abs(Math.sqrt((A - h) * (A - h) + (B - k) * (B - k)));
			
			char kChar = '-';
			if(k<0) {
				kChar = '+';
				k = 0 - k;
			}
			k = (Math.round(k*1000))/1000.0;

			char hChar = '-';
			if(h<0) {
				hChar = '+';
				h = 0 - h;
			}
			h = (Math.round(h*1000))/1000.0;
			
			char cChar = '+';
			if(c<0) {
				cChar = '-';
				c = 0 - c;
			}
			c = (Math.round(c*1000))/1000.0;
			
			char dChar = '+';
			if(d<0) {
				dChar = '-';
				d = 0 - d;
			}
			d = (Math.round(d*1000))/1000.0;

			char eChar = '-';
			if(e<0) {
				eChar = '+';
				e = 0 - e;
			}
			e = (Math.round(e*1000))/1000.0;
			
			// (x - h)2 + (y - k)2 = r2
			System.out.println(
				"(x "+hChar + " " + n.format(h).replace(',','.') + ")^2 + (y " + kChar + " " + n.format(k).replace(',','.') + ")^2 = " + n.format(r).replace(',','.') + "^2");
			
			// x2 + y2 + cx + dy - e = 0;
			System.out.println(
				"x^2 + y^2 "+cChar+" " + n.format(c).replace(',','.') + "x "+dChar+" " + n.format(d).replace(',','.') + "y "+eChar+" " + n.format(e).replace(',','.') + " = 0");
			
			System.out.println();

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
