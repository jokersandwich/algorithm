import java.util.Iterator;
import java.util.NoSuchElementException;

// Q：为什么是新加入的node是first，不是last？

public class LinkedStack<Item> implements Iterable<Item> {
    private int n;
    private Node first;

    private class Node {
        private Item item;
        private Node next;
    }

    public LinkedStack() {
        first = null;
        n = 0;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return n;
    }

    public void push(Item item) {
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        n++;
    }

    public Item pop() {
        Item item = first.item;
        first = first.next;
        n--;
        return item;
    }

    // public Item peek() {
    //     return first.item;
    // }

    // public String toString() {
    //     StringBuilder s = new StringBuilder();
    //     for (Item item: this) s.append(item + ' ');
    //     return s.toString();
    // }

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
    //         if (!hasNext())  throw new NoSuchElementException();
    //         Item item = current.item;
    //         current = current.next;
    //         return item;
    //     }
    // }
}