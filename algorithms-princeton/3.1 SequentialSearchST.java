public class SequentialSearchST<Key, Value> {
    private int n;
    private Node first;

    private class Node {
        private Key key;
        private Value val;
        private Node next;
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
        for (Node x = frist; x != null; x = x.next) {
            if (key.equals(x.key)) return x.val;
        }
    }

    public void put (Key key, Value val) {
        if (val == null) {
            delete(key);
            return;
        }
        
        for (Node x = first; x != null; x = x.next) {
            if (key.equals(x.key)) {
                x.val = val;
                return;
            }
        }
        first = new Node(key, val, first);
        n++;
    }

    private Node delete(Key key) {
        first = delete(first, key);
    }
}