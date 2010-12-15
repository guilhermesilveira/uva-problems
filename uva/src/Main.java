import java.io.IOException;
import java.io.InputStream;

class Main {

	static InputStream in = System.in;
	static int instanceCount = 0;

	public static void main(String[] args) throws Exception {
		while(true) {
			String str = readLine();
			if(str==null)
				return;
			int max = Integer.parseInt(str.trim());
			if(max==0) {
				System.out.println("0!\n1");
				continue;
			}
			BigInteger t  = new BigInteger(1);
			for(int i=1;i!=max+1;i++) {
				t = t.multiply(new BigInteger(i));
			}
			System.out.println(max + "!");
			System.out.println(t.toString(10));
		}
	}
	
	static String readLine() throws IOException {
		return readLine(500);
	}

	static String readLine(int max) throws IOException {

		int i = 0, character = -1;
		byte lin[] = new byte[max];

		while (i < max) {
			character = in.read();
			if ((character < 0) || (character == '\n'))
				break;
			lin[i++] += character;
		}

		// eof
		if ((character < 0) && (i == 0)) {
			return (null);
		}
		return (new String(lin, 0, i));

	}

}

class BigInteger {
	 int signum;
	 int[] mag;
	 private int bitCount =  -1;
	 private int bitLength = -1;
	 private int firstNonzeroIntNum = -2;
	 private final static long LONG_MASK = 0xffffffffL;

	static void primitiveLeftShift(int[] a, int len, int n) {
		if (len == 0 || n == 0)
			return;

		int n2 = 32 - n;
		for (int i=0, c=a[i], m=i+len-1; i<m; i++) {
			int b = c;
			c = a[i+1];
			a[i] = (b << n) | (c >>> n2);
		}
		a[len-1] <<= n;
	}

	 private BigInteger(int[] magnitude, int signum) {
this.signum = (magnitude.length==0 ? 0 : signum);
this.mag = magnitude;
	 }

	 BigInteger(long val) {
		 if (val < 0) {
			 signum = -1;
			 val = -val;
		 } else {
			 signum = 1;
		 }

		 int highWord = (int)(val >>> 32);
		 if (highWord==0) {
			 mag = new int[1];
			 mag[0] = (int)val;
		 } else {
			 mag = new int[2];
			 mag[0] = highWord;
			 mag[1] = (int)val;
		 }
	 }

	 private final static int MAX_CONSTANT = 16;
	 private static BigInteger posConst[] = new BigInteger[MAX_CONSTANT+1];
	 private static BigInteger negConst[] = new BigInteger[MAX_CONSTANT+1];
	 static {
for (int i = 1; i <= MAX_CONSTANT; i++) {
	int[] magnitude = new int[1];
	magnitude[0] = (int) i;
	posConst[i] = new BigInteger(magnitude,  1);
	negConst[i] = new BigInteger(magnitude, -1);
}
	 }

	 public BigInteger multiply(BigInteger val) {
		 int[] result = multiplyToLen(mag, mag.length,
									  val.mag, val.mag.length, null);
		 result = trustedStripLeadingZeroInts(result);
		 return new BigInteger(result, signum*val.signum);
	 }

	 private int[] multiplyToLen(int[] x, int xlen, int[] y, int ylen, int[] z) {
		 int xstart = xlen - 1;
		 int ystart = ylen - 1;

		 if (z == null || z.length < (xlen+ ylen))
			 z = new int[xlen+ylen];

		 long carry = 0;
		 for (int j=ystart, k=ystart+1+xstart; j>=0; j--, k--) {
			 long product = (y[j] & LONG_MASK) *
							(x[xstart] & LONG_MASK) + carry;
			 z[k] = (int)product;
			 carry = product >>> 32;
		 }
		 z[xstart] = (int)carry;

		 for (int i = xstart-1; i >= 0; i--) {
			 carry = 0;
			 for (int j=ystart, k=ystart+1+i; j>=0; j--, k--) {
				 long product = (y[j] & LONG_MASK) *
								(x[i] & LONG_MASK) +
								(z[k] & LONG_MASK) + carry;
				 z[k] = (int)product;
				 carry = product >>> 32;
			 }
			 z[i] = (int)carry;
		 }
		 return z;
	 }

	 public BigInteger abs() {
return (signum >= 0 ? this : this.negate());
	 }

