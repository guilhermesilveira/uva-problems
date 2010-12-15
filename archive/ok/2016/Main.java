

import java.io.*;
import java.util.*;

class Data {

    int d = -1, m, h, s;

    int v, i;

    Data(String s) {
        String temp[] = Main.split(s, '@');
        String v[] = Main.split(temp[1], '.');
        val = new String[v.length + 1];
        val[0] = temp[0];
        for (int i = 0; i != v.length; i++)
            val[i + 1] = v[i];
    }

    String val[];

    Data(String s[]) {
        this(s[4]);
        d = Integer.parseInt(s[0]);
        h = Integer.parseInt(s[1]);
        m = Integer.parseInt(s[2]);
        this.s = Integer.parseInt(s[3]);
    }

    boolean antesOuIgual(Data d2) {
        if (d != d2.d)
            return d < d2.d;
        if (h != d2.h)
            return h < d2.h;
        if (m != d2.m)
            return m < d2.m;
        if (s != d2.s)
            return s < d2.s;
        // igual
        return true;
    }

    void seisHoras() {
        h += 6;
        if (h >= 24) {
            d++;
            h -= 24;
        }
    }

    public String toString() {
        return d + ":" + h + ":" + m + ":" + s;
    }

    String last() {
        return val[val.length - 1];
    }

    String secondLast() {
        return val[val.length - 2];
    }

}

class Main {

    static HashMap mapa = new HashMap();
    static HashMap mapa2 = new HashMap();

    public static void main(String args[]) throws IOException {

        String linha;
        while ((linha = readLine()) != null) {
            if (linha.charAt(0) == '3' && linha.charAt(1) == '2')
                break;
            linha = linha.toLowerCase();
            String[] partes = split(linha, ':');
            if (!mapa.containsKey(partes[4])) {
                // adiciona com dia -1
                Data d = new Data(partes[4]);
                mapa.put(partes[4], d);
            }
            Data d = new Data(partes);
            Data antiga = (Data) mapa.get(partes[4]);
            if (antiga.antesOuIgual(d)) {
                d.i = antiga.i;
                d.v = antiga.v + 1;
                d.seisHoras();
                mapa.put(partes[4], d);
            } else {
                // invalido!!!
                antiga.i++;
            }
        }

        int len = mapa.size();
        int c1 = 0;
        while (len != 0) {
            // decide o subgrupo mais ao final
            boolean found = false;
            String s = null;
            Iterator i = mapa.keySet().iterator();
            while (i.hasNext()) {
                String s2 = (String) i.next();
                Data d = (Data) mapa.get(s2);
                if (!found || d.last().compareTo(s) < 0) {
                    found = true;
                    s = d.last();
                }
            }
            if(!found) {
                break;
            }
            if(c1++!=0) System.out.println('\n');
            System.out.println("TOP-LEVEL DOMAIN = " + s);
            // ja achei o primeiro
            int c = 0;
            while (true) {
                String ss = null;
                found = false;
                i = mapa.keySet().iterator();
                while (i.hasNext()) {
                    String s2 = (String) i.next();
                    Data d = (Data) mapa.get(s2);
                    if (d.last().equals(s)
                            && (!found || (d.secondLast().compareTo(ss)) < 0)) {
                        found = true;
                        ss = d.secondLast();
                    }
                }
                if (!found)
                    break;
                if (c++ != 0)
                    System.out.println();
                System.out.println("Second level domain = " + ss);
                i = mapa.keySet().iterator();
                Vector v = new Vector();
                while (i.hasNext()) {
                    String s2 = (String) i.next();
                    Data d = (Data) mapa.get(s2);
                    if (s.equals(d.last()) && ss.equals(d.secondLast())) {
                        len--;
                        v.addElement(s2);
                        mapa.remove(s2);
                        mapa2.put(s2,d);
                    }
                }
                sort(v);
                for(int ki=0;ki!=v.size();ki++) {
                    String s3 = (String) v.elementAt(ki);
                    System.out.print(s3.trim());
                    Data d = (Data) mapa2.get(s3);
                    System.out.println(" " + d.v + " " + d.i);
                }
            }
        }

    }

