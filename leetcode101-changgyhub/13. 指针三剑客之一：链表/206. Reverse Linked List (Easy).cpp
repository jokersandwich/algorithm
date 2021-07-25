// 递归
ListNode* reverseList(ListNode* head, ListNode* prev=nullptr) {
    if (!head) {
        return prev;
    }
    ListNode* next = head->next;
    head->next = prev;
    return reverseList(next, head);
}

// 非递归
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *next;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// 把下一个节点存起来
// 指向前一个节点
// 挪一格

// javascript
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
// 非递归
// var reverseList = function(head) {
//     let prev = null, curr = head;
//     while (curr) {
//         const next = curr.next;
//         curr.next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// };

// 递归
// var reverseList = function(head) {
//     return _reverseList(head, null)
// };
// var _reverseList = function(head, prev) {
//     if (!head) {
//         return prev;
//     }
//     let next = head.next;
//     head.next = prev;
//     return _reverseList(next, head);
// };