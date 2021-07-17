// 背包API
public class Bag<Item> implements Iterable<Item> {
    Bag()  // 创建一个空背包

    void add(Item item)  // 添加一个元素

    boolean isEmpty()  // 背包是否为空

    int size()  // 背包中的元素数量
}



// 先进先出（FIFO）队列
public class Queue<Item> implements Iterable<Item> {
    Queue()  // 创建一个空队列

    void enqueue(Item item)  // 添加一个元素

    Item dequeue()  // 删除最早添加的元素

    boolean isEmpty()  // 队列是否为空

    int size()  // 队列中的元素数量
}



// 下压（后进先出，LIFO）栈
public class Stack<Item> implements iterable<Item> {
    Stack()  // 创建一个空栈

    void push(Item item)  // 添加一个元素

    Item pop()  // 删除最近添加的元素

    boolean isEmpty()  // 栈是否为空

    int size()  // 栈中的元素数量
}