    public static void sort(Vector v) {
        int n = v.size();
        String[] v2 = new String[n];
        char us[] = new char[n];
        int j, t,i;
        String p1, p2;
        for(i=0;i<n;i++) {
            p1 = null;
            t = -1;
            for(j=0;j<n;j++) {
                if(us[j]==1) continue;
                p2 = (String) v.elementAt(j);
                if(p1==null || p1.compareTo(p2)>0) {
                    t = j;
                    p1 = p2;
                }
            }
            us[t] = 1;
            v2[i] = (p1);
        }
        v.removeAllElements();
        for(i=0;i!=n;i++) {
            v.addElement(v2[i]);
        }
    }

    static String[] split(String s, char c) {
        StringTokenizer st = new StringTokenizer(s, c + "");
        String[] sz = new String[st.countTokens()];
        int i = 0;
        while (st.hasMoreTokens()) {
            sz[i++] = (String) st.nextToken();
        }
        return sz;
    }

    static int maxLg = 150;

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

class HashMap extends AbstractMap {

    static final int DEFAULT_INITIAL_CAPACITY = 16;

    static final int MAXIMUM_CAPACITY = 1 << 30;

    static final float DEFAULT_LOAD_FACTOR = 0.75f;

    transient Entry[] table;

    transient int size;

    int threshold;

    final float loadFactor;

    transient volatile int modCount;

    public HashMap(int initialCapacity, float loadFactor) {
        if (initialCapacity < 0)
            throw new IllegalArgumentException("Illegal initial capacity: "
                    + initialCapacity);
        if (initialCapacity > MAXIMUM_CAPACITY)
            initialCapacity = MAXIMUM_CAPACITY;
        if (loadFactor <= 0 || Float.isNaN(loadFactor))
            throw new IllegalArgumentException("Illegal load factor: "
                    + loadFactor);

        // Find a power of 2 >= initialCapacity
        int capacity = 1;
        while (capacity < initialCapacity)
            capacity <<= 1;

        this.loadFactor = loadFactor;
        threshold = (int) (capacity * loadFactor);
        table = new Entry[capacity];
        init();
    }

    public HashMap(int initialCapacity) {
        this(initialCapacity, DEFAULT_LOAD_FACTOR);
    }

    public HashMap() {
        this.loadFactor = DEFAULT_LOAD_FACTOR;
        threshold = (int) (DEFAULT_INITIAL_CAPACITY * DEFAULT_LOAD_FACTOR);
        table = new Entry[DEFAULT_INITIAL_CAPACITY];
        init();
    }

    public HashMap(HashMap m) {
        this(Math.max((int) (m.size() / DEFAULT_LOAD_FACTOR) + 1,
                DEFAULT_INITIAL_CAPACITY), DEFAULT_LOAD_FACTOR);
        putAllForCreate(m);
    }

    void init() {
    }

    static final Object NULL_KEY = new Object();

    static Object maskNull(Object key) {
        return (key == null ? NULL_KEY : key);
    }

    static Object unmaskNull(Object key) {
        return (key == NULL_KEY ? null : key);
    }

    static int hash(Object x) {
        int h = x.hashCode();

        h += ~(h << 9);
        h ^= (h >>> 14);
        h += (h << 4);
        h ^= (h >>> 10);
        return h;
    }

    static boolean eq(Object x, Object y) {
        return x == y || x.equals(y);
    }