	 public BigInteger negate() {
return new BigInteger(this.mag, -this.signum);
	 }

	 public int bitLength() {
if (bitLength == -1) {
	if (signum == 0) {
bitLength = 0;
	} else {
// Calculate the bit length of the magnitude
int magBitLength = ((mag.length-1) << 5) + bitLen(mag[0]);

if (signum < 0) {
	// Check if magnitude is a power of two
	boolean pow2 = (bitCnt(mag[0]) == 1);
	for(int i=1; i<mag.length && pow2; i++)
pow2 = (mag[i]==0);

	bitLength = (pow2 ? magBitLength-1 : magBitLength);
} else {
	bitLength = magBitLength;
}
	}
}
return bitLength;
	 }

	 static int bitLen(int w) {
		 // Binary search - decision tree (5 tests, rarely 6)
		 return
		  (w < 1<<15 ?
		   (w < 1<<7 ?
			(w < 1<<3 ?
			 (w < 1<<1 ? (w < 1<<0 ? (w<0 ? 32 : 0) : 1) : (w < 1<<2 ? 2 : 3)) :
			 (w < 1<<5 ? (w < 1<<4 ? 4 : 5) : (w < 1<<6 ? 6 : 7))) :
			(w < 1<<11 ?
			 (w < 1<<9 ? (w < 1<<8 ? 8 : 9) : (w < 1<<10 ? 10 : 11)) :
			 (w < 1<<13 ? (w < 1<<12 ? 12 : 13) : (w < 1<<14 ? 14 : 15)))) :
		   (w < 1<<23 ?
			(w < 1<<19 ?
			 (w < 1<<17 ? (w < 1<<16 ? 16 : 17) : (w < 1<<18 ? 18 : 19)) :
			 (w < 1<<21 ? (w < 1<<20 ? 20 : 21) : (w < 1<<22 ? 22 : 23))) :
			(w < 1<<27 ?
			 (w < 1<<25 ? (w < 1<<24 ? 24 : 25) : (w < 1<<26 ? 26 : 27)) :
			 (w < 1<<29 ? (w < 1<<28 ? 28 : 29) : (w < 1<<30 ? 30 : 31)))));
	 }

	 final static byte trailingZeroTable[] = {
	   -25, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0};

	 public int bitCount() {
if (bitCount == -1) {
	// Count the bits in the magnitude
	int magBitCount = 0;
	for (int i=0; i<mag.length; i++)
magBitCount += bitCnt(mag[i]);

	if (signum < 0) {
// Count the trailing zeros in the magnitude
int magTrailingZeroCount = 0, j;
for (j=mag.length-1; mag[j]==0; j--)
	magTrailingZeroCount += 32;
magTrailingZeroCount +=
							 trailingZeroCnt(mag[j]);

bitCount = magBitCount + magTrailingZeroCount - 1;
	} else {
bitCount = magBitCount;
	}
}
return bitCount;
	 }

	 static int bitCnt(int val) {
		 val -= (0xaaaaaaaa & val) >>> 1;
		 val = (val & 0x33333333) + ((val >>> 2) & 0x33333333);
		 val = val + (val >>> 4) & 0x0f0f0f0f;
		 val += val >>> 8;
		 val += val >>> 16;
		 return val & 0xff;
	 }

	 static int trailingZeroCnt(int val) {
		 // Loop unrolled for performance
		 int byteVal = val & 0xff;
		 if (byteVal != 0)
			 return trailingZeroTable[byteVal];

		 byteVal = (val >>> 8) & 0xff;
		 if (byteVal != 0)
			 return trailingZeroTable[byteVal] + 8;

		 byteVal = (val >>> 16) & 0xff;
		 if (byteVal != 0)
			 return trailingZeroTable[byteVal] + 16;

		 byteVal = (val >>> 24) & 0xff;
		 return trailingZeroTable[byteVal] + 24;
	 }

	 public int hashCode() {
int hashCode = 0;

for (int i=0; i<mag.length; i++)
	hashCode = (int)(31*hashCode + (mag[i] & LONG_MASK));

return hashCode * signum;
	 }

	 public byte[] toByteArray() {
		 int byteLen = bitLength()/8 + 1;
		 byte[] byteArray = new byte[byteLen];

		 for (int i=byteLen-1, bytesCopied=4, nextInt=0, intIndex=0; i>=0; i--) {
			 if (bytesCopied == 4) {
				 nextInt = getInt(intIndex++);
				 bytesCopied = 1;
			 } else {
				 nextInt >>>= 8;
				 bytesCopied++;
			 }
			 byteArray[i] = (byte)nextInt;
		 }
		 return byteArray;
	 }

