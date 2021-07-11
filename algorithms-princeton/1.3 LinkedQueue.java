import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedQueue<Item> implements Iterable<Item> {
    private int n;
    private Node first;
    private Node last;

    private class Node {
        private Item item;
        private Node next;
    }

    public LinkedQueue() {
        first = null;
        last = null;
        n = 0;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return n;
    }

    public Item peek() {
        if (isEmpty()) throw new NoSuchElementException('queue underflow');
        return first.item;
    }

    public void enqueue(Item item) {
        Node oldlast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if (isEmpty()) first = last;
        else oldlast.next = last;
        n++;
    }

    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException('queue underflow');
        Item item = first.item;
        first = first.next;
        n--;
        if (isEmpty()) last = null;
        return item;
    }

    public String toString() {
        StringBuilder s = new StringBuilder();
        for (Item item: this) s.append(item + ' ');
        return s.toString();
    }

    // public Iterator<Item> iterator() {
    //     return new LinkedIterator();
    // }

    // private class LinkedIterator implements Iterator<Item> {
    //     private Node current = first;
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