    static int indexFor(int h, int length) {
        return h & (length - 1);
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public Object get(Object key) {
        Object k = maskNull(key);
        int hash = hash(k);
        int i = indexFor(hash, table.length);
        Entry e = table[i];
        while (true) {
            if (e == null)
                return e;
            if (e.hash == hash && eq(k, e.key))
                return e.value;
            e = e.next;
        }
    }

    public boolean containsKey(Object key) {
        Object k = maskNull(key);
        int hash = hash(k);
        int i = indexFor(hash, table.length);
        Entry e = table[i];
        while (e != null) {
            if (e.hash == hash && eq(k, e.key))
                return true;
            e = e.next;
        }
        return false;
    }

    Entry getEntry(Object key) {
        Object k = maskNull(key);
        int hash = hash(k);
        int i = indexFor(hash, table.length);
        Entry e = table[i];
        while (e != null && !(e.hash == hash && eq(k, e.key)))
            e = e.next;
        return e;
    }

    public Object put(Object key, Object value) {
        Object k = maskNull(key);
        int hash = hash(k);
        int i = indexFor(hash, table.length);

        for (Entry e = table[i]; e != null; e = e.next) {
            if (e.hash == hash && eq(k, e.key)) {
                Object oldValue = e.value;
                e.value = value;
                e.recordAccess(this);
                return oldValue;
            }
        }

        modCount++;
        addEntry(hash, k, value, i);
        return null;
    }

    private void putForCreate(Object key, Object value) {
        Object k = maskNull(key);
        int hash = hash(k);
        int i = indexFor(hash, table.length);

        for (Entry e = table[i]; e != null; e = e.next) {
            if (e.hash == hash && eq(k, e.key)) {
                e.value = value;
                return;
            }
        }

        createEntry(hash, k, value, i);
    }

    void putAllForCreate(HashMap m) {
        for (Iterator i = m.entrySet().iterator(); i.hasNext();) {
            Entry e = (Entry) i.next();
            putForCreate(e.getKey(), e.getValue());
        }
    }

    void resize(int newCapacity) {
        Entry[] oldTable = table;
        int oldCapacity = oldTable.length;
        if (oldCapacity == MAXIMUM_CAPACITY) {
            threshold = Integer.MAX_VALUE;
            return;
        }

        Entry[] newTable = new Entry[newCapacity];
        transfer(newTable);
        table = newTable;
        threshold = (int) (newCapacity * loadFactor);
    }

    void transfer(Entry[] newTable) {
        Entry[] src = table;
        int newCapacity = newTable.length;
        for (int j = 0; j < src.length; j++) {
            Entry e = src[j];
            if (e != null) {
                src[j] = null;
                do {
                    Entry next = e.next;
                    int i = indexFor(e.hash, newCapacity);
                    e.next = newTable[i];
                    newTable[i] = e;
                    e = next;
                } while (e != null);
            }
        }
    }

    public void putAll(HashMap m) {
        int numKeysToBeAdded = m.size();
        if (numKeysToBeAdded == 0)
            return;

        if (numKeysToBeAdded > threshold) {
            int targetCapacity = (int) (numKeysToBeAdded / loadFactor + 1);
            if (targetCapacity > MAXIMUM_CAPACITY)
                targetCapacity = MAXIMUM_CAPACITY;
            int newCapacity = table.length;
            while (newCapacity < targetCapacity)
                newCapacity <<= 1;
            if (newCapacity > table.length)
                resize(newCapacity);
        }

        for (Iterator i = m.entrySet().iterator(); i.hasNext();) {
            Entry e = (Entry) i.next();
            put(e.getKey(), e.getValue());
        }
    }

    public Object remove(Object key) {
        Entry e = removeEntryForKey(key);
        return (e == null ? e : e.value);
    }

    Entry removeEntryForKey(Object key) {
        Object k = maskNull(key);
        int hash = hash(k);
        int i = indexFor(hash, table.length);
        Entry prev = table[i];
        Entry e = prev;

        while (e != null) {
            Entry next = e.next;
            if (e.hash == hash && eq(k, e.key)) {
                modCount++;
                size--;
                if (prev == e)
                    table[i] = next;
                else
                    prev.next = next;
                e.recordRemoval(this);
                return e;
            }
            prev = e;
            e = next;
        }

        return e;
    }

    Entry removeMapping(Object o) {
        if (!(o instanceof Entry))
            return null;

        Entry entry = (Entry) o;
        Object k = maskNull(entry.getKey());
        int hash = hash(k);
        int i = indexFor(hash, table.length);
        Entry prev = table[i];
        Entry e = prev;

        while (e != null) {
            Entry next = e.next;
            if (e.hash == hash && e.equals(entry)) {
                modCount++;
                size--;
                if (prev == e)
                    table[i] = next;
                else
                    prev.next = next;
                e.recordRemoval(this);
                return e;
            }
            prev = e;
            e = next;
        }

        return e;
    }

    public void clear() {
        modCount++;
        Entry tab[] = table;
        for (int i = 0; i < tab.length; i++)
            tab[i] = null;
        size = 0;
    }

    public boolean containsValue(Object value) {
        if (value == null)
            return containsNullValue();

        Entry tab[] = table;
        for (int i = 0; i < tab.length; i++)
            for (Entry e = tab[i]; e != null; e = e.next)
                if (value.equals(e.value))
                    return true;
        return false;
    }

    private boolean containsNullValue() {
        Entry tab[] = table;
        for (int i = 0; i < tab.length; i++)
            for (Entry e = tab[i]; e != null; e = e.next)
                if (e.value == null)
                    return true;
        return false;
    }

    void addEntry(int hash, Object key, Object value, int bucketIndex) {
        table[bucketIndex] = new Entry(this, hash, key, value,
                table[bucketIndex]);
        if (size++ >= threshold)
            resize(2 * table.length);
    }

    void createEntry(int hash, Object key, Object value, int bucketIndex) {
        table[bucketIndex] = new Entry(this, hash, key, value,
                table[bucketIndex]);
        size++;
    }

    Iterator newKeyIterator() {
        return new KeyIterator(this);
    }

    Iterator newValueIterator() {
        return new ValueIterator(this);
    }

    Iterator newEntryIterator() {
        return new EntryIterator(this);
    }

    private transient Set entrySet = null;

    public Set keySet() {
        Set ks = keySet;
        return (ks != null ? ks : (keySet = new KeySet(this)));
    }

    public Collection values() {
        Collection vs = values;
        return (vs != null ? vs : (values = new Values(this)));
    }

    public Set entrySet() {
        Set es = entrySet;
        return (es != null ? es : (entrySet = new EntrySet(this)));
    }

    // These methods are used when serializing HashSets
    int capacity() {
        return table.length;
    }

    float loadFactor() {
        return loadFactor;
    }
}

interface Iterator {