	 private static int[] trustedStripLeadingZeroInts(int val[]) {
		 int keep;

// Find first nonzero byte
		 for (keep=0; keep<val.length && val[keep]==0; keep++)
			 ;

		 // Only perform copy if necessary
		 if (keep > 0) {
			 int result[] = new int[val.length - keep];
			 for(int i=0; i<val.length - keep; i++)
				result[i] = val[keep+i];
			 return result;
		 }
		 return val;
	 }

	 private int signInt() {
return (int) (signum < 0 ? -1 : 0);
	 }

	 private int getInt(int n) {
		 if (n < 0)
			 return 0;
if (n >= mag.length)
	return signInt();

int magInt = mag[mag.length-n-1];

return (int) (signum >= 0 ? magInt :
	   (n <= firstNonzeroIntNum() ? -magInt : ~magInt));
	 }

	BigInteger(MutableBigInteger val, int sign) {
		if (val.offset > 0 || val.value.length != val.intLen) {
			mag = new int[val.intLen];
			for(int i=0; i<val.intLen; i++)
				mag[i] = val.value[val.offset+i];
		} else {
			mag = val.value;
		}

	this.signum = (val.intLen == 0) ? 0 : sign;
	}

	  private int firstNonzeroIntNum() {
if (firstNonzeroIntNum == -2) {
	// Search for the first nonzero int
	int i;
	for (i=mag.length-1; i>=0 && mag[i]==0; i--)
;
	firstNonzeroIntNum = mag.length-i-1;
}
return firstNonzeroIntNum;
	 }

	 public String toString(int radix) {
if (signum == 0)
	return "0";
if (radix < Character.MIN_RADIX || radix > Character.MAX_RADIX)
	radix = 10;

// Compute upper bound on number of digit groups and allocate space
int maxNumDigitGroups = (4*mag.length + 6)/7;
String digitGroup[] = new String[maxNumDigitGroups];

// Translate number to string, a digit group at a time
BigInteger tmp = this.abs();
int numGroups = 0;
while (tmp.signum != 0) {
			 BigInteger d = longRadix[radix];

			 MutableBigInteger q = new MutableBigInteger(),
							   r = new MutableBigInteger(),
							   a = new MutableBigInteger(tmp.mag),
							   b = new MutableBigInteger(d.mag);
			 a.divide(b, q, r);
			 BigInteger q2 = new BigInteger(q, tmp.signum * d.signum);
			 BigInteger r2 = new BigInteger(r, tmp.signum * d.signum);

			 digitGroup[numGroups++] = Long.toString(r2.longValue(), radix);
			 tmp = q2;
}

// Put sign (if any) and first digit group into result buffer
StringBuffer buf = new StringBuffer(numGroups*digitsPerLong[radix]+1);
if (signum<0)
	buf.append('-');
buf.append(digitGroup[numGroups-1]);

// Append remaining digit groups padded with leading zeros
for (int i=numGroups-2; i>=0; i--) {
	// Prepend (any) leading zeros for this digit group
	int numLeadingZeros = digitsPerLong[radix]-digitGroup[i].length();
	if (numLeadingZeros != 0)
buf.append(zeros[numLeadingZeros]);
	buf.append(digitGroup[i]);
}
return buf.toString();
	 }

	 /* zero[i] is a string of i consecutive zeros. */
	 private static String zeros[] = new String[64];
	 static {
zeros[63] =
	"000000000000000000000000000000000000000000000000000000000000000";
for (int i=0; i<63; i++)
	zeros[i] = zeros[63].substring(0, i);
	 }

	 private static int digitsPerLong[] = {0, 0,
62, 39, 31, 27, 24, 22, 20, 19, 18, 18, 17, 17, 16, 16, 15, 15, 15, 14,
14, 14, 14, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 12, 12};

