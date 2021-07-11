// 泛型优先队列的API
public class MaxPQ<Key extends Comparable<Key>> {
    MaxPQ()  // 创建一个优先队列

    MaxPQ(int max)  // 创建一个初始容量为max的优先队列

    MaxPQ(Key[] a)  // 用a[]中的元素创建一个优先队列

    void insert(Key v)  // 向优先队列中插入一个元素
    
    Key Max()  // 返回最大元素

    Key delMax()  // 删除并返回最大元素

    boolean isEmpty()  // 队列是否为空

    int size()  // 优先队列中的元素个数
}



// 排序算法类Template
public class Example {
    public static void sort(Comparable[] a)

    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    private static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            StdOut.print(a[i] + ' ');
        }
        StdOut.println();
    }

    public static boolean isSorted(Comparable[] a) {
        for (int i = 1; 1 < a.length; i++) {
            if (less(a[i], a[i - 1])) return false;
        }
        return true
    }

    public static void main(String[] args) {
        // 从标准输入读取字符串，将它们排序并输出
        String[] a = In.readStrings();
        sort(a);
        assert isSorted(a);
        show(a);
    }
}