    boolean hasNext();

    Object next();

    void remove();
}

interface Collection {

    int size();

    boolean isEmpty();

    boolean contains(Object o);

    Iterator iterator();

    boolean add(Object o);

    boolean remove(Object o);

    boolean containsAll(Collection c);

    boolean addAll(Collection c);

    boolean removeAll(Collection c);

    boolean retainAll(Collection c);

    void clear();

    boolean equals(Object o);

    int hashCode();
}

interface Set {

    int size();

    Iterator iterator();

    void clear();
}

abstract class AbstractSet extends AbstractCollection implements Set {

    protected AbstractSet() {
    }

    public boolean equals(Object o) {
        if (o == this)
            return true;

        if (!(o instanceof Set))
            return false;
        Collection c = (Collection) o;
        if (c.size() != size())
            return false;
        try {
            return containsAll(c);
        } catch (ClassCastException unused) {
            return false;
        } catch (NullPointerException unused) {
            return false;
        }
    }

    public int hashCode() {
        int h = 0;
        Iterator i = iterator();
        while (i.hasNext()) {
            Object obj = i.next();
            if (obj != null)
                h += obj.hashCode();
        }
        return h;
    }

    public boolean removeAll(Collection c) {
        boolean modified = false;

        if (size() > c.size()) {
            for (Iterator i = c.iterator(); i.hasNext();)
                modified |= remove(i.next());
        } else {
            for (Iterator i = iterator(); i.hasNext();) {
                if (c.contains(i.next())) {
                    i.remove();
                    modified = true;
                }
            }
        }
        return modified;
    }

}

abstract class AbstractCollection implements Collection {

    protected AbstractCollection() {
    }

    public abstract Iterator iterator();

    public abstract int size();

    public boolean isEmpty() {
        return size() == 0;
    }

    public boolean contains(Object o) {
        Iterator e = iterator();
        if (o == null) {
            while (e.hasNext())
                if (e.next() == null)
                    return true;
        } else {
            while (e.hasNext())
                if (o.equals(e.next()))
                    return true;
        }
        return false;
    }

    public boolean add(Object o) {
        throw new UnsupportedOperationException();
    }

    public boolean remove(Object o) {
        Iterator e = iterator();
        if (o == null) {
            while (e.hasNext()) {
                if (e.next() == null) {
                    e.remove();
                    return true;
                }
            }
        } else {
            while (e.hasNext()) {
                if (o.equals(e.next())) {
                    e.remove();
                    return true;
                }
            }
        }
        return false;
    }

    public boolean containsAll(Collection c) {
        Iterator e = c.iterator();
        while (e.hasNext())
            if (!contains(e.next()))
                return false;

        return true;
    }

    public boolean addAll(Collection c) {
        boolean modified = false;
        Iterator e = c.iterator();
        while (e.hasNext()) {
            if (add(e.next()))
                modified = true;
        }
        return modified;
    }

    public boolean removeAll(Collection c) {
        boolean modified = false;
        Iterator e = iterator();
        while (e.hasNext()) {
            if (c.contains(e.next())) {
                e.remove();
                modified = true;
            }
        }
        return modified;
    }

    public boolean retainAll(Collection c) {
        boolean modified = false;
        Iterator e = iterator();
        while (e.hasNext()) {
            if (!c.contains(e.next())) {
                e.remove();
                modified = true;
            }
        }
        return modified;
    }

