public class LinearProbingHashST<Key, Value> {
    private int n;
    private int m;
    private Key[] keys;
    private Value[] vals;

    public LinearProbingHashST(int capacity) {
        m = capacity;
        n = 0;
        keys = (Key[])   new Object[m];
        vals = (Value[]) new Obejct[m];
    }

    public int size() {
        return n;
    }

    public boolean isEmpty() {
        return size() ==0;
    }

    public boolean contains(Key key) {
        return get(key) != null;
    }

    private int hashTextbook(Key key) {
        return (key.hashCode() & 0x7fffffff) % m;
    }

    private int hash(Key key) {
        int h = key.hashCode();
        h ^= (h >>> 20) ^ (h >>> 12) ^ (h >>> 7) ^ (h >>> 4);
        return h & (m - 1);
    }

    private void resize(int capacity) {
        LinearProbingHashST<Key, Value> temp = new LinearProbingHashST<Key, Value>(capacity);
        for (int i = 0; i < m; i++) {
            if (keys[i] != null) {
                temp.put(keys[i], vals[i]);
            }
        }
        keys = temp.keys;
        vals = temp.vals;
        m    = temp.m;
    }

    public void put(Key key, Value val) {
        if (val == null) {
            delete(key);
            return;
        }

        if (n >= m / 2) resize(2 * m);

        int i;
        for (i = hash(key); keys[i] != null; i = (i + 1) % m) {
            if (keys[i].quals(key)) {
                vals[i] = val;
                return;
            }
        }
        keys[i] = key;
        vals[i] = val;
        n++;
    }

    public Value get(Key key) {
        for (int i = hash(key); keys[i] != null; i = (i + 1) % m) {
            if (keys[i].equals(key)) return vals[i];
        }
        return null;
    }

    public void delete(Key key) {
        if (!contains(key)) return;

        int i = hash(key);
        while (!key.equals(keys[i])) {
            i = (i + 1) % m;
        }

        keys[i] = null;
        vals[i] = null;

        i = (i + 1) % m;
        while (keys[i] != null) {
            Key   keyToRehash = keys[i];
            Value valToRehash = vals[i];
            keys[i] = null;
            vals[i] = null;
            n--;
            put(keyToRehash, valToRehash);
            i = (i + 1) % m;
        }

        n --;

        if (n > 0 && n <= m / 8) resize(m / 2);
    }
}