	 private static BigInteger longRadix[] = {null, null,
		 valueOf(0x4000000000000000L), valueOf(0x383d9170b85ff80bL),
valueOf(0x4000000000000000L), valueOf(0x6765c793fa10079dL),
valueOf(0x41c21cb8e1000000L), valueOf(0x3642798750226111L),
		 valueOf(0x1000000000000000L), valueOf(0x12bf307ae81ffd59L),
valueOf( 0xde0b6b3a7640000L), valueOf(0x4d28cb56c33fa539L),
valueOf(0x1eca170c00000000L), valueOf(0x780c7372621bd74dL),
valueOf(0x1e39a5057d810000L), valueOf(0x5b27ac993df97701L),
valueOf(0x1000000000000000L), valueOf(0x27b95e997e21d9f1L),
valueOf(0x5da0e1e53c5c8000L), valueOf( 0xb16a458ef403f19L),
valueOf(0x16bcc41e90000000L), valueOf(0x2d04b7fdd9c0ef49L),
valueOf(0x5658597bcaa24000L), valueOf( 0x6feb266931a75b7L),
valueOf( 0xc29e98000000000L), valueOf(0x14adf4b7320334b9L),
valueOf(0x226ed36478bfa000L), valueOf(0x383d9170b85ff80bL),
valueOf(0x5a3c23e39c000000L), valueOf( 0x4e900abb53e6b71L),
valueOf( 0x7600ec618141000L), valueOf( 0xaee5720ee830681L),
valueOf(0x1000000000000000L), valueOf(0x172588ad4f5f0981L),
valueOf(0x211e44f7d02c1000L), valueOf(0x2ee56725f06e5c71L),
valueOf(0x41c21cb8e1000000L)};

	 public static BigInteger valueOf(long val) {
// If -MAX_CONSTANT < val < MAX_CONSTANT, return stashed constant
if (val == 0)
	return ZERO;
if (val > 0 && val <= MAX_CONSTANT)
	return posConst[(int) val];
else if (val < 0 && val >= -MAX_CONSTANT)
	return negConst[(int) -val];

return new BigInteger(val);
	 }

	public static final BigInteger ZERO = new BigInteger(new int[0], 0);

	 public long longValue() {
long result = 0;

for (int i=1; i>=0; i--)
	result = (result << 32) + (getInt(i) & LONG_MASK);
return result;
	 }

}



class MutableBigInteger {
	int[] value;
	int intLen;
	int offset = 0;
	private final static long LONG_MASK = 0xffffffffL;
	MutableBigInteger() {
		value = new int[1];
		intLen = 0;
	}

	/**
	 * Construct a new MutableBigInteger with a magnitude specified by
	 * the int val.
	 */
	MutableBigInteger(int val) {
		value = new int[1];
		intLen = 1;
		value[0] = val;
	}

	/**
	 * Construct a new MutableBigInteger with the specified value array
	 * up to the specified length.
	 */
	MutableBigInteger(int[] val, int len) {
		value = val;
		intLen = len;
	}

	/**
	 * Construct a new MutableBigInteger with the specified value array
	 * up to the length of the array supplied.
	 */
	MutableBigInteger(int[] val) {
		value = val;
		intLen = val.length;
	}

	/**
	 * Construct a new MutableBigInteger with a magnitude equal to the
	 * specified BigInteger.
	 */
	MutableBigInteger(BigInteger b) {
		value = (int[]) b.mag.clone();
		intLen = value.length;
	}

	/**
	 * Construct a new MutableBigInteger with a magnitude equal to the
	 * specified MutableBigInteger.
	 */
	MutableBigInteger(MutableBigInteger val) {
		intLen = val.intLen;
		value = new int[intLen];

		for(int i=0; i<intLen; i++)
			value[i] = val.value[val.offset+i];
	}

	/**
	 * Clear out a MutableBigInteger for reuse.
	 */
	void clear() {
		offset = intLen = 0;
		for (int index=0, n=value.length; index < n; index++)
			value[index] = 0;
	}

	final int compare(MutableBigInteger b) {
		if (intLen < b.intLen)
			return -1;
		if (intLen > b.intLen)
			return 1;

		for (int i=0; i<intLen; i++) {
			int b1 = value[offset+i]     + 0x80000000;
			int b2 = b.value[b.offset+i] + 0x80000000;
			if (b1 < b2)
				return -1;
			if (b1 > b2)
				return 1;
		}
		return 0;
	}