    public void clear() {
        Iterator e = iterator();
        while (e.hasNext()) {
            e.next();
            e.remove();
        }
    }

    public String toString() {
        StringBuffer buf = new StringBuffer();
        buf.append("[");

        Iterator i = iterator();
        boolean hasNext = i.hasNext();
        while (hasNext) {
            Object o = i.next();
            buf.append(o == this ? "(this Collection)" : String.valueOf(o));
            hasNext = i.hasNext();
            if (hasNext)
                buf.append(", ");
        }

        buf.append("]");
        return buf.toString();
    }
}

abstract class AbstractMap {

    protected AbstractMap() {
    }

    public int size() {
        return entrySet().size();
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public boolean containsValue(Object value) {
        Iterator i = entrySet().iterator();
        if (value == null) {
            while (i.hasNext()) {
                Entry e = (Entry) i.next();
                if (e.getValue() == null)
                    return true;
            }
        } else {
            while (i.hasNext()) {
                Entry e = (Entry) i.next();
                if (value.equals(e.getValue()))
                    return true;
            }
        }
        return false;
    }

    public boolean containsKey(Object key) {
        Iterator i = entrySet().iterator();
        if (key == null) {
            while (i.hasNext()) {
                Entry e = (Entry) i.next();
                if (e.getKey() == null)
                    return true;
            }
        } else {
            while (i.hasNext()) {
                Entry e = (Entry) i.next();
                if (key.equals(e.getKey()))
                    return true;
            }
        }
        return false;
    }

    public Object get(Object key) {
        Iterator i = entrySet().iterator();
        if (key == null) {
            while (i.hasNext()) {
                Entry e = (Entry) i.next();
                if (e.getKey() == null)
                    return e.getValue();
            }
        } else {
            while (i.hasNext()) {
                Entry e = (Entry) i.next();
                if (key.equals(e.getKey()))
                    return e.getValue();
            }
        }
        return null;
    }

    public Object put(Object key, Object value) {
        throw new UnsupportedOperationException();
    }

    public Object remove(Object key) {
        Iterator i = entrySet().iterator();
        Entry correctEntry = null;
        if (key == null) {
            while (correctEntry == null && i.hasNext()) {
                Entry e = (Entry) i.next();
                if (e.getKey() == null)
                    correctEntry = e;
            }
        } else {
            while (correctEntry == null && i.hasNext()) {
                Entry e = (Entry) i.next();
                if (key.equals(e.getKey()))
                    correctEntry = e;
            }
        }

        Object oldValue = null;
        if (correctEntry != null) {
            oldValue = correctEntry.getValue();
            i.remove();
        }
        return oldValue;
    }

    public void putAll(AbstractMap t) {
        Iterator i = t.entrySet().iterator();
        while (i.hasNext()) {
            Entry e = (Entry) i.next();
            put(e.getKey(), e.getValue());
        }
    }

    public void clear() {
        entrySet().clear();
    }

    transient volatile Set keySet = null;

    transient volatile Collection values = null;

    public abstract Set keySet();

    public abstract Collection values();

    public abstract Set entrySet();

    public boolean equals(Object o) {
        if (o == this)
            return true;

        if (!(o instanceof HashMap))
            return false;
        HashMap t = (HashMap) o;
        if (t.size() != size())
            return false;

        try {
            Iterator i = entrySet().iterator();
            while (i.hasNext()) {
                Entry e = (Entry) i.next();
                Object key = e.getKey();
                Object value = e.getValue();
                if (value == null) {
                    if (!(t.get(key) == null && t.containsKey(key)))
                        return false;
                } else {
                    if (!value.equals(t.get(key)))
                        return false;
                }
            }
        } catch (ClassCastException unused) {
            return false;
        } catch (NullPointerException unused) {
            return false;
        }

        return true;
    }

    public int hashCode() {
        int h = 0;
        Iterator i = entrySet().iterator();
        while (i.hasNext())
            h += i.next().hashCode();
        return h;
    }

    public String toString() {
        StringBuffer buf = new StringBuffer();
        buf.append("{");

        Iterator i = entrySet().iterator();
        boolean hasNext = i.hasNext();
        while (hasNext) {
            Entry e = (Entry) (i.next());
            Object key = e.getKey();
            Object value = e.getValue();
            buf.append((key == this ? "(this Map)" : key) + "="
                    + (value == this ? "(this Map)" : value));

            hasNext = i.hasNext();
            if (hasNext)
                buf.append(", ");
        }

        buf.append("}");
        return buf.toString();
    }
}

class Entry {

