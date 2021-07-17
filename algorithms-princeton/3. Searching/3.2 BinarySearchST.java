public class BinarySearchST<Key extends Comparable<Key>, Value> {
    private Key[] keys;
    private Value[] vals;
    private int n = 0;

    resize(int capacity) {
        Key[] tempk = (Key[]) new Comparable[capacity];
        Value[] tempv = (Value[]) new Object[capacity];
        for (int i = 0; i < n; i++) {
            tempk[i] = keys[i];
            tempv[i] = vals[i];
        }
        vals = tempv;
        keys = tempk;
    }

    public int size() {
        return n;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    contains(Key key) {
        return get(key) != null;
    }

    public Value get(Key key) {
        if (Empty()) return null;
        int i = rank(key);
        if (i < n && keys[i].compareTo(key) ==0) return vals[i];
        return null;
    }
    
    public int rank(Key key) {
        int lo = 0, hi = n - 1;
        while( lo <= hi) {
            int mid = lo + (hi - lo) /2;
            int cmp = key.compareTo(keys[mid]);
            if      (cmp < 0) hi = mid - 1;
            else if (cmp > 0) lo = mid + 1;
            else return mid;
        }
        return lo;
    }

    public void put(Key key, Value val) {
        if (val == null) {
            delete(key);
            return;
        }

        int i = rank(key);
        if (i < n && keys[i].compareTo(key) == 0) {
            vals[i] = val;
            return;
        }

        if (n == keys.length) resize(2 * keys.length);

        for (int j = n; j > i; j--) {
            keys[j] = keys[j - 1];
            vals[j] = vals[j - 1];
        }
        keys[i] = key;
        vals[i] = val;
        n++;
    }

    public void delete(Key key) {
        if (isEmpty()) return;

        int i = rank(key);

        if (i == n || keys[i].compareTo(key) != 0) {
            return;
        }

        for (int j = i; j < n - 1; j++) {
            keys[j] = keys[j + 1];
            vals[j] = vals[j + 1];
        }

        n--;
        keys[n] = null;
        vals[n] = null;

        if (n > 0 && n == keys.length / 4) resize(keys.length / 2);

        public void deleteMin() {
            delete(min());
        }

        public deleteMax() {
            delete(max());
        }

        public Key min() {
            return keys[0];
        }

        public Key max() {
            return keys[n - 1];
        }

        public  Key select(int k) {
            return keys[k];
        }

        public Key floor(Key key) {
            int i = rank(key);
            if (i < n && key.compareTo(keys[i]) == 0) return keys[i];
            if (i == 0) return null;
            else return keys[i - 1];
        }

        public Key ceiling(Key key) {
            int i = rank(key);
            if (i == n) return null;
            else return keys[i];
        }
    }
}