	/**
	 * Ensure that the MutableBigInteger is in normal form, specifically
	 * making sure that there are no leading zeros, and that if the
	 * magnitude is zero, then intLen is zero.
	 */
	final void normalize() {
		if (intLen == 0) {
			offset = 0;
			return;
		}

		int index = offset;
		if (value[index] != 0)
			return;

		int indexBound = index+intLen;
		do {
			index++;
		} while(index < indexBound && value[index]==0);

		int numZeros = index - offset;
		intLen -= numZeros;
		offset = (intLen==0 ?  0 : offset+numZeros);
	}

	/**
	 * Sets the int at index+offset in this MutableBigInteger to val.
	 * This does not get inlined on all platforms so it is not used
	 * as often as originally intended.
	 */
	void setInt(int index, int val) {
		value[offset + index] = val;
	}

	/**
	 * Sets this MutableBigInteger's value array to the specified array.
	 * The intLen is set to the specified length.
	 */
	void setValue(int[] val, int length) {
		value = val;
		intLen = length;
		offset = 0;
	}

	/**
	 * Sets this MutableBigInteger's value array to a copy of the specified
	 * array. The intLen is set to the length of the new array.
	 */
	void copyValue(MutableBigInteger val) {
		int len = val.intLen;
		if (value.length < len)
			value = new int[len];

		for(int i=0; i<len; i++)
			value[i] = val.value[val.offset+i];
		intLen = len;
		offset = 0;
	}

	/**
	 * Returns a String representation of this MutableBigInteger in radix 10.
	 */
	public String toString() {
		BigInteger b = new BigInteger(this, 1);
		return b.toString();
	}

	/**
	 * Right shift this MutableBigInteger n bits. The MutableBigInteger is left
	 * in normal form.
	 */
	void rightShift(int n) {
		if (intLen == 0)
			return;
		int nInts = n >>> 5;
		int nBits = n & 0x1F;
		this.intLen -= nInts;
		if (nBits == 0)
			return;
		int bitsInHighWord = BigInteger.bitLen(value[offset]);
		if (nBits >= bitsInHighWord) {
			this.primitiveLeftShift(32 - nBits);
			this.intLen--;
		} else {
			primitiveRightShift(nBits);
		}
	}

	/**
	 * Left shift this MutableBigInteger n bits. 
	 */
	void leftShift(int n) {
		/*
		 * If there is enough storage space in this MutableBigInteger already
		 * the available space will be used. Space to the right of the used
		 * ints in the value array is faster to utilize, so the extra space
		 * will be taken from the right if possible.
		 */
		if (intLen == 0)
		   return;
		int nInts = n >>> 5;
		int nBits = n&0x1F;
		int bitsInHighWord = BigInteger.bitLen(value[offset]);
        
		// If shift can be done without moving words, do so
		if (n <= (32-bitsInHighWord)) {
			primitiveLeftShift(nBits);
			return;
		}

		int newLen = intLen + nInts +1;
		if (nBits <= (32-bitsInHighWord))
			newLen--;
		if (value.length < newLen) {
			// The array must grow
			int[] result = new int[newLen];
			for (int i=0; i<intLen; i++)
				result[i] = value[offset+i];
			setValue(result, newLen);
		} else if (value.length - offset >= newLen) {
			// Use space on right
			for(int i=0; i<newLen - intLen; i++)
				value[offset+intLen+i] = 0;
		} else {
			// Must use space on left
			for (int i=0; i<intLen; i++)
				value[i] = value[offset+i];
			for (int i=intLen; i<newLen; i++)
				value[i] = 0;
			offset = 0;
		}
		intLen = newLen;
		if (nBits == 0)
			return;
		if (nBits <= (32-bitsInHighWord))
			primitiveLeftShift(nBits);
		else
			primitiveRightShift(32 -nBits);
	}

	/**
	 * A primitive used for division. This method adds in one multiple of the
	 * divisor a back to the dividend result at a specified offset. It is used
	 * when qhat was estimated too large, and must be adjusted.
	 */
	private int divadd(int[] a, int[] result, int offset) {
		long carry = 0;

		for (int j=a.length-1; j >= 0; j--) {
			long sum = (a[j] & LONG_MASK) + 
					   (result[j+offset] & LONG_MASK) + carry;
			result[j+offset] = (int)sum;
			carry = sum >>> 32;
		}
		return (int)carry;
	}

