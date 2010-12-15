import java.io.IOException;
import java.util.StringTokenizer;
class Main {
static String readLine(int max) throws IOException {
 int i = 0, character = -1;
 byte lin[] = new byte[max];
 while (i < max) {
 character = System.in.read();
 if ((character < 0) || (character == '\n')) break;
 lin[i++] += character;
 }
 // eof
 if ((character < 0) && (i == 0)) { return (null); }
 return (new String(lin, 0, i));
}
public static void main(String[] args) throws IOException {
 int n = Integer.parseInt(readLine(100).trim());
 while (n-- != 0) {
 String s = readLine(200);
 StringTokenizer tokens = new StringTokenizer(s);
 BigInteger n1 = new BigInteger((tokens.nextToken()));
 tokens.nextElement();
 BigInteger n2 = new BigInteger((tokens.nextToken()));
 BigInteger gc = n1.gcd(n2);
 n1 = n1.divide(gc);
 n2 = n2.divide(gc);
 System.out.println(n1 + " / " + n2);
 }
}
}
class MutableBigInteger {
int[] value;
int intLen;
int offset = 0;
private static long LONG_MASK = 0xffffffffL;
MutableBigInteger() {
 value = new int[1];
 intLen = 0;
}
MutableBigInteger(int[] val) {
 value = val;
 intLen = val.length;
}
MutableBigInteger(BigInteger b) {
 value = (int[]) b.mag.clone();
 intLen = value.length;
}
private void clear() {
 offset = intLen = 0;
 for (int index = 0, n = value.length; index < n; index++)
  value[index] = 0;
}
private int compare(MutableBigInteger b) {
 if (intLen < b.intLen) return -1;
 if (intLen > b.intLen) return 1;
 for (int i = 0; i < intLen; i++) {
 int b1 = value[offset + i] + 0x80000000;
 int b2 = b.value[b.offset + i] + 0x80000000;
 if (b1 < b2) return -1;
 if (b1 > b2) return 1;
 }
 return 0;
}
private int getLowestSetBit() {
 if (intLen == 0) return -1;
 int j, b;
 for (j = intLen - 1; (j > 0) && (value[j + offset] == 0); j--);
 b = value[j + offset];
 if (b == 0) return -1;
 int n = ((intLen - 1 - j) << 5);
 return n + BigInteger.trailingZeroCnt(b);
}
private void normalize() {
 if (intLen == 0) {
 offset = 0;
 return;
 }
 int index = offset;
 if (value[index] != 0) return;
 int indexBound = index + intLen;
 do {
 index++;
 } while (index < indexBound && value[index] == 0);
 int numZeros = index - offset;
 intLen -= numZeros;
 offset = (intLen == 0 ? 0 : offset + numZeros);
}
private void setValue(int[] val, int length) {
 value = val;
 intLen = length;
 offset = 0;
}
private void copyValue(MutableBigInteger val) {
 int len = val.intLen;
 if (value.length < len) value = new int[len];
 for (int i = 0; i < len; i++)
  value[i] = val.value[val.offset + i];
 intLen = len;
 offset = 0;
}
public String toString() {
 BigInteger b = new BigInteger(this, 1);
 return b.toString();
}
private void rightShift(int n) {
 if (intLen == 0) return;
 int nInts = n >>> 5;
 int nBits = n & 0x1F;
 this.intLen -= nInts;
 if (nBits == 0) return;
 int bitsInHighWord = BigInteger.bitLen(value[offset]);
 if (nBits >= bitsInHighWord) {
 this.primitiveLeftShift(32 - nBits);
 this.intLen--;
 } else {
 primitiveRightShift(nBits);
 }
}
private void leftShift(int n) {
 if (intLen == 0) return;
 int nInts = n >>> 5;
 int nBits = n & 0x1F;
 int bitsInHighWord = BigInteger.bitLen(value[offset]);
 // If shift can be done without moving words, do so
 if (n <= (32 - bitsInHighWord)) {
 primitiveLeftShift(nBits);
 return;
 }
 int newLen = intLen + nInts + 1;
 if (nBits <= (32 - bitsInHighWord)) newLen--;
 if (value.length < newLen) {
 // The array must grow
 int[] result = new int[newLen];
 for (int i = 0; i < intLen; i++)
  result[i] = value[offset + i];
 setValue(result, newLen);
 } else if (value.length - offset >= newLen) {
 // Use space on right
 for (int i = 0; i < newLen - intLen; i++)
  value[offset + intLen + i] = 0;
 } else {
 // Must use space on left
 for (int i = 0; i < intLen; i++)
  value[i] = value[offset + i];
 for (int i = intLen; i < newLen; i++)
  value[i] = 0;
 offset = 0;
 }
 intLen = newLen;
 if (nBits == 0) return;
 if (nBits <= (32 - bitsInHighWord)) primitiveLeftShift(nBits);
 else primitiveRightShift(32 - nBits);
}
private int divadd(int[] a, int[] result, int offset) {
 long carry = 0;
 for (int j = a.length - 1; j >= 0; j--) {
 long sum = (a[j] & LONG_MASK) + (result[j + offset] & LONG_MASK) + carry;
 result[j + offset] = (int) sum;
 carry = sum >>> 32;
 }
 return (int) carry;
}
private int mulsub(int[] q, int[] a, int x, int len, int offset) {
 long xLong = x & LONG_MASK;
 long carry = 0;
 offset += len;
 for (int j = len - 1; j >= 0; j--) {
 long product = (a[j] & LONG_MASK) * xLong + carry;
 long difference = q[offset] - product;
 q[offset--] = (int) difference;
 carry = (product >>> 32) + (((difference & LONG_MASK) > (((~(int) product) & LONG_MASK))) ? 1 : 0);
 }
 return (int) carry;
}
private void primitiveRightShift(int n) {
 int[] val = value;
 int n2 = 32 - n;
 for (int i = offset + intLen - 1, c = val[i]; i > offset; i--) {
 int b = c;
 c = val[i - 1];
 val[i] = (c << n2) | (b >>> n);
 }
 val[offset] >>>= n;
}
private void primitiveLeftShift(int n) {
 int[] val = value;
 int n2 = 32 - n;
 for (int i = offset, c = val[i], m = i + intLen - 1; i < m; i++) {
 int b = c;
 c = val[i + 1];
 val[i] = (b << n) | (c >>> n2);
 }
 val[offset + intLen - 1] <<= n;
}
private int difference(MutableBigInteger b) {
 MutableBigInteger a = this;
 int sign = a.compare(b);
 if (sign == 0) return 0;
 if (sign < 0) {
 MutableBigInteger tmp = a;
 a = b;
 b = tmp;
 }
 long diff = 0;
 int x = a.intLen;
 int y = b.intLen;
 // Subtract common parts of both numbers
 while (y > 0) {
 x--;
 y--;
 diff = (a.value[a.offset + x] & LONG_MASK) - (b.value[b.offset + y] & LONG_MASK) - ((int) -(diff >> 32));
 a.value[a.offset + x] = (int) diff;
 }
 // Subtract remainder of longer number
 while (x > 0) {
 x--;
 diff = (a.value[a.offset + x] & LONG_MASK) - ((int) -(diff >> 32));
 a.value[a.offset + x] = (int) diff;
 }
 a.normalize();
 return sign;
}
private void divideOneWord(int divisor, MutableBigInteger quotient) {
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
 if (quotient.value.length < intLen) quotient.value = new int[intLen];
 quotient.offset = 0;
 quotient.intLen = intLen;
 // Normalize the divisor
 int shift = 32 - BigInteger.bitLen(divisor);
 int rem = value[offset];
 long remLong = rem & LONG_MASK;
 if (remLong < divLong) {
 quotient.value[0] = 0;
 } else {
 quotient.value[0] = (int) (remLong / divLong);
 rem = (int) (remLong - (quotient.value[0] * divLong));
 remLong = rem & LONG_MASK;
 }
 int xlen = intLen;
 int[] qWord = new int[2];
 while (--xlen > 0) {
 long dividendEstimate = (remLong << 32) | (value[offset + intLen - xlen] & LONG_MASK);
 if (dividendEstimate >= 0) {
 qWord[0] = (int) (dividendEstimate / divLong);
 qWord[1] = (int) (dividendEstimate - (qWord[0] * divLong));
 } else {
 divWord(qWord, dividendEstimate, divisor);
 }
 quotient.value[intLen - xlen] = (int) qWord[0];
 rem = (int) qWord[1];
 remLong = rem & LONG_MASK;
 }
 // Unnormalize
 if (shift > 0) value[0] = rem %= divisor;
 else value[0] = rem;
 intLen = (value[0] == 0) ? 0 : 1;
 quotient.normalize();
}
void divide(MutableBigInteger b, MutableBigInteger quotient, MutableBigInteger rem) {
 if (b.intLen == 0) throw new ArithmeticException("BigInteger divide by zero");
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
 for (int i = 0; i < b.intLen; i++)
  d[i] = b.value[b.offset + i];
 int dlen = b.intLen;
 // Remainder starts as dividend with space for a leading zero
 if (rem.value.length < intLen + 1) rem.value = new int[intLen + 1];
 for (int i = 0; i < intLen; i++)
  rem.value[i + 1] = value[i + offset];
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
 for (int j = 0; j < limit; j++) {
 // D3 Calculate qhat
 // estimate qhat
 int qhat = 0;
 int qrem = 0;
 boolean skipCorrection = false;
 int nh = rem.value[j + rem.offset];
 int nh2 = nh + 0x80000000;
 int nm = rem.value[j + 1 + rem.offset];
 if (nh == dh) {
 qhat = ~0;
 qrem = nh + nm;
 skipCorrection = qrem + 0x80000000 < nh2;
 } else {
 long nChunk = (((long) nh) << 32) | (nm & LONG_MASK);
 if (nChunk >= 0) {
 qhat = (int) (nChunk / dhLong);
 qrem = (int) (nChunk - (qhat * dhLong));
 } else {
 divWord(qWord, nChunk, dh);
 qhat = qWord[0];
 qrem = qWord[1];
 }
 }
 if (qhat == 0) continue;
 if (!skipCorrection) { // Correct qhat
 long nl = rem.value[j + 2 + rem.offset] & LONG_MASK;
 long rs = ((qrem & LONG_MASK) << 32) | nl;
 long estProduct = (dl & LONG_MASK) * (qhat & LONG_MASK);
 if (unsignedLongCompare(estProduct, rs)) {
 qhat--;
 qrem = (int) ((qrem & LONG_MASK) + dhLong);
 if ((qrem & LONG_MASK) >= dhLong) {
 estProduct = (dl & LONG_MASK) * (qhat & LONG_MASK);
 rs = ((qrem & LONG_MASK) << 32) | nl;
 if (unsignedLongCompare(estProduct, rs)) qhat--;
 }
 }
 }
 // D4 Multiply and subtract
 rem.value[j + rem.offset] = 0;
 int borrow = mulsub(rem.value, d, qhat, dlen, j + rem.offset);
 // D5 Test remainder
 if (borrow + 0x80000000 > nh2) {
 // D6 Add back
 divadd(d, rem.value, j + 1 + rem.offset);
 qhat--;
 }
 // Store the quotient digit
 q[j] = qhat;
 } // D7 loop on j
 // D8 Unnormalize
 if (shift > 0) rem.rightShift(shift);
 rem.normalize();
 quotient.normalize();
}
private boolean unsignedLongCompare(long one, long two) {
 return (one + Long.MIN_VALUE) > (two + Long.MIN_VALUE);
}
private void divWord(int[] result, long n, int d) {
 long dLong = d & LONG_MASK;
 if (dLong == 1) {
 result[0] = (int) n;
 result[1] = 0;
 return;
 }
 // Approximate the quotient and remainder
 long q = (n >>> 1) / (dLong >>> 1);
 long r = n - q * dLong;
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
 result[0] = (int) q;
 result[1] = (int) r;
}
MutableBigInteger hybridGCD(MutableBigInteger b) {
 // Use Euclid's algorithm until the numbers are approximately the
 // same length, then use the binary GCD algorithm to find the GCD.
 MutableBigInteger a = this;
 MutableBigInteger q = new MutableBigInteger(), r = new MutableBigInteger();
 while (b.intLen != 0) {
 if (Math.abs(a.intLen - b.intLen) < 2) return a.binaryGCD(b);
 a.divide(b, q, r);
 MutableBigInteger swapper = a;
 a = b;
 b = r;
 r = swapper;
 }
 return a;
}
private MutableBigInteger binaryGCD(MutableBigInteger v) {
 // Algorithm B from Knuth section 4.5.2
 MutableBigInteger u = this;
 MutableBigInteger r = new MutableBigInteger();
 // step B1
 int s1 = u.getLowestSetBit();
 int s2 = v.getLowestSetBit();
 int k = (s1 < s2) ? s1 : s2;
 if (k != 0) {
 u.rightShift(k);
 v.rightShift(k);
 }
 // step B2
 boolean uOdd = (k == s1);
 MutableBigInteger t = uOdd ? v : u;
 int tsign = uOdd ? -1 : 1;
 int lb;
 while ((lb = t.getLowestSetBit()) >= 0) {
 // steps B3 and B4
 t.rightShift(lb);
 // step B5
 if (tsign > 0) u = t;
 else v = t;
 // Special case one word numbers
 if (u.intLen < 2 && v.intLen < 2) {
 int x = u.value[u.offset];
 int y = v.value[v.offset];
 x = binaryGcd(x, y);
 r.value[0] = x;
 r.intLen = 1;
 r.offset = 0;
 if (k > 0) r.leftShift(k);
 return r;
 }
 // step B6
 if ((tsign = u.difference(v)) == 0) break;
 t = (tsign >= 0) ? u : v;
 }
 if (k > 0) u.leftShift(k);
 return u;
}
static int binaryGcd(int a, int b) {
 if (b == 0) return a;
 if (a == 0) return b;
 int x;
 int aZeros = 0;
 while ((x = (int) a & 0xff) == 0) {
 a >>>= 8;
 aZeros += 8;
 }
 int y = BigInteger.trailingZeroTable[x];
 aZeros += y;
 a >>>= y;
 int bZeros = 0;
 while ((x = (int) b & 0xff) == 0) {
 b >>>= 8;
 bZeros += 8;
 }
 y = BigInteger.trailingZeroTable[x];
 bZeros += y;
 b >>>= y;
 int t = (aZeros < bZeros ? aZeros : bZeros);
 while (a != b) {
 if ((a + 0x80000000) > (b + 0x80000000)) { // a > b as unsigned
 a -= b;
 while ((x = (int) a & 0xff) == 0)
  a >>>= 8;
 a >>>= BigInteger.trailingZeroTable[x];
 } else {
 b -= a;
 while ((x = (int) b & 0xff) == 0)
  b >>>= 8;
 b >>>= BigInteger.trailingZeroTable[x];
 }
 }
 return a << t;
}
}
class BigInteger {
int signum;
int[] mag;
private int bitCount = -1;
private int bitLength = -1;
private int firstNonzeroIntNum = -2;
private static long LONG_MASK = 0xffffffffL;
public BigInteger(byte[] val) {
 if (val.length == 0) throw new NumberFormatException("Zero ");
 if (val[0] < 0) {
 mag = makePositive(val);
 signum = -1;
 } else {
 mag = stripLeadingZeroBytes(val);
 signum = (mag.length == 0 ? 0 : 1);
 }
}
public BigInteger(int signum, byte[] magnitude) {
 this.mag = stripLeadingZeroBytes(magnitude);
 if (signum < -1 || signum > 1) throw (new NumberFormatException("Invalid "));
 if (this.mag.length == 0) {
 this.signum = 0;
 } else {
 if (signum == 0) throw (new NumberFormatException("signum"));
 this.signum = signum;
 }
}
public BigInteger(String val, int radix) {
 int cursor = 0, numDigits;
 int len = val.length();
 if (radix < Character.MIN_RADIX || radix > Character.MAX_RADIX) throw new NumberFormatException("Radix out ");
 if (val.length() == 0) throw new NumberFormatException("Zero ");
 // Check for minus sign
 signum = 1;
 int index = val.lastIndexOf("-");
 if (index != -1) {
 if (index == 0) {
 if (val.length() == 1) throw new NumberFormatException("Zero ");
 signum = -1;
 cursor = 1;
 } else {
 throw new NumberFormatException("Illegal embedded minus sign");
 }
 }
 // Skip leading zeros and compute number of digits in magnitude
 while (cursor < len && Character.digit(val.charAt(cursor), radix) == 0)
  cursor++;
 if (cursor == len) {
 signum = 0;
 mag = ZERO.mag;
 return;
 }
 numDigits = len - cursor;
 // Pre-allocate array of expected size. May be too large but can
 // never be too small. Typically exact.
 int numBits = (int) (((numDigits * bitsPerDigit[radix]) >>> 10) + 1);
 int numWords = (numBits + 31) / 32;
 mag = new int[numWords];
 // Process first (potentially short) digit group
 int firstGroupLen = numDigits % digitsPerInt[radix];
 if (firstGroupLen == 0) firstGroupLen = digitsPerInt[radix];
 String group = val.substring(cursor, cursor += firstGroupLen);
 mag[mag.length - 1] = Integer.parseInt(group, radix);
 if (mag[mag.length - 1] < 0) throw new NumberFormatException("Illegal digit");
 // Process remaining digit groups
 int superRadix = intRadix[radix];
 int groupVal = 0;
 while (cursor < val.length()) {
 group = val.substring(cursor, cursor += digitsPerInt[radix]);
 groupVal = Integer.parseInt(group, radix);
 if (groupVal < 0) throw new NumberFormatException("Illegal digit");
 destructiveMulAdd(mag, superRadix, groupVal);
 }
 // Required for cases where the array was overallocated.
 mag = trustedStripLeadingZeroInts(mag);
}
BigInteger(char[] val) {
 int cursor = 0, numDigits;
 int len = val.length;
 // Check for leading minus sign
 signum = 1;
 if (val[0] == '-') {
 if (len == 1) throw new NumberFormatException("Zero ");
 signum = -1;
 cursor = 1;
 }
 // Skip leading zeros and compute number of digits in magnitude
 while (cursor < len && Character.digit(val[cursor], 10) == 0)
  cursor++;
 if (cursor == len) {
 signum = 0;
 mag = ZERO.mag;
 return;
 }
 numDigits = len - cursor;
 // Pre-allocate array of expected size
 int numWords;
 if (len < 10) {
 numWords = 1;
 } else {
 int numBits = (int) (((numDigits * bitsPerDigit[10]) >>> 10) + 1);
 numWords = (numBits + 31) / 32;
 }
 mag = new int[numWords];
 // Process first (potentially short) digit group
 int firstGroupLen = numDigits % digitsPerInt[10];
 if (firstGroupLen == 0) firstGroupLen = digitsPerInt[10];
 mag[mag.length - 1] = parseInt(val, cursor, cursor += firstGroupLen);
 // Process remaining digit groups
 while (cursor < len) {
 int groupVal = parseInt(val, cursor, cursor += digitsPerInt[10]);
 destructiveMulAdd(mag, intRadix[10], groupVal);
 }
 mag = trustedStripLeadingZeroInts(mag);
}
private int parseInt(char[] source, int start, int end) {
 int result = Character.digit(source[start++], 10);
 if (result == -1) throw new NumberFormatException(new String(source));
 for (int index = start; index < end; index++) {
 int nextVal = Character.digit(source[index], 10);
 if (nextVal == -1) throw new NumberFormatException(new String(source));
 result = 10 * result + nextVal;
 }
 return result;
}
// bitsPerDigit in the given radix times 1024
// Rounded up to avoid underallocation.
private static long bitsPerDigit[] = { 0, 0, 1024, 1624, 2048, 2378, 2648, 2875, 3072, 3247, 3402, 3543, 3672, 3790, 3899, 4001, 4096, 4186, 4271, 4350, 4426, 4498, 4567, 4633, 4696, 4756, 4814, 4870, 4923, 4975, 5025, 5074, 5120, 5166, 5210, 5253, 5295 };
// Multiply x array times word y in place, and add word z
private static void destructiveMulAdd(int[] x, int y, int z) {
 // Perform the multiplication word by word
 long ylong = y & LONG_MASK;
 long zlong = z & LONG_MASK;
 int len = x.length;
 long product = 0;
 long carry = 0;
 for (int i = len - 1; i >= 0; i--) {
 product = ylong * (x[i] & LONG_MASK) + carry;
 x[i] = (int) product;
 carry = product >>> 32;
 }
 // Perform the addition
 long sum = (x[len - 1] & LONG_MASK) + zlong;
 x[len - 1] = (int) sum;
 carry = sum >>> 32;
 for (int i = len - 2; i >= 0; i--) {
 sum = (x[i] & LONG_MASK) + carry;
 x[i] = (int) sum;
 carry = sum >>> 32;
 }
}
public BigInteger(String val) {
 this(val, 10);
}
private BigInteger(int[] magnitude, int signum) {
 this.signum = (magnitude.length == 0 ? 0 : signum);
 this.mag = magnitude;
}
BigInteger(MutableBigInteger val, int sign) {
 if (val.offset > 0 || val.value.length != val.intLen) {
 mag = new int[val.intLen];
 for (int i = 0; i < val.intLen; i++)
  mag[i] = val.value[val.offset + i];
 } else {
 mag = val.value;
 }
 this.signum = (val.intLen == 0) ? 0 : sign;
}
public static BigInteger valueOf(long val) {
 if (val == 0) return ZERO;
 if (val > 0 && val <= MAX_CONSTANT) return posConst[(int) val];
 else if (val < 0 && val >= -MAX_CONSTANT) return negConst[(int) -val];
 return new BigInteger(val);
}
private BigInteger(long val) {
 if (val < 0) {
 signum = -1;
 val = -val;
 } else {
 signum = 1;
 }
 int highWord = (int) (val >>> 32);
 if (highWord == 0) {
 mag = new int[1];
 mag[0] = (int) val;
 } else {
 mag = new int[2];
 mag[0] = highWord;
 mag[1] = (int) val;
 }
}
private static int MAX_CONSTANT = 16;
private static BigInteger posConst[] = new BigInteger[MAX_CONSTANT + 1];
private static BigInteger negConst[] = new BigInteger[MAX_CONSTANT + 1];
static {
for (int i = 1; i <= MAX_CONSTANT; i++) {
int[] magnitude = new int[1];
magnitude[0] = (int) i;
posConst[i] = new BigInteger(magnitude, 1);
negConst[i] = new BigInteger(magnitude, -1);
}
}
public static BigInteger ZERO = new BigInteger(new int[0], 0);
public static BigInteger ONE = valueOf(1);
public static BigInteger TEN = valueOf(10);
public BigInteger add(BigInteger val) {
 int[] resultMag;
 if (val.signum == 0) return this;
 if (signum == 0) return val;
 if (val.signum == signum) return new BigInteger(add(mag, val.mag), signum);
 int cmp = intArrayCmp(mag, val.mag);
 if (cmp == 0) return ZERO;
 resultMag = (cmp > 0 ? subtract(mag, val.mag) : subtract(val.mag, mag));
 resultMag = trustedStripLeadingZeroInts(resultMag);
 return new BigInteger(resultMag, cmp * signum);
}
private static int[] add(int[] x, int[] y) {
 if (x.length < y.length) {
 int[] tmp = x;
 x = y;
 y = tmp;
 }
 int xIndex = x.length;
 int yIndex = y.length;
 int result[] = new int[xIndex];
 long sum = 0;
 while (yIndex > 0) {
 sum = (x[--xIndex] & LONG_MASK) + (y[--yIndex] & LONG_MASK) + (sum >>> 32);
 result[xIndex] = (int) sum;
 }
 boolean carry = (sum >>> 32 != 0);
 while (xIndex > 0 && carry)
  carry = ((result[--xIndex] = x[xIndex] + 1) == 0);
 while (xIndex > 0)
  result[--xIndex] = x[xIndex];
 if (carry) {
 int newLen = result.length + 1;
 int temp[] = new int[newLen];
 for (int i = 1; i < newLen; i++)
  temp[i] = result[i - 1];
 temp[0] = 0x01;
 result = temp;
 }
 return result;
}
public BigInteger subtract(BigInteger val) {
 int[] resultMag;
 if (val.signum == 0) return this;
 if (signum == 0) return val.negate();
 if (val.signum != signum) return new BigInteger(add(mag, val.mag), signum);
 int cmp = intArrayCmp(mag, val.mag);
 if (cmp == 0) return ZERO;
 resultMag = (cmp > 0 ? subtract(mag, val.mag) : subtract(val.mag, mag));
 resultMag = trustedStripLeadingZeroInts(resultMag);
 return new BigInteger(resultMag, cmp * signum);
}
private static int[] subtract(int[] big, int[] little) {
 int bigIndex = big.length;
 int result[] = new int[bigIndex];
 int littleIndex = little.length;
 long difference = 0;
 // Subtract common parts of both numbers
 while (littleIndex > 0) {
 difference = (big[--bigIndex] & LONG_MASK) - (little[--littleIndex] & LONG_MASK) + (difference >> 32);
 result[bigIndex] = (int) difference;
 }
 // Subtract remainder of longer number while borrow propagates
 boolean borrow = (difference >> 32 != 0);
 while (bigIndex > 0 && borrow)
  borrow = ((result[--bigIndex] = big[bigIndex] - 1) == -1);
 // Copy remainder of longer number
 while (bigIndex > 0)
  result[--bigIndex] = big[bigIndex];
 return result;
}
public BigInteger multiply(BigInteger val) {
 if (signum == 0 || val.signum == 0) return ZERO;
 int[] result = multiplyToLen(mag, mag.length, val.mag, val.mag.length, null);
 result = trustedStripLeadingZeroInts(result);
 return new BigInteger(result, signum * val.signum);
}
private int[] multiplyToLen(int[] x, int xlen, int[] y, int ylen, int[] z) {
 int xstart = xlen - 1;
 int ystart = ylen - 1;
 if (z == null || z.length < (xlen + ylen)) z = new int[xlen + ylen];
 long carry = 0;
 for (int j = ystart, k = ystart + 1 + xstart; j >= 0; j--, k--) {
 long product = (y[j] & LONG_MASK) * (x[xstart] & LONG_MASK) + carry;
 z[k] = (int) product;
 carry = product >>> 32;
 }
 z[xstart] = (int) carry;
 for (int i = xstart - 1; i >= 0; i--) {
 carry = 0;
 for (int j = ystart, k = ystart + 1 + i; j >= 0; j--, k--) {
 long product = (y[j] & LONG_MASK) * (x[i] & LONG_MASK) + (z[k] & LONG_MASK) + carry;
 z[k] = (int) product;
 carry = product >>> 32;
 }
 z[i] = (int) carry;
 }
 return z;
}
public BigInteger divide(BigInteger val) {
 MutableBigInteger q = new MutableBigInteger(), r = new MutableBigInteger(), a = new MutableBigInteger(this.mag), b = new MutableBigInteger(val.mag);
 a.divide(b, q, r);
 return new BigInteger(q, this.signum * val.signum);
}
public BigInteger[] divideAndRemainder(BigInteger val) {
 BigInteger[] result = new BigInteger[2];
 MutableBigInteger q = new MutableBigInteger(), r = new MutableBigInteger(), a = new MutableBigInteger(this.mag), b = new MutableBigInteger(val.mag);
 a.divide(b, q, r);
 result[0] = new BigInteger(q, this.signum * val.signum);
 result[1] = new BigInteger(r, this.signum);
 return result;
}
public BigInteger remainder(BigInteger val) {
 MutableBigInteger q = new MutableBigInteger(), r = new MutableBigInteger(), a = new MutableBigInteger(this.mag), b = new MutableBigInteger(val.mag);
 a.divide(b, q, r);
 return new BigInteger(r, this.signum);
}
public BigInteger gcd(BigInteger val) {
 if (val.signum == 0) return this.abs();
 else if (this.signum == 0) return val.abs();
 MutableBigInteger a = new MutableBigInteger(this);
 MutableBigInteger b = new MutableBigInteger(val);
 MutableBigInteger result = a.hybridGCD(b);
 return new BigInteger(result, 1);
}
// shifts a up to len right n bits assumes no leading zeros, 0<n<32
static void primitiveRightShift(int[] a, int len, int n) {
 int n2 = 32 - n;
 for (int i = len - 1, c = a[i]; i > 0; i--) {
 int b = c;
 c = a[i - 1];
 a[i] = (c << n2) | (b >>> n);
 }
 a[0] >>>= n;
}
// shifts a up to len left n bits assumes no leading zeros, 0<=n<32
static void primitiveLeftShift(int[] a, int len, int n) {
 if (len == 0 || n == 0) return;
 int n2 = 32 - n;
 for (int i = 0, c = a[i], m = i + len - 1; i < m; i++) {
 int b = c;
 c = a[i + 1];
 a[i] = (b << n) | (c >>> n2);
 }
 a[len - 1] <<= n;
}
private BigInteger abs() {
 return (signum >= 0 ? this : this.negate());
}
private BigInteger negate() {
 return new BigInteger(this.mag, -this.signum);
}
public int signum() {
 return this.signum;
}
public BigInteger mod(BigInteger m) {
 if (m.signum <= 0) throw new ArithmeticException("BigInteger: modulus not positive");
 BigInteger result = this.remainder(m);
 return (result.signum >= 0 ? result : result.add(m));
}
private BigInteger shiftLeft(int n) {
 if (signum == 0) return ZERO;
 if (n == 0) return this;
 if (n < 0) return shiftRight(-n);
 int nInts = n >>> 5;
 int nBits = n & 0x1f;
 int magLen = mag.length;
 int newMag[] = null;
 if (nBits == 0) {
 newMag = new int[magLen + nInts];
 for (int i = 0; i < magLen; i++)
  newMag[i] = mag[i];
 } else {
 int i = 0;
 int nBits2 = 32 - nBits;
 int highBits = mag[0] >>> nBits2;
 if (highBits != 0) {
 newMag = new int[magLen + nInts + 1];
 newMag[i++] = highBits;
 } else {
 newMag = new int[magLen + nInts];
 }
 int j = 0;
 while (j < magLen - 1)
  newMag[i++] = mag[j++] << nBits | mag[j] >>> nBits2;
 newMag[i] = mag[j] << nBits;
 }
 return new BigInteger(newMag, signum);
}
private BigInteger shiftRight(int n) {
 if (n == 0) return this;
 if (n < 0) return shiftLeft(-n);
 int nInts = n >>> 5;
 int nBits = n & 0x1f;
 int magLen = mag.length;
 int newMag[] = null;
 // Special case: entire contents shifted off the end
 if (nInts >= magLen) return (signum >= 0 ? ZERO : negConst[1]);
 if (nBits == 0) {
 int newMagLen = magLen - nInts;
 newMag = new int[newMagLen];
 for (int i = 0; i < newMagLen; i++)
  newMag[i] = mag[i];
 } else {
 int i = 0;
 int highBits = mag[0] >>> nBits;
 if (highBits != 0) {
 newMag = new int[magLen - nInts];
 newMag[i++] = highBits;
 } else {
 newMag = new int[magLen - nInts - 1];
 }
 int nBits2 = 32 - nBits;
 int j = 0;
 while (j < magLen - nInts - 1)
  newMag[i++] = (mag[j++] << nBits2) | (mag[j] >>> nBits);
 }
 if (signum < 0) {
 // Find out whether any one-bits were shifted off the end.
 boolean onesLost = false;
 for (int i = magLen - 1, j = magLen - nInts; i >= j && !onesLost; i--)
  onesLost = (mag[i] != 0);
 if (!onesLost && nBits != 0) onesLost = (mag[magLen - nInts - 1] << (32 - nBits) != 0);
 if (onesLost) newMag = javaIncrement(newMag);
 }
 return new BigInteger(newMag, signum);
}
private int[] javaIncrement(int[] val) {
 int lastSum = 0;
 for (int i = val.length - 1; i >= 0 && lastSum == 0; i--)
  lastSum = (val[i] += 1);
 if (lastSum == 0) {
 val = new int[val.length + 1];
 val[0] = 1;
 }
 return val;
}
public int bitLength() {
 if (bitLength == -1) {
 if (signum == 0) {
 bitLength = 0;
 } else {
 // Calculate the bit length of the magnitude
 int magBitLength = ((mag.length - 1) << 5) + bitLen(mag[0]);
 if (signum < 0) {
 // Check if magnitude is a power of two
 boolean pow2 = (bitCnt(mag[0]) == 1);
 for (int i = 1; i < mag.length && pow2; i++)
  pow2 = (mag[i] == 0);
 bitLength = (pow2 ? magBitLength - 1 : magBitLength);
 } else {
 bitLength = magBitLength;
 }
 }
 }
 return bitLength;
}
static int bitLen(int w) {
 // Binary search - decision tree (5 tests, rarely 6)
 return (w < 1 << 15 ? (w < 1 << 7 ? (w < 1 << 3 ? (w < 1 << 1 ? (w < 1 << 0 ? (w < 0 ? 32 : 0) : 1) : (w < 1 << 2 ? 2 : 3)) : (w < 1 << 5 ? (w < 1 << 4 ? 4 : 5) : (w < 1 << 6 ? 6 : 7))) : (w < 1 << 11 ? (w < 1 << 9 ? (w < 1 << 8 ? 8 : 9) : (w < 1 << 10 ? 10 : 11))
   : (w < 1 << 13 ? (w < 1 << 12 ? 12 : 13) : (w < 1 << 14 ? 14 : 15)))) : (w < 1 << 23 ? (w < 1 << 19 ? (w < 1 << 17 ? (w < 1 << 16 ? 16 : 17) : (w < 1 << 18 ? 18 : 19)) : (w < 1 << 21 ? (w < 1 << 20 ? 20 : 21) : (w < 1 << 22 ? 22 : 23))) : (w < 1 << 27 ? (w < 1 << 25 ? (w < 1 << 24 ? 24 : 25)
   : (w < 1 << 26 ? 26 : 27)) : (w < 1 << 29 ? (w < 1 << 28 ? 28 : 29) : (w < 1 << 30 ? 30 : 31)))));
}
static byte trailingZeroTable[] = { -25, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1,
  0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0,
  1, 0, 2, 0, 1, 0, 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0 };
public int bitCount() {
 if (bitCount == -1) {
 // Count the bits in the magnitude
 int magBitCount = 0;
 for (int i = 0; i < mag.length; i++)
  magBitCount += bitCnt(mag[i]);
 if (signum < 0) {
 // Count the trailing zeros in the magnitude
 int magTrailingZeroCount = 0, j;
 for (j = mag.length - 1; mag[j] == 0; j--)
  magTrailingZeroCount += 32;
 magTrailingZeroCount += trailingZeroCnt(mag[j]);
 bitCount = magBitCount + magTrailingZeroCount - 1;
 } else {
 bitCount = magBitCount;
 }
 }
 return bitCount;
}
private static int bitCnt(int val) {
 val -= (0xaaaaaaaa & val) >>> 1;
 val = (val & 0x33333333) + ((val >>> 2) & 0x33333333);
 val = val + (val >>> 4) & 0x0f0f0f0f;
 val += val >>> 8;
 val += val >>> 16;
 return val & 0xff;
}
static int trailingZeroCnt(int val) {
 int byteVal = val & 0xff;
 if (byteVal != 0) return trailingZeroTable[byteVal];
 byteVal = (val >>> 8) & 0xff;
 if (byteVal != 0) return trailingZeroTable[byteVal] + 8;
 byteVal = (val >>> 16) & 0xff;
 if (byteVal != 0) return trailingZeroTable[byteVal] + 16;
 byteVal = (val >>> 24) & 0xff;
 return trailingZeroTable[byteVal] + 24;
}
public int compareTo(BigInteger val) {
 return (signum == val.signum ? signum * intArrayCmp(mag, val.mag) : (signum > val.signum ? 1 : -1));
}
private static int intArrayCmp(int[] arg1, int[] arg2) {
 if (arg1.length < arg2.length) return -1;
 if (arg1.length > arg2.length) return 1;
 // Argument lengths are equal; compare the values
 for (int i = 0; i < arg1.length; i++) {
 long b1 = arg1[i] & LONG_MASK;
 long b2 = arg2[i] & LONG_MASK;
 if (b1 < b2) return -1;
 if (b1 > b2) return 1;
 }
 return 0;
}
public boolean equals(Object x) {
 // This test is just an optimization, which may or may not help
 if (x == this) return true;
 if (!(x instanceof BigInteger)) return false;
 BigInteger xInt = (BigInteger) x;
 if (xInt.signum != signum || xInt.mag.length != mag.length) return false;
 for (int i = 0; i < mag.length; i++)
  if (xInt.mag[i] != mag[i]) return false;
 return true;
}
public String toString(int radix) {
 if (signum == 0) return "0";
 if (radix < Character.MIN_RADIX || radix > Character.MAX_RADIX) radix = 10;
 // Compute upper bound on number of digit groups and allocate space
 int maxNumDigitGroups = (4 * mag.length + 6) / 7;
 String digitGroup[] = new String[maxNumDigitGroups];
 // Translate number to string, a digit group at a time
 BigInteger tmp = this.abs();
 int numGroups = 0;
 while (tmp.signum != 0) {
 BigInteger d = longRadix[radix];
 MutableBigInteger q = new MutableBigInteger(), r = new MutableBigInteger(), a = new MutableBigInteger(tmp.mag), b = new MutableBigInteger(d.mag);
 a.divide(b, q, r);
 BigInteger q2 = new BigInteger(q, tmp.signum * d.signum);
 BigInteger r2 = new BigInteger(r, tmp.signum * d.signum);
 digitGroup[numGroups++] = Long.toString(r2.longValue(), radix);
 tmp = q2;
 }
 // Put sign (if any) and first digit group into result buffer
 StringBuilder buf = new StringBuilder(numGroups * digitsPerLong[radix] + 1);
 if (signum < 0) buf.append('-');
 buf.append(digitGroup[numGroups - 1]);
 // Append remaining digit groups padded with leading zeros
 for (int i = numGroups - 2; i >= 0; i--) {
 // Prepend (any) leading zeros for this digit group
 int numLeadingZeros = digitsPerLong[radix] - digitGroup[i].length();
 if (numLeadingZeros != 0) buf.append(zeros[numLeadingZeros]);
 buf.append(digitGroup[i]);
 }
 return buf.toString();
}
private static String zeros[] = new String[64];
static {
zeros[63] = "000000000000000000000000000000000000000000000000000000000000000";
for (int i = 0; i < 63; i++)
 zeros[i] = zeros[63].substring(0, i);
}
public String toString() {
 return toString(10);
}
public long longValue() {
 long result = 0;
 for (int i = 1; i >= 0; i--)
  result = (result << 32) + (getInt(i) & LONG_MASK);
 return result;
}
private static int[] trustedStripLeadingZeroInts(int val[]) {
 int keep;
 // Find first nonzero byte
 for (keep = 0; keep < val.length && val[keep] == 0; keep++);
 // Only perform copy if necessary
 if (keep > 0) {
 int result[] = new int[val.length - keep];
 for (int i = 0; i < val.length - keep; i++)
  result[i] = val[keep + i];
 return result;
 }
 return val;
}
private static int[] stripLeadingZeroBytes(byte a[]) {
 int byteLength = a.length;
 int keep;
 // Find first nonzero byte
 for (keep = 0; keep < a.length && a[keep] == 0; keep++);
 // Allocate new array and copy relevant part of input array
 int intLength = ((byteLength - keep) + 3) / 4;
 int[] result = new int[intLength];
 int b = byteLength - 1;
 for (int i = intLength - 1; i >= 0; i--) {
 result[i] = a[b--] & 0xff;
 int bytesRemaining = b - keep + 1;
 int bytesToTransfer = Math.min(3, bytesRemaining);
 for (int j = 8; j <= 8 * bytesToTransfer; j += 8)
  result[i] |= ((a[b--] & 0xff) << j);
 }
 return result;
}
private static int[] makePositive(byte a[]) {
 int keep, k;
 int byteLength = a.length;
 // Find first non-sign (0xff) byte of input
 for (keep = 0; keep < byteLength && a[keep] == -1; keep++);
 for (k = keep; k < byteLength && a[k] == 0; k++);
 int extraByte = (k == byteLength) ? 1 : 0;
 int intLength = ((byteLength - keep + extraByte) + 3) / 4;
 int result[] = new int[intLength];
 int b = byteLength - 1;
 for (int i = intLength - 1; i >= 0; i--) {
 result[i] = a[b--] & 0xff;
 int numBytesToTransfer = Math.min(3, b - keep + 1);
 if (numBytesToTransfer < 0) numBytesToTransfer = 0;
 for (int j = 8; j <= 8 * numBytesToTransfer; j += 8)
  result[i] |= ((a[b--] & 0xff) << j);
 // Mask indicates which bits must be complemented
 int mask = -1 >>> (8 * (3 - numBytesToTransfer));
 result[i] = ~result[i] & mask;
 }
 // Add one to one's complement to generate two's complement
 for (int i = result.length - 1; i >= 0; i--) {
 result[i] = (int) ((result[i] & LONG_MASK) + 1);
 if (result[i] != 0) break;
 }
 return result;
}
private static int digitsPerLong[] = { 0, 0, 62, 39, 31, 27, 24, 22, 20, 19, 18, 18, 17, 17, 16, 16, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 12, 12 };
private static BigInteger longRadix[] = { null, null, valueOf(0x4000000000000000L), valueOf(0x383d9170b85ff80bL), valueOf(0x4000000000000000L), valueOf(0x6765c793fa10079dL), valueOf(0x41c21cb8e1000000L), valueOf(0x3642798750226111L), valueOf(0x1000000000000000L), valueOf(0x12bf307ae81ffd59L),
  valueOf(0xde0b6b3a7640000L), valueOf(0x4d28cb56c33fa539L), valueOf(0x1eca170c00000000L), valueOf(0x780c7372621bd74dL), valueOf(0x1e39a5057d810000L), valueOf(0x5b27ac993df97701L), valueOf(0x1000000000000000L), valueOf(0x27b95e997e21d9f1L), valueOf(0x5da0e1e53c5c8000L), valueOf(0xb16a458ef403f19L),
  valueOf(0x16bcc41e90000000L), valueOf(0x2d04b7fdd9c0ef49L), valueOf(0x5658597bcaa24000L), valueOf(0x6feb266931a75b7L), valueOf(0xc29e98000000000L), valueOf(0x14adf4b7320334b9L), valueOf(0x226ed36478bfa000L), valueOf(0x383d9170b85ff80bL), valueOf(0x5a3c23e39c000000L), valueOf(0x4e900abb53e6b71L),
  valueOf(0x7600ec618141000L), valueOf(0xaee5720ee830681L), valueOf(0x1000000000000000L), valueOf(0x172588ad4f5f0981L), valueOf(0x211e44f7d02c1000L), valueOf(0x2ee56725f06e5c71L), valueOf(0x41c21cb8e1000000L) };
private static int digitsPerInt[] = { 0, 0, 30, 19, 15, 13, 11, 11, 10, 9, 9, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5 };
private static int intRadix[] = { 0, 0, 0x40000000, 0x4546b3db, 0x40000000, 0x48c27395, 0x159fd800, 0x75db9c97, 0x40000000, 0x17179149, 0x3b9aca00, 0xcc6db61, 0x19a10000, 0x309f1021, 0x57f6c100, 0xa2f1b6f, 0x10000000, 0x18754571, 0x247dbc80, 0x3547667b, 0x4c4b4000, 0x6b5a6e1d, 0x6c20a40, 0x8d2d931,
  0xb640000, 0xe8d4a51, 0x1269ae40, 0x17179149, 0x1cb91000, 0x23744899, 0x2b73a840, 0x34e63b41, 0x40000000, 0x4cfa3cc1, 0x5c13d840, 0x6d91b519, 0x39aa400 };
private int signInt() {
 return (int) (signum < 0 ? -1 : 0);
}
private int getInt(int n) {
 if (n < 0) return 0;
 if (n >= mag.length) return signInt();
 int magInt = mag[mag.length - n - 1];
 return (int) (signum >= 0 ? magInt : (n <= firstNonzeroIntNum() ? -magInt : ~magInt));
}
private int firstNonzeroIntNum() {
 if (firstNonzeroIntNum == -2) {
 // Search for the first nonzero int
 int i;
 for (i = mag.length - 1; i >= 0 && mag[i] == 0; i--);
 firstNonzeroIntNum = mag.length - i - 1;
 }
 return firstNonzeroIntNum;
}
}