    final Object key;

    Object value;

    final int hash;

    Entry next;

    HashMap map;

    Entry(HashMap map, int h, Object k, Object v, Entry n) {
        this.map = map;
        value = v;
        next = n;
        key = k;
        hash = h;
    }

    public Object getKey() {
        return map.unmaskNull(key);
    }

    public Object getValue() {
        return value;
    }

    public Object setValue(Object newValue) {
        Object oldValue = value;
        value = newValue;
        return oldValue;
    }

    public boolean equals(Object o) {
        if (!(o instanceof Entry))
            return false;
        Entry e = (Entry) o;
        Object k1 = getKey();
        Object k2 = e.getKey();
        if (k1 == k2 || (k1 != null && k1.equals(k2))) {
            Object v1 = getValue();
            Object v2 = e.getValue();
            if (v1 == v2 || (v1 != null && v1.equals(v2)))
                return true;
        }
        return false;
    }

    public int hashCode() {
        return (key == HashMap.NULL_KEY ? 0 : key.hashCode())
                ^ (value == null ? 0 : value.hashCode());
    }

    public String toString() {
        return getKey() + "=" + getValue();
    }

    void recordAccess(HashMap m) {
    }

    void recordRemoval(HashMap m) {
    }
}

abstract class HashIterator implements Iterator {

    Entry next; // next entry to return

    int expectedModCount; // For fast-fail 

    int index; // current slot 

    Entry current; // current entry

    HashMap map;

    HashIterator(HashMap map) {
        this.map = map;
        expectedModCount = map.modCount;
        Entry[] t = map.table;
        int i = t.length;
        Entry n = null;
        if (map.size != 0) { // advance to first entry
            while (i > 0 && (n = t[--i]) == null)
                ;
        }
        next = n;
        index = i;
    }

    public boolean hasNext() {
        return next != null;
    }

    Entry nextEntry() {
        Entry e = next;

        Entry n = e.next;
        Entry[] t = map.table;
        int i = index;
        while (n == null && i > 0)
            n = t[--i];
        index = i;
        next = n;
        return current = e;
    }

    public void remove() {
        if (current == null)
            throw new IllegalStateException();
        Object k = current.key;
        current = null;
        map.removeEntryForKey(k);
        expectedModCount = map.modCount;
    }

}

class ValueIterator extends HashIterator {

    ValueIterator(HashMap map) {
        super(map);
    }

    public Object next() {
        return nextEntry().value;
    }
}

class KeyIterator extends HashIterator {

    KeyIterator(HashMap map) {
        super(map);
    }

    public Object next() {
        return nextEntry().getKey();
    }
}

class EntryIterator extends HashIterator {

    EntryIterator(HashMap map) {
        super(map);
    }

    public Object next() {
        return nextEntry();
    }
}

class KeySet extends AbstractSet {

    HashMap map;

    KeySet(HashMap map) {
        this.map = map;
    }

    public Iterator iterator() {
        return map.newKeyIterator();
    }

    public int size() {
        return map.size;
    }

    public boolean contains(Object o) {
        return map.containsKey(o);
    }

    public boolean remove(Object o) {
        return map.removeEntryForKey(o) != null;
    }

    public void clear() {
        map.clear();
    }
}

class Values extends AbstractCollection {

    HashMap map;

    Values(HashMap map) {
        this.map = map;
    }

    public Iterator iterator() {
        return map.newValueIterator();
    }

    public int size() {
        return map.size;
    }

    public boolean contains(Object o) {
        return map.containsValue(o);
    }

    public void clear() {
        map.clear();
    }
}

class EntrySet extends AbstractSet {

    HashMap map;

    EntrySet(HashMap map) {
        this.map = map;
    }

    public Iterator iterator() {
        return map.newEntryIterator();
    }

    public boolean contains(Object o) {
        if (!(o instanceof Entry))
            return false;
        Entry e = (Entry) o;
        Entry candidate = map.getEntry(e.getKey());
        return candidate != null && candidate.equals(e);
    }

    public boolean remove(Object o) {
        return map.removeMapping(o) != null;
    }

    public int size() {
        return map.size;
    }

    public void clear() {
        map.clear();
    }
}