	/**
	 * This method is used for division. It multiplies an n word input a by one
	 * word input x, and subtracts the n word product from q. This is needed
	 * when subtracting qhat*divisor from dividend.
	 */
	private int mulsub(int[] q, int[] a, int x, int len, int offset) {
		long xLong = x & LONG_MASK;
		long carry = 0;
		offset += len;

		for (int j=len-1; j >= 0; j--) {
			long product = (a[j] & LONG_MASK) * xLong + carry;
			long difference = q[offset] - product;
			q[offset--] = (int)difference;
			carry = (product >>> 32)
					 + (((difference & LONG_MASK) >
						 (((~(int)product) & LONG_MASK))) ? 1:0);
		}
		return (int)carry;
	}

	/**
	 * Right shift this MutableBigInteger n bits, where n is
	 * less than 32.
	 * Assumes that intLen > 0, n > 0 for speed
	 */
	private final void primitiveRightShift(int n) {
		int[] val = value;
		int n2 = 32 - n;
		for (int i=offset+intLen-1, c=val[i]; i>offset; i--) {
			int b = c;
			c = val[i-1];
			val[i] = (c << n2) | (b >>> n);
		}
		val[offset] >>>= n;
	}

	/**
	 * Left shift this MutableBigInteger n bits, where n is
	 * less than 32.
	 * Assumes that intLen > 0, n > 0 for speed
	 */
	private final void primitiveLeftShift(int n) {
		int[] val = value;
		int n2 = 32 - n;
		for (int i=offset, c=val[i], m=i+intLen-1; i<m; i++) {
			int b = c;
			c = val[i+1];
			val[i] = (b << n) | (c >>> n2);
		}
		val[offset+intLen-1] <<= n;
	}

	/**
	 * Adds the contents of two MutableBigInteger objects.The result
	 * is placed within this MutableBigInteger.
	 * The contents of the addend are not changed.
	 */
	void add(MutableBigInteger addend) {
		int x = intLen;
		int y = addend.intLen;
		int resultLen = (intLen > addend.intLen ? intLen : addend.intLen);
		int[] result = (value.length < resultLen ? new int[resultLen] : value);

		int rstart = result.length-1;
		long sum = 0;

		// Add common parts of both numbers
		while(x>0 && y>0) {
			x--; y--;
			sum = (value[x+offset] & LONG_MASK) +
				(addend.value[y+addend.offset] & LONG_MASK) + (sum >>> 32);
			result[rstart--] = (int)sum;
		}

		// Add remainder of the longer number
		while(x>0) {
			x--;
			sum = (value[x+offset] & LONG_MASK) + (sum >>> 32);
			result[rstart--] = (int)sum;
		}
		while(y>0) {
			y--;
			sum = (addend.value[y+addend.offset] & LONG_MASK) + (sum >>> 32);
			result[rstart--] = (int)sum;
		}

		if ((sum >>> 32) > 0) { // Result must grow in length
			resultLen++;
			if (result.length < resultLen) {
				int temp[] = new int[resultLen];
				for (int i=resultLen-1; i>0; i--)
					temp[i] = result[i-1];
				temp[0] = 1;
				result = temp;
			} else {
				result[rstart--] = 1;
			}
		}

		value = result;
		intLen = resultLen;
		offset = result.length - resultLen;
	}


	void multiply(MutableBigInteger y, MutableBigInteger z) {
		int xLen = intLen;
		int yLen = y.intLen;
		int newLen = xLen + yLen;

		// Put z into an appropriate state to receive product
		if (z.value.length < newLen)
			z.value = new int[newLen];
		z.offset = 0;
		z.intLen = newLen;

		// The first iteration is hoisted out of the loop to avoid extra add
		long carry = 0;
		for (int j=yLen-1, k=yLen+xLen-1; j >= 0; j--, k--) {
				long product = (y.value[j+y.offset] & LONG_MASK) *
							   (value[xLen-1+offset] & LONG_MASK) + carry;
				z.value[k] = (int)product;
				carry = product >>> 32;
		}
		z.value[xLen-1] = (int)carry;

		// Perform the multiplication word by word
		for (int i = xLen-2; i >= 0; i--) {
			carry = 0;
			for (int j=yLen-1, k=yLen+i; j >= 0; j--, k--) {
				long product = (y.value[j+y.offset] & LONG_MASK) *
							   (value[i+offset] & LONG_MASK) +
							   (z.value[k] & LONG_MASK) + carry;
				z.value[k] = (int)product;
				carry = product >>> 32;
			}
			z.value[i] = (int)carry;
		}

		// Remove leading zeros from product
		z.normalize();
	}

