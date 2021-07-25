ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;
    while (l1 != l2) {
        l1 = l1? l1->next: headB;
        l2 = l2? l2->next: headA;
    }
    return l1;
}

// javascript
/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
// var getIntersectionNode = function(headA, headB) {
//     let arr = [], nodeA = headA, nodeB = headB;
//     while (nodeA !== null) {
//         arr.push(nodeA);
//         nodeA = nodeA.next;
//     }
//     while (nodeB !== null) {
//         if (arr.indexOf(nodeB) !== -1) {
//             return nodeB;
//         }
//         nodeB = nodeB.next;
//     }
//     return null;
// };