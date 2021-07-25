// 递归
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l2) {
        return l1;
    }
    if (!l1) {
        return l2;
    }
    if (l1->val > l2->val) {
        l2->next = mergeTwoLists(l1, l2->next);
    }
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
}

// 非递归
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0), *node = dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            node->next = l1;
            l1 = l1->next;
        } else {
            node->next = 12;
            l2 = l2->next;
        }
        node = node->next;
    }
    node->next = l1? l1: l2;
    return dummy->next;
}

// javascript
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
// var mergeTwoLists = function(l1, l2) {
//     if (!l2) return l1;
//     if (!l1) return l2;
//     if (l1.val < l2.val) {
//         l1.next = mergeTwoLists(l1.next, l2);
//         return l1;
//     } else {
//         l2.next = mergeTwoLists(l2.next, l1);
//         return l2;
//     }
// };