	/**
	 * Multiply the contents of this MutableBigInteger by the word y. The
	 * result is placed into z.
	 */
	void mul(int y, MutableBigInteger z) {
		if (y == 1) {
			z.copyValue(this);
			return;
		}
            
		if (y == 0) {
			z.clear();
			return;
		}

		// Perform the multiplication word by word
		long ylong = y & LONG_MASK;
		int[] zval = (z.value.length<intLen+1 ? new int[intLen + 1]
											  : z.value);
		long carry = 0;
		for (int i = intLen-1; i >= 0; i--) {
			long product = ylong * (value[i+offset] & LONG_MASK) + carry;
			zval[i+1] = (int)product;
			carry = product >>> 32;
		}

		if (carry == 0) {
			z.offset = 1;
			z.intLen = intLen;
		} else {
			z.offset = 0;
			z.intLen = intLen + 1;
			zval[0] = (int)carry;
		}
		z.value = zval;
	}

	void divideOneWord(int divisor, MutableBigInteger quotient) {
		long divLong = divisor & LONG_MASK;

		// Special case of one word dividend
		if (intLen == 1) {
			long remValue = value[offset] & LONG_MASK;
			quotient.value[0] = (int) (remValue / divLong);
			quotient.intLen = (quotient.value[0] == 0) ? 0 : 1;
			quotient.offset = 0;

			value[0] = (int) (remValue - (quotient.value[0] * divLong));
			offset = 0;
			intLen = (value[0] == 0) ? 0 : 1;
           
			return;
		}

		if (quotient.value.length < intLen)
			quotient.value = new int[intLen];
		quotient.offset = 0;
		quotient.intLen = intLen;

		// Normalize the divisor
		int shift = 32 - BigInteger.bitLen(divisor);

	int rem = value[offset];
		long remLong = rem & LONG_MASK;
	if (remLong < divLong) {
			quotient.value[0] = 0;
	} else {
			quotient.value[0] = (int)(remLong/divLong);
			rem = (int) (remLong - (quotient.value[0] * divLong));
			remLong = rem & LONG_MASK;
	}

	int xlen = intLen; 
		int[] qWord = new int[2];
	while (--xlen > 0) {
			long dividendEstimate = (remLong<<32) |
				(value[offset + intLen - xlen] & LONG_MASK);
			if (dividendEstimate >= 0) {
				qWord[0] = (int) (dividendEstimate/divLong);
				qWord[1] = (int) (dividendEstimate - (qWord[0] * divLong));
			} else {
				divWord(qWord, dividendEstimate, divisor);
			}
			quotient.value[intLen - xlen] = (int)qWord[0];
			rem = (int)qWord[1];
			remLong = rem & LONG_MASK;
		}
        
		// Unnormalize
		if (shift > 0)
			value[0] = rem %= divisor;
		else
			value[0] = rem;
		intLen = (value[0] == 0) ? 0 : 1;
        
		quotient.normalize();
	}



	/**
	 * Compare two longs as if they were unsigned.
	 * Returns true iff one is bigger than two.
	 */
	private boolean unsignedLongCompare(long one, long two) {
		return (one+Long.MIN_VALUE) > (two+Long.MIN_VALUE);
	}

	/**
	 * This method divides a long quantity by an int to estimate
	 * qhat for two multi precision numbers. It is used when 
	 * the signed value of n is less than zero.
	 */
	private void divWord(int[] result, long n, int d) {
		long dLong = d & LONG_MASK;

		if (dLong == 1) {
			result[0] = (int)n;
			result[1] = 0;
			return;
		}
                
		// Approximate the quotient and remainder
		long q = (n >>> 1) / (dLong >>> 1);
		long r = n - q*dLong;

		// Correct the approximation
		while (r < 0) {
			r += dLong;
			q--;
		}
		while (r >= dLong) {
			r -= dLong;
			q++;
		}

		// n - q*dlong == r && 0 <= r <dLong, hence we're done.
		result[0] = (int)q;
		result[1] = (int)r;
	}

