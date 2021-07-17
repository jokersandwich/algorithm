public class SeparateChainingHashST<Key, Value> {
    private int n;
    private int m;
    private SequentialSearchST<Key, Value>[] st;

    private void resize(int chains) {
        SeparateChainingHashST<Key, Value> temp = new SeparateChainingHashST<Key, Value>(chains);
        for (int i = 0; i < m; i++) {
            for (Key key : st[i].keys()) {
                temp.put(key, st[i].get(key));
            }
        }
        this.m   = temp.m;
        this.n   = temp.n;
        this. st = temp.st;
    }

    private int hashTextbook(Key key) {
        return (key.hashCode() & 0x7fffffff) % m;
    }

    private int hash(Key key) {
        int h = key.hashCode();
        h ^= (h >>> 20) ^ (h >>> 12) ^ (h >>> 7) ^ (h >>> 4);
        return h & (m - 1);
    }

    public int size() {
        return n;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public boolean contains(Key key) {
        return get(key) != null;
    }

    public Value get(Key key) {
        int i = hash(key);
        return st[i].get(key);
    }

    public void put(Key key, Value val) {
        if (val == null) {
            delete(key);
            return;
        }

        if (n >= 10 * m) resize(2 * m);

        int i = hash(key);
        if (!st[i].contains(key)) n++;
        st[i].put(key, val);
    }

    public void delete(Key key) {
        int i = hash(key);
        if (st[i].contains(key)) n--;
        st[i].delete(key);

        if (m > INIT_CAPACITY && n <= 2 * m) resize(m / 2);
    }
}