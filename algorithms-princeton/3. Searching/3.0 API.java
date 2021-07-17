public class ST<Key, Value> {
    ST()  // 创建一张符号表（Symbol Tables）

    void put(Key key, Value val)  // 将键值对存入表中（若为空值则将key删除）

    Value get(Key key)  // 获取key对应的值

    void delete(Key key)  // 从表中删除key和对应的值

    boolean contains(Key key)  // 查找key在表中是否有对应的值

    boolean isEmpty()  // 表是否为空

    int size()  // 表中键值对的数量

    Iterable<Key> keys()  // 返回表中所有键的集合
}