	void divide(MutableBigInteger b,
						MutableBigInteger quotient, MutableBigInteger rem) {  
		if (b.intLen == 0)
			throw new ArithmeticException("BigInteger divide by zero");

		// Dividend is zero
		if (intLen == 0) {
			quotient.intLen = quotient.offset = rem.intLen = rem.offset = 0;
			return;
		}
 
		int cmp = compare(b);

		// Dividend less than divisor
		if (cmp < 0) {
			quotient.intLen = quotient.offset = 0;
			rem.copyValue(this);
			return;
		}
		// Dividend equal to divisor
		if (cmp == 0) {
			quotient.value[0] = quotient.intLen = 1;
			quotient.offset = rem.intLen = rem.offset = 0;
			return;
		}

		quotient.clear();

		// Special case one word divisor
		if (b.intLen == 1) {
			rem.copyValue(this);
			rem.divideOneWord(b.value[b.offset], quotient);
			return;
		}

		// Copy divisor value to protect divisor
		int[] d = new int[b.intLen];
		for(int i=0; i<b.intLen; i++)
			d[i] = b.value[b.offset+i];
		int dlen = b.intLen;

		// Remainder starts as dividend with space for a leading zero
		if (rem.value.length < intLen +1)
			rem.value = new int[intLen+1];

		for (int i=0; i<intLen; i++)
			rem.value[i+1] = value[i+offset];
		rem.intLen = intLen;
		rem.offset = 1;

		int nlen = rem.intLen;

		// Set the quotient size
		int limit = nlen - dlen + 1;
		if (quotient.value.length < limit) {
			quotient.value = new int[limit];
			quotient.offset = 0;
		}
		quotient.intLen = limit;
		int[] q = quotient.value;
        
		// D1 normalize the divisor
		int shift = 32 - BigInteger.bitLen(d[0]);
		if (shift > 0) {
			// First shift will not grow array
			BigInteger.primitiveLeftShift(d, dlen, shift);
			// But this one might
			rem.leftShift(shift);
		}
       
		// Must insert leading 0 in rem if its length did not change
		if (rem.intLen == nlen) {
			rem.offset = 0;
			rem.value[0] = 0;
			rem.intLen++;
		}

		int dh = d[0];
		long dhLong = dh & LONG_MASK;
		int dl = d[1];
		int[] qWord = new int[2];
        
		// D2 Initialize j
		for(int j=0; j<limit; j++) {
			// D3 Calculate qhat
			// estimate qhat
			int qhat = 0;
			int qrem = 0;
			boolean skipCorrection = false;
			int nh = rem.value[j+rem.offset];
			int nh2 = nh + 0x80000000;
			int nm = rem.value[j+1+rem.offset];

			if (nh == dh) {
				qhat = ~0;
				qrem = nh + nm;
				skipCorrection = qrem + 0x80000000 < nh2;
			} else {
				long nChunk = (((long)nh) << 32) | (nm & LONG_MASK);
				if (nChunk >= 0) {
					qhat = (int) (nChunk / dhLong);
					qrem = (int) (nChunk - (qhat * dhLong));
				} else {
					divWord(qWord, nChunk, dh);
					qhat = qWord[0];
					qrem = qWord[1];
				}
			}

			if (qhat == 0)
				continue;
            
			if (!skipCorrection) { // Correct qhat
				long nl = rem.value[j+2+rem.offset] & LONG_MASK;
				long rs = ((qrem & LONG_MASK) << 32) | nl;
				long estProduct = (dl & LONG_MASK) * (qhat & LONG_MASK);

				if (unsignedLongCompare(estProduct, rs)) {
					qhat--;
					qrem = (int)((qrem & LONG_MASK) + dhLong);
					if ((qrem & LONG_MASK) >=  dhLong) {
						estProduct = (dl & LONG_MASK) * (qhat & LONG_MASK);
						rs = ((qrem & LONG_MASK) << 32) | nl;
						if (unsignedLongCompare(estProduct, rs))
							qhat--;
					}
				}
			}

			// D4 Multiply and subtract    
			rem.value[j+rem.offset] = 0;
			int borrow = mulsub(rem.value, d, qhat, dlen, j+rem.offset);

			// D5 Test remainder
			if (borrow + 0x80000000 > nh2) {
				// D6 Add back
				divadd(d, rem.value, j+1+rem.offset);
				qhat--;
			}

			// Store the quotient digit
			q[j] = qhat;
		} // D7 loop on j

		// D8 Unnormalize
		if (shift > 0)
			rem.rightShift(shift);

		rem.normalize();
		quotient.normalize();
	}
}
