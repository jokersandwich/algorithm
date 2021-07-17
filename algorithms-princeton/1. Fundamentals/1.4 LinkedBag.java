import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedBag<Item> implements Iterable<Item> {
    private Node first;
    private int n;

    private class Node {
        private Item item;
        private Node next;
    }

    // public LinkedBag() {
    //     first = null;
    //     n = 0;
    // }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return n;
    }

    public void add(Item item) {
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        n++;
    }

    // public Iterator<Item> iterator() {
    //     return new LinkedIterator();
    // }

    // private class LinkedIterator implements Iterator<Item> {
    //     private Node current;
    //     public LinkedIterator() {
    //         current = first;
    //     }
    //     public boolean hasNext() {
    //         return current != null;
    //     }
    //     public void remove() {
    //         throw new UnsupportedOperationException();
    //     }
    //     public Item next() {
    //         if (!hasNext()) throw new NoSuchElementException();
    //         Item item = current.item;
    //         current = current.next;
    //         return item;
    //     }
    // }
}